/**
   IRQ_ACK_Transmission
   Main program file.
   Created by Arduino IDE
   External files:
   lib-adc-irq.h
   lib-adc-meas.h
   @autor: Khevenin
   @date: 15-12-2019
*/

#include <Arduino.h>
#include <RF24.h>
#include <SPI.h>
#include <nRF24l01.h>
#include <printf.h>

#include "libbuf.h"
#include "lib-adc-irq.h"

#define CE 7
#define CSN 8

#define TX_BUF_SIZE 32          //Size of TX buffer
#define RX_BUF_SIZE 32          //Size of RX buffer
#define ADDRESS_BUF_SIZE 5      //Size of buffer with pipeline address 

const uint8_t addressRX[ADDRESS_BUF_SIZE] = {'P', 'I', 'L', 'O', 'T'};
const uint8_t addressTX[ADDRESS_BUF_SIZE] = {'S', 'L', 'A', 'V', 'E'};

uint8_t bufferTX[TX_BUF_SIZE];
uint8_t bufferRX[RX_BUF_SIZE];

volatile uint8_t  tmp = 0;

RF24 Remote(CE, CSN); //set CE, CSN pins

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init done.");

  /* RF config */
  Serial.println("RF init start.\n");
  Remote.begin();
  Remote.setPALevel(RF24_PA_LOW);   //set Power Amp output power
  Serial.println("Set PA power.");
  Remote.setDataRate(RF24_250KBPS); //set Data Rate of speed tramission
  Serial.println("Set data rate.");
  Remote.setChannel(0x64);          //set Channel
  Serial.println("Set RF channel.");

  Remote.setRetries(4, 3);          //set Retries of package trasmission
  Serial.println("Set retries feature.");
  Remote.setCRCLength(RF24_CRC_8);
  Serial.println("Set CRC.");

  Remote.setAutoAck(1);
  Serial.println("Enable ACK.");
  Remote.enableAckPayload();        //enable transmission ACK signal with Payload
  Serial.println("Enable ACK payload.");
  Serial.println("nRF24 init done.");

  /* Pritn nRF24 settigns */
  //Remote.printDetails();

  /* Open pipeline */
  Remote.openWritingPipe(addressTX);    //enable pipeline to transmit on TX address
  Remote.openReadingPipe(1, addressRX); //enable pipeline to receive from RX address
  Remote.stopListening();
  Serial.println("nRF24 pipeline addresses done.");

  /* Reset MCU TX and RX buffers */
  resetShort(bufferTX, TX_BUF_SIZE);
  resetShort(bufferRX, RX_BUF_SIZE);
  Serial.println("TX and RX buffers reset done.\n");

  /* ADC IRQ init */
  Serial.println("ADC interrupt init start.\n");
  adcIrqSetup(TEMP_SENS_CHANNEL, INTER , DIV_128, FREE_RUN, LEFT_ADJ);
  Serial.println("ADC interrupt init done.\n Conversion started.\n");
}
// writeAckPayload (uint8_t pipe, const void *buf, uint8_t len)
// isAckPayloadAvailable ()

void loop()
{
  delay(1000);
  //  Serial.print("\n Tempatrature measure: ");
  //  Serial.print(tmp);



}


ISR(ADC_vect)
{
  tmp = (readAdcTen() - 313) / 1.22;
  Serial.print("\nADC IRQ handle temperature: ");
  Serial.print(tmp);

}
