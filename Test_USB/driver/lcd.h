/*
 * lcd.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */

#ifndef DRIVER_LCD_H_
#define DRIVER_LCD_H_

#include <msp430f5529.h>
#include "io.h"
#include "gpio.h"
#include "hw_memmap.h"

#define DR P4OUT |= BIT7
#define CWR P4OUT &= ~BIT7
#define ENABLE_HIGH P5OUT |=  BIT7
#define ENABLE_LOW P5OUT &= ~BIT7
#define RS_INIT P4DIR |= BIT7
#define LCD_PORTINIT P7DIR |= 0xF0
#define LCD_LOW P7OUT |= 0x00
#define EN_INIT P5DIR |= BIT7
#define RW_INIT P5DIR |= BIT6
#define RW_LOW P5OUT &= ~BIT6

#define LCD_VALUE P7OUT
#define NUMBER_OF_BITS 4
#define HIGH_NIBBLE 0xF0
#define LOW_NIBBLE 0x0F
#define COUNT_TARGET 100
#define INIT_COMMAND1 0x33
#define INIT_COMMAND2 0x32
#define BIT_4_MODE 0x28
#define CLEAR_SCREEN 0x0E
#define CURSOR_ON 0x01
#define CURSOR_INCREMENT 0x06
#define ROW_1_COL_1 0x80
#define NEW_LINE 0xC0

enum LCDState { NOT_SEND, SEND };
extern enum LCDState voltage[7], current[7], data[7];

void delay(unsigned int time);
void dataWrite(void);
void dataRead(void);
void sendCommand(unsigned char cmd);
void sendData(unsigned char data);
void sendString(char *str);
void initLCD(void);
void lcdHandle(void);
void lcdVoltageReset(void);
void lcdCurrentReset(void);

#endif /* DRIVER_LCD_H_ */
