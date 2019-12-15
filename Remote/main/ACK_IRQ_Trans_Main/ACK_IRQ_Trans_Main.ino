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

#include "C:\Users\Khevenin\Documents\nRF24L0\IRQ_ACK_Transmission\IRQ_ACK_Transmission\Remote/libbuf.h"

#define BUF_SIZE 32

uint8_t buffer[BUF_SIZE];
uint8_t buffer_2[BUF_SIZE];

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init.");

  for (size_t i = 0; i < BUF_SIZE; i++)
  {
    buffer[i] = i;
    Serial.println("\nBuffer value.");
    Serial.print(buffer[i]);
  }

  resetShort(buffer, BUF_SIZE);
  for (size_t i = 0; i < BUF_SIZE; i++)
  {
    Serial.println("\nBuffer value after reset.");
    Serial.print(buffer[i]);
  }

  resetShort(buffer_2, BUF_SIZE);
  bufferCopy(buffer, buffer_2, BUF_SIZE, BUF_SIZE);
}

void loop()
{
}
