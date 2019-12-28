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


RF24 Remote(CE, CSN); //set CE, CSN pins

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init.");
  Serial.println("RF init start.");

  /* RF config */
  Remote.begin();
  Remote.setPALevel(RF24_PA_LOW);   //set Power Amp output power
  Remote.setDataRate(RF24_250KBPS); //set Data Rate of speed tramission
  Remote.setChannel(0x64);          //set Channel

  Remote.setRetries(4, 3);          //set Retries of package trasmission
  Remote.setCRCLength(RF24_CRC_8);

  Remote.setAutoAck(1);
  Remote.enableAckPayload();        //enable transmission ACK signal with Payload

  Remote.printDetails();

  Remote.openWritingPipe(addressTX);    //enable pipeline to transmit on TX address
  Remote.openReadingPipe(1, addressRX); //enable pipeline to receive from RX address
  Remote.stopListening(); 

  resetShort(bufferRX, RX_BUF_SIZE);
}

void loop()
{
}
