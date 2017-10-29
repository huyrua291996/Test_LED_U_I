#include <msp430f5529.h>
#include "gpio.h"
#include "adc.h"
#include "io.h"
#include "lcd.h"
#include "timer.h"
#include "calc.h"
#include "system.h"
/*
 * main.c
 */

//int now = 0;
//int timeCheck = 0;
unsigned int state = START;
unsigned int voltState = VOLT220;
unsigned int errorCount = 0;
int buttonCount = 600;
int buttonPressCount = 0;
unsigned int startFlag = 0;
unsigned int voltageFlag = 0;
unsigned int currentFlag = 0;
unsigned int relayFlag = 0;
int timerStart = 0;
int timerVoltage = 0;
int timerCurrent = 0;
int timerRelay = 0;
unsigned int bButtonPressed = BUTTON_NOT_PRESSED;

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    systemInit();
    //initTimerStateMachine();
    bButtonPressed = BUTTON_NOT_PRESSED;
    while(1)
    {

        //updateTimerStateMachine();
        switch (state)
        {
        case START:
            if (timer == 1)
            {
                if ((P1IN & BIT5) == 0x0000)
                    buttonPressCount += 1;
                //timer = 0;
                buttonCount -= 1;
                if (buttonCount == 0)
                {
                    buttonCount = 600;
                    if (buttonPressCount >= 550)
                        bButtonPressed = BUTTON_PRESSED;
                    buttonPressCount = 0;
                    timer = 0;
                }

            }

                        if (bButtonPressed == BUTTON_PRESSED)
                        {

                            startFlag = 1;
                            relayFlag = 1;
                            buttonPressedHandler();
                            relayInState = ON;
                            switch (voltState)
                                    {
                                    /*case VOLT85:
                                        P5OUT |= BIT2;
                                        P5OUT &= ~BIT3;
                                        break;*/
                                    case VOLT220:
                                        P5OUT &= ~BIT2;
                                        P5OUT &= ~BIT3;
                                        relayInState = ON;
                                        break;
                                    case VOLT265:
                                        P5OUT &= ~BIT2;
                                        P5OUT |= BIT3;
                                        break;
                                    }
                            //gTimerState = TICKING;
                            if (timerRelay >= BUTTON_TIMEOUT)
                                {
                                    relayFlag = 0;
                                    relayHandle();
                                    //timerRelay = 0;
                                }
                            //else relayInState = OFF;

                            if (timerStart >= 1300) checkData();
                            if (timerStart >= START_TIMEOUT)
                            {
                            startADC();
                            startCalc = CALCSTART;
                            state = VOLTAGE;
                            startFlag = 0;
                            timerStart = 0;
                            timerRelay = 0;
                            }
                            else state = START;
                        }
                        break;
         case VOLTAGE:

             if (startCalc == CALCNONSTART)
             {
                 //gTimerState = TICKING;
                 voltageFlag = 1;
                 voltageCheck();
                 resetVol();
                 resetCurrent();

                 if ((errorCount != 0) && (timerVoltage >= VOLTAGE_TIMEOUT))
                     {
                         state = CURRENT;
                         lcdHandle();
                         startCalc = CALCSTART;
                         errorCount = 0;
                         voltageFlag = 0;
                         timerVoltage = 0;
                         relayHandle();
                     }
                 else if ((errorCount == 0) && (timerVoltage >= VOLTAGE_TIMEOUT))
                     {
                         state = NOTIFICATION;
                         lcdHandle();
                         startCalc = CALCNONSTART;
                         errorCount = 0;
                         voltageFlag = 0;
                         timerVoltage = 0;
                         relayHandle();
                     }
                 else
                     {
                         state = VOLTAGE;
                         lcdVoltageReset();
                         //voltageFlag = 0;
                     }
             }
             break;
         case CURRENT:
             if (startCalc == CALCNONSTART)
             {
                 //sendCommand(NEW_LINE);
                 //gTimerState = TICKING;
                 currentFlag = 1;
                 currentCheck();

                 if (timerCurrent >= CURRENT_TIMEOUT)
                 {
                     state = NOTIFICATION;
                     startCalc = CALCNONSTART;
                     currentFlag = 0;
                     timerCurrent = 0;
                     resetCurrent();
                     resetVol();
                 }
                 else
                     {
                         state = CURRENT;
                         lcdCurrentReset();
                         //currentFlag = 0;
                     }
             }
             break;
         case NOTIFICATION:
             gBuzzleState = COMPLETE;
             //gTimerState = RESET;
             stopADC();
             state = START;
             //relayOutOff();

             buzzleHandle(gBuzzleState);
             dataResult1 = 0;
             dataResult2 = 0;
             dataResult3 = 0;
             dataResult4 = 0;
             dataResult5 = 0;
             dataResult6 = 0;
             dataResult7 = 0;

             relayOutState[0] = OFF;
             relayOutState[1] = OFF;
             relayOutState[2] = OFF;
             relayOutState[3] = OFF;
             relayOutState[4] = OFF;
             relayOutState[5] = OFF;
             relayOutState[6] = OFF;

             if (voltState == 2) {voltState = 1;
             contactorOff;

             lcdHandle();
             ledHandle();bButtonPressed = BUTTON_NOT_PRESSED;
             relayInState = OFF;
             ledOutState[0] = OFF;
             ledOutState[1] = OFF;
             ledOutState[2] = OFF;
             ledOutState[3] = OFF;
             ledOutState[4] = OFF;
             ledOutState[5] = OFF;
             ledOutState[6] = OFF;}
             else voltState += 1;
             break;
        }

    }
    //return 0;
}
