/**
 * IRQ_ACK_Transmission
 * Main program file.
 * Created by Arduino IDE
 * External files: 
 * lib-adc-irq.h
 * lib-adc-meas.h
 * @autor: Khevenin
 * @date: 15-12-2019
 */

#include <Arduino.h>
#include "libbuf.h"

#define BUF_SIZE 32

uint8_t buffer_1[BUF_SIZE];
uint8_t *pBuf_1 = buffer_1;
uint8_t buffer_2[BUF_SIZE];
uint8_t *pBuf_2 = buffer_2;

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init.");

  for (size_t i = 0; i < BUF_SIZE; i++)
  {
    pBuf_1[i] = i;
    Serial.println("\nBuffer value.");
    Serial.print(pBuf_1[i]);
  }

    resetShort(pBuf_1, BUF_SIZE);
    for (size_t i = 0; i < BUF_SIZE; i++)
    {
      Serial.println("\nbuffer_1 value after reset.");
      Serial.print(pBuf_1[i]);
    }

    resetShort(pBuf_2, BUF_SIZE);
    bufferCopy(pBuf_1, pBuf_2, BUF_SIZE, BUF_SIZE);
}

void loop()
{
}
