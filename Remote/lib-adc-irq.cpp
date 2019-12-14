#include "lib-adc-irq.h"

void adcIrqSetup(uint8_t channel, referenceVoltage v, adcPrescalerDiv div, triggerSource source)
{
    resetRegADMUX;
    resetRegADCSRA;
    resetRegADCSRB; //Zero bits in ADC registers

    /* settigns in ADMUX reg */
    setAdcChannel(channel); //set ADC measure channel
    setAdcRefVol(v);        //set ADC ref. voltage
    setRightAdjust();

    /* settigns in ADCSRA reg */
    setAdcPresaler(div);
    setAdcIrqEnable();
    setAutoTrigger();

    /* settings in ADCSRB reg */
    setAutoTriggerSource(source);

    /* Enable ADC and conversion - set 6 and 7 bit in ADCSRA */
    adcEnable();
    adcStartConversion();
}

/* Function set bits and functionality in ADMUX register */
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

/* Functions to set bit and functionality in ADCSRA register */
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

void adcStartConversion()
{
    ADCSRA = 1 << 6;
}
void adcEnable()
{
    ADCSRA = 1 << 7;
}

/* Functions to set bits in ADCSRB register */
void setAutoTriggerSource(triggerSource source)
{
    ADCSRB = (source & 0x07);
}

/* Reset ADC registers function */
void resetRegADMUX()
{
    ADMUX = 0x00;
}
void resetRegADCSRA()
{
    ADCSRA = 0x00;
}
void resetRegADCSRB()
{
    ADCSRB = 0x00;
}