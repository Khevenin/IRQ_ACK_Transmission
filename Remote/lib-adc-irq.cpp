#include "lib-adc-irq.h"

void setAdcChannel(uint8_t channel)
{
    if (((channel < 0x00) && (channel > 0x0F)) || ((channel > 0x08) && (channel < 0x0E))) //if channel number invalid
    {
        ADMUX = TEMP_SENS_CHANNEL; //set default temp measure
    }
    else
    {
        ADMUX = channel;
    }
}

void setAdcRefVol(referenceVoltage v)
{
    if (v == RESERVED) //if reserved value
    {
        ADMUX = AVCC << 6; //set default Avcc as reference voltage
    }
    else
    {
        ADMUX = v << 6;
    }
}