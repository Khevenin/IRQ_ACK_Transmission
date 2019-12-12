#include <stdio.h>

#define TEMP_SENS_CHANNEL 0x08

enum referenceVoltage = {
    AREF, AVCC, RESERVED, INTERNAL};

enum adcPrescalerDiv = {
    DIV_2 = 2,
    DIV_4 = 4,
    DIV_8 = 8,
    DIV_16 = 16,
    DIV_32 = 32,
    DIV_64 = 64,
    DIV_128 = 128};
enum triggerSource = {
    FREE_RUN,
    ANALOG_CMP,
    EXT_IRQ_REQ_0,
    TIM_CMP,
    TIM0_OVERFLOW,
    TIM_CMP_B,
    TIM_OVERFLOW_1,
    TIM_CAP_EVENT_1};

referenceVoltage Vref;
triggerSource Trigg;
adcPrescalerDiv prescalerDiv;

void adcIrqSetup(uint8_t channel);
void setAdcChannel(uint8_t channel);
void setAdcRefVol(referenceVoltage v);

void setAdcPresaler(adcPrescalerDiv div);
void setAutoTriggerSource(triggerSource source);

void setRightAdjust();

void adcEnable();
void adcStarConversion();
void setAutoTrigger();
void setAdcIrqFlag();
void setAdcIrqEnable();

unsigned int readAdc();
unsigned short readAdcAsEight();

ISR(ADC_vect);