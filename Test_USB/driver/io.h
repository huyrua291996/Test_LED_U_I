/*
 * driver.h
 *
 *  Created on: Mar 9, 2017
 *      Author: Huy
 */

#ifndef DRIVER_IO_H_
#define DRIVER_IO_H_

#include "gpio.h"

#define PORT1         1
#define PORT2         2
#define PORT3         3
#define PORT4         4
#define PORT5         5
#define PORT6         6
#define PORT7         7

#define LOW 0
#define HIGH 1

#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED 1

#define NO_MODE 0
#define MENU 1
#define ENTER 2
#define UP 3
#define DOWN 4

#define buzzleOn P1OUT |= BIT4
#define buzzleOff P1OUT &= ~BIT4
#define contactorOn P5OUT |= BIT5
#define contactorOff P5OUT &= ~BIT5

#define DATA1 1
#define DATA2 2
#define DATA3 3
#define DATA4 4
#define DATA5 5
#define DATA6 6
#define DATA7 7

enum IOState {OFF, ON};
extern enum IOState ledOutState[7], relayOutState[7], relayInState, ledAllState, relayOutAllState;

enum buzzleState { NONE, COMPLETE, ERROR };
extern enum buzzleState gBuzzleState;

extern unsigned int bButtonPressed ;
extern unsigned int bMode;
extern unsigned int dataResult1;
extern unsigned int dataResult2;
extern unsigned int dataResult3;
extern unsigned int dataResult4;
extern unsigned int dataResult5;
extern unsigned int dataResult6;
extern unsigned int dataResult7;


void initButton(void);
void initIO(void);
void ledOutOn(void);
void ledOutOff(void);
void relayOutOff(void);
void ledHandle(void);
void relayHandle(void);
void buzzleHandle(int state);
void buttonPressedHandler(void);
void buttonModeHandler(void);
void initRelayAC(void);
void checkData(void);

#endif /* DRIVER_IO_H_ */
