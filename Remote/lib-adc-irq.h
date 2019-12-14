/**
 *  Library to set ADC conversin while interrupt.
 *  For Atmega 328 -  Arduino Uno rev3 microcontroller.
 *  @Autor: Khevenin
 * */

#include <stdio.h>

#define TEMP_SENS_CHANNEL 0x08

enum referenceVoltage = {
    AREF, AVCC, RESERVED, INTERNAL};

enum adcPrescalerDiv = {
    DIV_2 = 0x01,
    DIV_4 = 0x02,
    DIV_8 = 0x03,
    DIV_16 = 0x04,
    DIV_32 = 0x05,
    DIV_64 = 0x06,
    DIV_128 = 0x07};
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

void adcIrqSetup(uint8_t channel, referenceVoltage v, adcPrescalerDiv div, triggerSource source, uint8_t adjust);

void setAdcChannel(uint8_t channel);
void setLefAdjust();
void setRightAdjust();
void setAdcRefVol(referenceVoltage v);

void setAdcPresaler(adcPrescalerDiv div);
void setAdcIrqEnable();
void setAdcIrqFlag();
void setAutoTrigger();
void adcStartConversion();
void adcEnable();

void setAutoTriggerSource(triggerSource source);

void resetRegADMUX();
void resetRegADCSRA();
void resetRegADCSRB();

unsigned int readAdcTen();
unsigned short readAdcEight();

ISR(ADC_vect);