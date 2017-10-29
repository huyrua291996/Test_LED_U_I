/*
 * driver.c
 *
 *  Created on: Mar 9, 2017
 *      Author: Huy
 */
#include "io.h"

#include <msp430f5529.h>
#include "gpio.h"
#include "inc/hw_memmap.h"
#include "wdt_a.h"
//#include "gpio.c"
#include "lcd.h"


unsigned int bMode = NO_MODE;
enum IOState ledOutState[7], relayOutState[7], relayInState, ledAllState, relayOutAllState;
enum buzzleState gBuzzleState = NONE;
unsigned int dataAgreeCount1 = 0;
unsigned int dataAgreeCount2 = 0;
unsigned int dataAgreeCount3 = 0;
unsigned int dataAgreeCount4 = 0;
unsigned int dataAgreeCount5 = 0;
unsigned int dataAgreeCount6 = 0;
unsigned int dataAgreeCount7 = 0;
unsigned int dataCount = 300;
unsigned int dataFlag = 0;
unsigned int dataResult1 = 0;
unsigned int dataResult2 = 0;
unsigned int dataResult3 = 0;
unsigned int dataResult4 = 0;
unsigned int dataResult5 = 0;
unsigned int dataResult6 = 0;
unsigned int dataResult7 = 0;

void initButton(void)
{
    P1DIR &= ~BIT5;
    P1REN |= BIT5;
    P1OUT |= BIT5;
}

void initIO(void)
{
    P4DIR |= (BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6);
    P2DIR |= (BIT5+ BIT6 + BIT7);
    P3DIR |= (BIT0 + BIT2 + BIT1 + BIT3);
    P1DIR |= (BIT6 + BIT7);
    P2DIR |= (BIT0 + BIT1 + BIT2 + BIT3 + BIT4);
    P5DIR |= BIT5;
    P1DIR |= BIT4;
    P3DIR &= ~BIT4;
    P3DIR &= ~BIT5;
    P3DIR &= ~BIT6;
    P3DIR &= ~BIT7;
    P1DIR &= ~(BIT0 + BIT1 + BIT2 + BIT3);
    P8DIR &= ~(BIT0 + BIT1 + BIT2);
    P1OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3);
    P8OUT &= ~(BIT0 + BIT1 + BIT2);
    P1REN |= (BIT0 + BIT1 + BIT2 + BIT3);
    P8REN |= (BIT0 + BIT1 + BIT2);
    ledOutState[0] = OFF;
    ledOutState[1] = OFF;
    ledOutState[2] = OFF;
    ledOutState[3] = OFF;
    ledOutState[4] = OFF;
    ledOutState[5] = OFF;
    ledOutState[6] = OFF;
}

void buttonPressedHandler(void)
{
    sendCommand(CURSOR_ON);
    ledOutOff();
    //relayHandle();
    contactorOn;
    //relayOutOff();
    //bButtonPressed = BUTTON_NOT_PRESSED;
}

void ledHandle(void)
{
    if (bButtonPressed == BUTTON_PRESSED)
    {
        	if (ledOutState[0] == ON)
                P1OUT |= BIT6;
            else P1OUT &= ~BIT6;
            if (ledOutState[1] == ON)
                    P1OUT |= BIT7;
                else P1OUT &= ~BIT7;
            if (ledOutState[2] == ON)
                    P2OUT |= BIT0;
                else P2OUT &= ~BIT0;
            if (ledOutState[3] == ON)
                    P2OUT |= BIT1;
                else P2OUT &= ~BIT1;
            if (ledOutState[4] == ON)
                    P2OUT |= BIT2;
                else P2OUT &= ~BIT2;
            if (ledOutState[5] == ON)
                    P2OUT |= BIT3;
                else P2OUT &= ~BIT3;
            if (ledOutState[6] == ON)
                    P2OUT |= BIT4;
                else P2OUT &= ~BIT4;
    }
}

void ledOutOn(void)
{
    P1OUT |= (BIT6 + BIT7);
    P2OUT |= (BIT0 + BIT1 + BIT2 + BIT3 + BIT4);
    //P1OUT &= ~(BIT7 + BIT6);
}

void ledOutOff(void)
{
    P1OUT &= ~(BIT6 + BIT7);
    P2OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4);
}

//void relay
void relayHandle(void)
{
    if (relayOutState[0] == ON)
        P3OUT |= BIT3;
    else P3OUT &= ~BIT3;
    if (relayOutState[1] == ON)
            P3OUT |= BIT2;
        else P3OUT &= ~BIT2;
    if (relayOutState[2] == ON)
            P3OUT |= BIT1;
        else P3OUT &= ~BIT1;
    if (relayOutState[3] == ON)
            P3OUT |= BIT0;
        else P3OUT &= ~BIT0;
    if (relayOutState[4] == ON)
            P2OUT |= BIT7;
        else P2OUT &= ~BIT7;
    if (relayOutState[5] == ON)
            P2OUT |= BIT6;
        else P2OUT &= ~BIT6;
    if (relayOutState[6] == ON)
            P2OUT |= BIT5;
        else P2OUT &= ~BIT5;
    if (relayInState == ON)
        P4OUT |= (BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6);
    else P4OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6);
}

void initRelayAC(void)
{
    P5DIR |= (BIT3 + BIT2);
    P5OUT &= ~(BIT3 + BIT2);
}
void relayOutOff(void)
{
    P2OUT &= ~(BIT5 + BIT6 + BIT7);         // relay out off
    P3OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3);
}

void checkData(void)
{

        if (dataFlag == 1)
                    {
                        if ((P8IN & 0x01) == 0x01)
                            dataAgreeCount1 += 1;
                        if ((P8IN & 0x02) == 0x02)
                            dataAgreeCount2 += 1;
                        if ((P8IN & 0x04) == 0x04)
                            dataAgreeCount3 += 1;
                        if ((P1IN & 0x01) == 0x01)
                            dataAgreeCount4 += 1;
                        if ((P1IN & 0x02) == 0x02)
                            dataAgreeCount5 += 1;
                        if ((P1IN & 0x04) == 0x04)
                            dataAgreeCount6 += 1;
                        if ((P1IN & 0x08) == 0x08)
                            dataAgreeCount7 += 1;
                                //timer = 0;
                        dataCount -= 1;
                        if (dataCount == 0)
                        {
                            dataCount = 300;
                            if (dataAgreeCount1 >= 220)
                            {
                                dataResult1 = 1;
                            }
                            else
                            {
                                 dataResult1 = 2;
                            }
                            if (dataAgreeCount2 >= 220)
                            {
                                 dataResult2 = 1;
                            }
                            else
                            {
                                 dataResult2 = 2;
                            }
                            if (dataAgreeCount3 >= 220)
                            {
                                 dataResult3 = 1;
                            }
                            else
                            {
                                 dataResult3 = 2;
                            }
                            if (dataAgreeCount4 >= 220)
                            {
                                 dataResult4 = 1;
                            }
                            else
                            {
                                 dataResult4 = 2;
                            }
                            if (dataAgreeCount5 >= 220)
                            {
                                 dataResult5 = 1;
                            }
                            else
                            {
                                 dataResult5 = 2;
                            }
                            if (dataAgreeCount6 >= 220)
                            {
                                 dataResult6 = 1;
                            }
                            else
                            {
                                 dataResult6 = 2;
                            }
                            if (dataAgreeCount7 >= 220)
                            {
                                 dataResult7 = 1;
                            }
                            else
                            {
                                 dataResult7 = 2;
                            }
                        }
                    }
        dataFlag = 0;
}

void buzzleHandle(int bstate)
{
    int bcount = 0;
    switch (bstate)
    {
    case COMPLETE:
        for (bcount = 0; bcount < 3; bcount ++)
        {
            buzzleOn;
            delay(20);
            buzzleOff;
        }
        gBuzzleState = NONE;
        break;
    case ERROR:
        buzzleOn;
        delay(20);
        buzzleOff;
        break;
    }
}
void buttonModeHandler(void)
{
    if ((P3IN & 0x80) == 0x80)
    {
        bMode = MENU;
    }
    if ((P3IN & 0x40) == 0x40)
    {
        bMode = ENTER;
    }
    if ((P3IN & 0x20) == 0x20)
    {
        bMode = UP;
    }
    if ((P3IN & 0x10) == 0x10)
    {
        bMode = DOWN;
    }
}

/*#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port_1(void)
#else
#error Compiler not supported!
#endif
{
    bButtonPressed = BUTTON_PRESSED;
    P1IFG &= ~BIT5;
}*/
