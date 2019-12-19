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

#define TX_BUF_SIZE 32
#define RX_BUF_SIZE 32



RF24 Remote(CE, CSN); //set CE, CSN pins

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init.");
  Serial.println("RF init start.");
  Remote.begin();
  Remote.setPALevel(RF24_PA_LOW);
  Remote.setDataRate(RF24_250KBPS);
  radio.setChannel(0x64);
  radio.setRetries(4, 3);
  radio.enableAckPayload();


}

void loop()
{
}
