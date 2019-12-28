#include "lib-adc-irq.h"

referenceVoltage Vref;
triggerSource Trigg;
adcPrescalerDiv prescalerDiv;

//ISR(ADC_vect)
//{
//  //Place for User ADC read code
//  //Remember it's interrupt, so this code must be short and fast
//  //Slower operation put in main loop of program
//}

/* Read 8bits output of converion from ADCL and  ADCH */
unsigned short readAdcEight()
{
  if (ADMUX & 0x20) //If Adjust to left is on -  ADLAR = 1
  {
    unsigned short tmp = ADCH;
    return tmp;
  }
  else //If Adjust to right is on - ADLAR = 0
  {
    unsigned int tmp = ADCL;                 //Read low value
    tmp = ADCH << 8;                         //Read high value
    unsigned short result = short(tmp >> 2); //Cut off two LSB
    return result;
  }
}

/* Read full - 10bit - of output ADC conversion from ADCL and ADCH */
unsigned int readAdcTen()
{
  if (ADMUX & 0x20) //If Adjust to left is on -  ADLAR = 1
  {
    unsigned int tmp = ADCW;  // ADCL; //Read low bits
    //    tmp = ADCH << 8;    //Read high bits
    return (tmp >> 6);        //Return with removal of ADLAR = 1
  }
  else //If Adjust to right is on - ADLAR = 0
  {
    unsigned int tmp = ADCW; // ADCL; //Read low value
    // tmp = ADCH << 8;         //Read high value
    return tmp;
  }
}

/* ADC conversion with interrupt init */
void adcIrqSetup(uint8_t channel, referenceVoltage v, adcPrescalerDiv div, triggerSource source, adjustSelection adjust)
{
  Serial.print("\n ADC irq init. ");
  resetRegADMUX;
  resetRegADCSRA;
  resetRegADCSRB; //Zero bits in ADC registers
  Serial.print("\n ADC regiters reset. ");

  Serial.print("\n ADMUX register: "); Serial.print(ADMUX, BIN);
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);
  Serial.print("\n ADCSRB resgister: "); Serial.print(ADCSRB, BIN);

  /* settigns in ADMUX reg */
  Serial.print("\n Set ADC channel." );
  setAdcChannel(channel); //set ADC measure channel
  Serial.print("\n ADMUX register: "); Serial.print(ADMUX, BIN);
  Serial.print("\n Set reference voltage.");
  setAdcRefVol(v);        //set ADC ref. voltage
  Serial.print("\n ADMUX register: "); Serial.print(ADMUX, BIN);
  Serial.print("\n Set measure result adjust.");
  if (adjust)
  {
    setLefAdjust();
  }
  else
  {
    setRightAdjust();
  }
  Serial.print("\n ADMUX register: "); Serial.print(ADMUX, BIN);

  /* settigns in ADCSRA reg */
  Serial.print("\n\n Set prescaler value.");
  setAdcPresaler(div);
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);
  Serial.print("\n IRQ enable.");
  setAdcIrqEnable();
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);
  Serial.print("\n Set auto - trigger.");
  setAutoTrigger();
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);

  /* settings in ADCSRB reg */
  Serial.print("\n\n Set trigger source.");
  setAutoTriggerSource(source);
  Serial.print("\n ADCSRB resgister: "); Serial.print(ADCSRB, BIN);

  /* Enable ADC and conversion - set 6 and 7 bit in ADCSRA */
  Serial.print("\n ADC enable.");
  adcEnable();
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);
  Serial.print("\n Enable conversion. ");
  adcStartConversion();
  Serial.print("\n ADCSRA register: "); Serial.print(ADCSRA, BIN);
}

/* Function set bits and functionality in ADMUX register */
void setAdcChannel(uint8_t channel)
{
  if (((channel < 0x00) && (channel > 0x0F)) || ((channel > 0x08) && (channel < 0x0E))) //if channel number invalid
  {
    ADMUX |= TEMP_SENS_CHANNEL; //set default temp measure
  }
  else
  {
    ADMUX |= channel;
  }
}

void setAdcRefVol(referenceVoltage v)
{
  if (v == RESERVED) //if reserved value
  {
    ADMUX |= AVCC << 6; //set default Avcc as reference voltage
  }
  else
  {
    ADMUX |= v << 6;
  }
}
void setLefAdjust()
{
  ADMUX |= 1 << 5;
}

void setRightAdjust()
{
  ADMUX |= 0 << 5;
}

/* Functions to set bit and functionality in ADCSRA register */
void setAdcPresaler(adcPrescalerDiv div)
{
  ADCSRA |= (div & 0x07);
}

void setAdcIrqEnable()
{
  ADCSRA |= 1 << 3;
}

void setAdcIrqFlag()
{
  ADCSRA |= 1 << 4;
}

void setAutoTrigger()
{
  ADCSRA |= 1 << 5;
}

void adcStartConversion()
{
  ADCSRA |= 1 << 6;
}
void adcEnable()
{
  ADCSRA |= 1 << 7;
}

/* Functions to set bits in ADCSRB register */
void setAutoTriggerSource(triggerSource source)
{
  ADCSRB |= (source & 0x07);
}

/* Reset ADC registers function */
void resetRegADMUX()
{
  ADMUX &= 0x00;
}
void resetRegADCSRA()
{
  ADCSRA &= 0x00;
}
void resetRegADCSRB()
{
  ADCSRB &= 0x00;
}
