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
#include "libbuf.h"

#define BUF_SIZE 32


void setup()
{
  Serial.begin(115200);
  Serial.println("Serial port init.");


}

void loop()
{
}
