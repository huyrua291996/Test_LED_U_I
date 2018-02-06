/*
 * lcd.c
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */
#include "lcd.h"

#include <msp430f5529.h>
#include "gpio.h"
#include "hw_memmap.h"

unsigned int count1, count2;
enum LCDState voltage[7], current[7], data[7];

void delay(unsigned int time)
{
    for (count1 = 0; count1 <= time; count1 ++)
    {
        for (count2 = 0; count2 <= COUNT_TARGET; count2 ++);
    }
}

void dataWrite(void)
{
    ENABLE_HIGH;
    delay(2);
    ENABLE_LOW;
}

void dataRead(void)
{
    ENABLE_LOW;
    delay(2);
    ENABLE_HIGH;
}

void sendCommand(unsigned char cmd)
{
    CWR;
    LCD_VALUE = ((LCD_VALUE & HIGH_NIBBLE)|((cmd >> NUMBER_OF_BITS) & LOW_NIBBLE)) << NUMBER_OF_BITS;
    dataWrite();
    LCD_VALUE = ((LCD_VALUE & HIGH_NIBBLE)|(cmd & LOW_NIBBLE)) << NUMBER_OF_BITS;
    dataWrite();
}

void sendData(unsigned char data)
{
    DR;
    LCD_VALUE = ((LCD_VALUE & HIGH_NIBBLE)|((data >> NUMBER_OF_BITS) & LOW_NIBBLE)) << NUMBER_OF_BITS;
    dataWrite();
    LCD_VALUE = ((LCD_VALUE & HIGH_NIBBLE)|(data & LOW_NIBBLE)) << NUMBER_OF_BITS;
    dataWrite();
}

void sendString(char *str)
{
    while(*str)
    {
        sendData(*str);
        str ++;
    }
}

void initLCD(void)
{
    int index = 0;
    EN_INIT;
    ENABLE_LOW;
    RW_INIT;
    RW_LOW;
    RS_INIT;
    CWR;
    LCD_PORTINIT;
    LCD_LOW;
    sendCommand(INIT_COMMAND1);
    sendCommand(INIT_COMMAND2);
    sendCommand(BIT_4_MODE);
    sendCommand(CLEAR_SCREEN);
    sendCommand(CURSOR_ON);
    sendCommand(CURSOR_INCREMENT);
    sendCommand(ROW_1_COL_1);
    for (index = 0; index < 7; index ++)
        {
            voltage[index] = NOT_SEND;
            current[index] = NOT_SEND;
        }
}

void lcdHandle(void)
{
    int index = 0;
    for (index = 0; index < 7; index ++)
    {
        if (voltage[index] == SEND)
        {
            sendData(index + 1 + 48);
            //sendString("u");
        }
        if (data[index] == SEND)
        {
            sendData(index + 1 +65);
        }
    }
        sendCommand(NEW_LINE);
    for (index = 0; index < 7; index ++)
    {
        if (current[index] == SEND)
        {
            sendData(index +7 + 1 + 48);
            //sendString("i");
        }
    }
    /*for (index = 0; index < 7; index ++)
    {
        voltage[index] = NOT_SEND;
        current[index] = NOT_SEND;
    }*/
}

void lcdVoltageReset(void)
{
    int index = 0;
    for (index = 0; index < 7; index ++)
        {
            voltage[index] = NOT_SEND;
            //current[index] = NOT_SEND;
            data[index] = NOT_SEND;
        }
}

void lcdCurrentReset(void)
{
    int index = 0;
    for (index = 0; index < 7; index ++)
        {
            //voltage[index] = NOT_SEND;
            current[index] = NOT_SEND;
        }
}
