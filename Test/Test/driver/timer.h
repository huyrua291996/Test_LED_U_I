/*
 * timer.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */

#ifndef DRIVER_TIMER_H_
#define DRIVER_TIMER_H_

#define TIME_1MS 32

extern int systemTime;
//enum  TimerState { STOPPED, TICKING, RESET };

//extern enum  TimerState gTimerState;
//extern unsigned long int gTimerCount;
extern unsigned int timer, relayFlag, startFlag, voltageFlag, currentFlag;
extern int timerRelay, timerStart, timerVoltage, timerCurrent;
extern unsigned int dataFlag;


//void initTimerStateMachine( void );
//unsigned long int getTimerCount( void );
//void updateTimerStateMachine( void );
void initTimer(void);


#endif /* DRIVER_TIMER_H_ */
