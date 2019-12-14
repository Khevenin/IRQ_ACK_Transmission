/**
 * File with funtions to execute specialized measure tasks.
 * Based on external function from lib-adc-irq.
 * @Khevenin
 * */

#include "lib-adc-meas.h"

unsigned short volatile adcTab[MEASURE_SIZE];
unsigned short volatile measureCounter = 0;
unsigned short resetCounter = 0x08;

void adcMeasure(unsigned short volatile *tab, unsigned short volatile *counter)
{
    tab[*counter] = readAdcEight();
    *counter++;
    *counter = *counter & resetCounter; //reste measureCounter value using bitwise AND
}

unsigned short meanVal(unsigned volatile *tab, size_t size)
{

    if (size)
    {
        unsigned float tmp = 0;

        size_t i;
        for (i = 0; i < size; i++)
        {
            tmp += tab[i];
        }

        tmp = tmp / size;
        return short(tmp);
    }
    else
    {
        return 0;
    }
}

ISR(ADC_vect)
{
}