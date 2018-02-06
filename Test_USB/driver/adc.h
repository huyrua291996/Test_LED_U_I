/*
 * adc.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */

#ifndef DRIVER_ADC_H_
#define DRIVER_ADC_H_

#include <msp430f5529.h>
#include "gpio.h"
#include "hw_memmap.h"
#include "adc12_a.h"
#include "io.h"

#define ENABLE_AD_IN1 P6SEL |= 0xFF
#define ENABLE_AD_IN2 P7SEL |= 0x0F
#define ENABLE_AD_IN3 P5SEL |= 0x03
#define VECTOR_15 ADC12IE15
#define TAKE_SAMPLE_TIMES 256
#define CALCNONSTART 0
#define CALCSTART 1

extern long int Ares0 ;
extern long int Ares1 ;
extern long int Ares2 ;
extern long int Ares3 ;
extern long int Ares4 ;
extern long int Ares5 ;
extern long int Ares6 ;
extern long int Ares7 ;
extern long int Ares8 ;
extern long int Ares9 ;
extern long int Ares10 ;
extern long int Ares11 ;
extern long int Ares12 ;
extern long int Ares13 ;
extern unsigned int startCalc;

void enableAdInput(void);
void configRef(void);
void configADCClock(void);
void configADCMode(void);
void configInputChannel(void);
void selectInterruptVect(uint16_t vector);
void initADC(void);
void startADC(void);
void stopADC(void);


#endif /* DRIVER_ADC_H_ */
