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

void setRightAdjust()
{
    ADMUX = 0 << 4;
}

void setAdcPresaler(adcPrescalerDiv div)
{
    ADCSRA = (div & 0x07);
}

void setAdcIrqEnable()
{
    ADCSRA = 1 << 3;
}

void setAdcIrqFlag()
{
    ADCSRA = 1 << 4;
}

void setAutoTrigger()
{
    ADCSRA = 1 << 5;
}

void adcStarConversion()
{
    ADCSRA = 1 << 6;
}
void adcEnable()
{
    ADCSRA = 1 << 7;
}

void setAutoTriggerSource(triggerSource source)
{
    ADCSRB = (source & 0x07);
}
