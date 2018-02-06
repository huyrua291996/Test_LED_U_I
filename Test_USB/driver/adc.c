/*
 * adc.c
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */
#include "adc.h"

#include <msp430f5529.h>
#include "gpio.h"
#include "hw_memmap.h"
#include "adc12_a.h"

#include "io.h"

volatile unsigned int A0results[TAKE_SAMPLE_TIMES];
volatile unsigned int A1results[TAKE_SAMPLE_TIMES];
volatile unsigned int A2results[TAKE_SAMPLE_TIMES];
volatile unsigned int A3results[TAKE_SAMPLE_TIMES];
volatile unsigned int A4results[TAKE_SAMPLE_TIMES];
volatile unsigned int A5results[TAKE_SAMPLE_TIMES];
volatile unsigned int A6results[TAKE_SAMPLE_TIMES];
volatile unsigned int A7results[TAKE_SAMPLE_TIMES];
volatile unsigned int A8results[TAKE_SAMPLE_TIMES];
volatile unsigned int A9results[TAKE_SAMPLE_TIMES];
volatile unsigned int A10results[TAKE_SAMPLE_TIMES];
volatile unsigned int A11results[TAKE_SAMPLE_TIMES];
volatile unsigned int A12results[TAKE_SAMPLE_TIMES];
volatile unsigned int A13results[TAKE_SAMPLE_TIMES];

long int Ares0 = 0;
long int Ares1 = 0;
long int Ares2 = 0;
long int Ares3 = 0;
long int Ares4 = 0;
long int Ares5 = 0;
long int Ares6 = 0;
long int Ares7 = 0;
long int Ares8 = 0;
long int Ares9 = 0;
long int Ares10 = 0;
long int Ares11 = 0;
long int Ares12 = 0;
long int Ares13 = 0;
unsigned int startCalc = CALCNONSTART;

void enableAdInput(void)
{
    ENABLE_AD_IN1;
    ENABLE_AD_IN2;
    ENABLE_AD_IN3;
}

void configRef(void)
{
    REFCTL0 |= REFVSEL_2 + REFON;
    ADC12CTL0 |= ADC12REFON + ADC12REF2_5V;
}
void configADCClock(void)
{
    ADC12CTL0 |= ADC12SHT0_8;
}
void configADCMode(void)
{
    ADC12CTL0 |= ADC12MSC;
    ADC12CTL1 |= ADC12SHP + ADC12CONSEQ_3;
}
void configInputChannel(void)
{
    ADC12MCTL0 = ADC12SREF_1 + ADC12INCH_0;
    ADC12MCTL1 = ADC12SREF_1 + ADC12INCH_1;
    ADC12MCTL2 = ADC12SREF_1 + ADC12INCH_2;
    ADC12MCTL3 = ADC12SREF_1 + ADC12INCH_3;
    ADC12MCTL4 = ADC12SREF_1 + ADC12INCH_4;
    ADC12MCTL5 = ADC12SREF_1 + ADC12INCH_5;
    ADC12MCTL6 = ADC12SREF_1 + ADC12INCH_6;
    ADC12MCTL7 = ADC12SREF_1 + ADC12INCH_7;
    ADC12MCTL8 = ADC12SREF_1 + ADC12INCH_8;
    ADC12MCTL9 = ADC12SREF_1 + ADC12INCH_9;
    ADC12MCTL12 = ADC12SREF_1 + ADC12INCH_12;
    ADC12MCTL13 = ADC12SREF_1 + ADC12INCH_13;
    ADC12MCTL14 = ADC12SREF_1 + ADC12INCH_14;
    ADC12MCTL15 = ADC12SREF_1 + ADC12INCH_15 + ADC12EOS;
}
void selectInterruptVect(uint16_t vector)
{
    ADC12IE = vector;
}
void initADC(void)
{
    enableAdInput();
    ADC12CTL0 = ADC12ON;
    configADCClock();
    configRef();
    configADCMode();
    configInputChannel();
    selectInterruptVect(VECTOR_15);
    /*P6SEL |= 0xFF;                             // Enable A/D channel inputs
    P7SEL |= 0x0F;
    P5SEL |= 0x03;
         //P6SEL |= (BIT0 + BIT1);
    REFCTL0 |= REFVSEL_2 + REFON;
    ADC12CTL0 = ADC12ON+ADC12MSC+ADC12SHT0_8+ADC12REFON+ADC12REF2_5V; // Turn on ADC12, extend sampling time
                                                     // to avoid overflow of results + V ref = 2.5V
    ADC12CTL1 = ADC12SHP+ADC12CONSEQ_3;       // Use sampling timer, repeated sequence
    ADC12MCTL0 = ADC12SREF_1 + ADC12INCH_0;                 // ref+=AVcc = 2.5V, channel = A0
    ADC12MCTL1 = ADC12SREF_1 + ADC12INCH_1;                 // ref+=AVcc, channel = A1
    ADC12MCTL2 = ADC12SREF_1 + ADC12INCH_2;                 // ref+=AVcc, channel = A2
    ADC12MCTL3 = ADC12SREF_1 + ADC12INCH_3;        // ref+=AVcc, channel = A3, end seq.
    ADC12MCTL4 = ADC12SREF_1 + ADC12INCH_4;
    ADC12MCTL5 = ADC12SREF_1 + ADC12INCH_5;
    ADC12MCTL6 = ADC12SREF_1 + ADC12INCH_6;
    ADC12MCTL7 = ADC12SREF_1 + ADC12INCH_7;
    ADC12MCTL8 = ADC12SREF_1 + ADC12INCH_8;
    ADC12MCTL9 = ADC12SREF_1 + ADC12INCH_9;
    ADC12MCTL12 = ADC12SREF_1 + ADC12INCH_12;
    ADC12MCTL13 = ADC12SREF_1 + ADC12INCH_13;
    ADC12MCTL14 = ADC12SREF_1 + ADC12INCH_14;
    ADC12MCTL15 = ADC12SREF_1 + ADC12INCH_15 + ADC12EOS;
    ADC12IE = ADC12IE15;                           // Enable ADC12IFG.15*/
}

void startADC(void)
{
    ADC12CTL0 |= ADC12ENC;
    ADC12CTL0 |= ADC12SC;
    //startCalcstartCalc = CALCNONSTART;
    __enable_interrupt();
}

void stopADC(void)
{
    ADC12CTL0 &= ~(ADC12ENC + ADC12SC);
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12ISR (void)
#else
#error Compiler not supported!
#endif
{
    //ngat = 2;
    static unsigned int index = 0;
    switch(__even_in_range(ADC12IV,36))
      {
      case  0: break;                           // Vector  0:  No interrupt
      case  2: break;                           // Vector  2:  ADC overflow
      case  4: break;                           // Vector  4:  ADC timing overflow
      case  6: break;                           // Vector  6:  ADC12IFG0
      case  8: break;                           // Vector  8:  ADC12IFG1
      case 10: break;                           // Vector 10:  ADC12IFG2
      case 12: break;                           // Vector 12:  ADC12IFG3
      case 14: break;                           // Vector 14:  ADC12IFG4
      case 16: break;                           // Vector 16:  ADC12IFG5
      case 18: break;                           // Vector 18:  ADC12IFG6
      case 20: break;                           // Vector 20:  ADC12IFG7
      case 22: break;                           // Vector 22:  ADC12IFG8
      case 24: break;                           // Vector 24:  ADC12IFG9
      case 26: break;                           // Vector 26:  ADC12IFG10
      case 28: break;                           // Vector 28:  ADC12IFG11
      case 30: break;                           // Vector 30:  ADC12IFG12
      case 32: break;                           // Vector 32:  ADC12IFG13
      case 34: break;                           // Vector 34:  ADC12IFG14
      case 36:
          A0results[index] = ADC12MEM0;
          A1results[index] = ADC12MEM1;
          A2results[index] = ADC12MEM2;
          A3results[index] = ADC12MEM3;
          A4results[index] = ADC12MEM4;
          A5results[index] = ADC12MEM5;
          A6results[index] = ADC12MEM6;
          A7results[index] = ADC12MEM7;
          A8results[index] = ADC12MEM8;
          A9results[index] = ADC12MEM9;
          A10results[index] = ADC12MEM12;
          A11results[index] = ADC12MEM13;
          A12results[index] = ADC12MEM14;
          A13results[index] = ADC12MEM15;
          if (startCalc == CALCSTART)
          {
              Ares0 += A0results[index];
              Ares1 += A1results[index];
              Ares2 += A2results[index];
              Ares3 += A3results[index];
              Ares4 += A4results[index];
              Ares5 += A5results[index];
              Ares6 += A6results[index];
              Ares7 += A7results[index];
              Ares8 += A8results[index];
              Ares9 += A9results[index];
              Ares10 += A10results[index];
              Ares11 += A11results[index];
              Ares12 += A12results[index];
              Ares13 += A13results[index];
              index++;
          }

                                         // Increment results index, modulo; Set Breakpoint1 here
          if (index == TAKE_SAMPLE_TIMES)
          {
                      Ares0 = Ares0 >>= 8;
                      Ares1 = Ares1 >>= 8;
                      Ares2 = Ares2 >>= 8;
                      Ares3 = Ares3 >>= 8;
                      Ares4 = Ares4 >>= 8;
                      Ares5 = Ares5 >>= 8;
                      Ares6 = Ares6 >>= 8;
                      Ares7 = Ares7 >>= 8;
                      Ares8 = Ares8 >>= 8;
                      Ares9 = Ares9 >>= 8;
                      Ares10 = Ares10 >>= 8;
                      Ares11 = Ares11 >>= 8;
                      Ares12 = Ares12 >>= 8;
                      Ares13 = Ares13 >>= 8;
                      /*Ares0 = (int) Ares0 / 4095 * 2.5;
                      Ares1 = (int) Ares1 / 4095 * 2.5;
                      Ares2 = (int) Ares2 / 4095 * 2.5;
                      Ares3 = (int) Ares3 / 4095 * 2.5;
                      Ares4 = (int) Ares4 / 4095 * 2.5;
                      Ares5 = (int) Ares5 / 4095 * 2.5;
                      Ares6 = (int) Ares6 / 4095 * 2.5;
                      Ares7 = (int) Ares7 / 4095 * 2.5;
                      Ares8 = (int) Ares8 / 4095 * 2.5;
                      Ares9 = (int) Ares9 / 4095 * 2.5;
                      Ares10 = (int) Ares10 / 4095 * 2.5;
                      Ares11 = (int) Ares11 / 4095 * 2.5;
                      Ares12 = (int) Ares12 / 4095 * 2.5;
                      Ares13 = (int) Ares13 / 4095 * 2.5;*/
                      startCalc = CALCNONSTART;
                      index = 0;
                      //ADC12CTL0 &= ~(ADC12ENC + ADC12SC);
          }
          break;
      default: break;
      }
}
