/*
 * system.c
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */
#include "system.h"

#include "adc.h"
#include "io.h"
#include "lcd.h"
#include "timer.h"
#include "calc.h"

void systemInit(void)
{
    initButton();
    initIO();
    ledOutOn();
    initADC();
    initLCD();
    initTimer();
    initRelayAC();
    contactorOff;
}
