/**
 * File with funtions to execute specialized measure tasks.
 * Based on external function from lib-adc-irq.
 * @Khevenin
 * */
#include <Arduino.h>
#include "lib-adc-irq.h"

extern unsigned short volatile measureCounter;
extern unsigned short resetCounter;

void adcMeasure(unsigned short volatile *tab, unsigned short volatile *counter);
unsigned short meanVal(unsigned volatile *tab, size_t size);
