/*
 * calc.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */

#ifndef HANDLE_CALC_H_
#define HANDLE_CALC_H_

#include <msp430f5529.h>
#include "adc.h"
#include "io.h"
#include "gpio.h"

#define COMPARE_VALUE 2
#define RELAYOUT_VALUE1 P3OUT
#define RELAYOUT_VALUE2 P2OUT
#define RELAY1 0x08
#define RELAY2 0x04
#define RELAY3 0x02
#define RELAY4 0x01
#define RELAY5 0x80
#define RELAY6 0x40
#define RELAY7 0x20

extern unsigned int errorCount;

void voltageCheck(void);
void currentCheck(void);
void resetVol(void);
void resetCurrent(void);

#endif /* HANDLE_CALC_H_ */
