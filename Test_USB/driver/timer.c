/*
 * timer.c
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */
#include "timer.h"
#include <msp430f5529.h>
#include "hw_memmap.h"

int systemTime = 0;
//enum  TimerState gTimerState;
//unsigned long int gTimerCount;
unsigned int timer = 0;



/*void initTimerStateMachine( void )
{
  gTimerState = STOPPED;
  gTimerCount = 0;
}

unsigned long int getTimerCount( void )
{
  return( gTimerCount );
}

void updateTimerStateMachine( void )
{
  switch( gTimerState )
  {
    case STOPPED:
      break;

    case TICKING:
      gTimerCount++;  // Increment the count
      break;

    case RESET:
      gTimerCount = 0;
      gTimerState = STOPPED;
      break;

    default:
      break;
  }
}*/

void initTimer(void)
{
    TA0CCTL0 = CCIE;
    TA0CCR0 = TIME_1MS;
    TA0CTL = TASSEL_1 + MC_1 + TACLR;
    __enable_interrupt();
    __bis_SR_register(GIE);       // Enter LPM0, enable interrupts

}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = TIMER0_A0_VECTOR
__interrupt
void TIMER0_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
    systemTime += 1;
    timer = 1;
    if (startFlag == 1) timerStart ++;
    if (voltageFlag == 1) timerVoltage ++;
    if (currentFlag == 1) timerCurrent ++;
    //if (notiFlag == 1) timerNoti ++;
    if (relayFlag == 1) timerRelay ++;
    dataFlag = 1;
}
