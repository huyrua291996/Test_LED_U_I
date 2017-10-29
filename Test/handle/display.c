/*
 * display.c
 *
 *  Created on: Mar 24, 2017
 *      Author: Huy
 */

#include "display.h"
#include "io.h"
#include "lcd.h"

void menuDisplay(void)
{
    switch (bMode)
    {
    case MENU:
        sendCommand(CLEAR_SCREEN);
        sendString("Welcome");
        break;
    }
}


