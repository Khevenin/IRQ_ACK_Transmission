/**
 * File with funtions to execute specialized measure tasks.
 * Based on external function from lib-adc-irq.
 * @Khevenin
 * */

#include "lib-adc-irq.h"

#define MEASURE_SIZE 8

extern unsigned short adcTab;
extern unsigned short volatile measureCounter;
extern unsigned short resetCounter;

void adcMeasure(unsigned short volatile *tab, unsigned short volatile *counter);
unsigned short meanVal(unsigned volatile *tab, size_t size);
