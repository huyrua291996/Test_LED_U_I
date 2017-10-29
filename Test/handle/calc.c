/*
 * calc.c
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */
#include "calc.h"

#include <msp430f5529.h>
#include "gpio.h"
#include "adc.h"
#include "io.h"
#include "lcd.h"

//int val, tram, chuc, dv = 0;
//unsigned int errorCount = 0;
enum LCDState voltage[7], current[7];

void voltageCheck(void)
{
                    if ((Ares1 <= 4095)/*&&(Ares1 >= 3660)/*&&(dataResult1== 1)*/)
                    {
                        relayOutState[0] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult1 == 0)
                    {
                        P4OUT &= ~BIT0;
                        data[0] = SEND;
                    }*/
                    else
                    {
                                                P4OUT &= ~BIT0;
                                                voltage[0] = SEND;
                                                /*val = Ares1 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares3 <= 4095)/*&&(Ares3 >= 3660)/*&&(dataResult2== 1)*/)
                    {
                        relayOutState[1] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult2 == 0)
                                        {
                                            P4OUT &= ~BIT1;
                                            data[1] = SEND;
                                        }*/
                    else
                    {
                                                P4OUT &= ~BIT1;
                                                voltage[1] = SEND;
                                                /*val = Ares3 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares5 <= 4095)/*&&(Ares5 >= 3660)/*&&(dataResult3== 1)*/)
                    {
                        relayOutState[2] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult3 == 0)
                                        {
                                            P4OUT &= ~BIT2;
                                            data[2] = SEND;
                                        }*/
                    else
                    {
                                                P4OUT &= ~BIT2;
                                                voltage[2] = SEND;
                                               /* val = Ares5 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares7 <= 4095)/*&&(Ares7 >= 3660)/*&&(dataResult4== 1)*/)
                    {
                        relayOutState[3] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult4 == 0)
                                        {
                                            P4OUT &= ~BIT3;
                                            data[3] = SEND;
                                        }*/
                    else
                    {
                                                P4OUT &= ~BIT3;
                                                voltage[3] = SEND;
                                                /*val = Ares7 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares9 <= 4095)/*&&(Ares9 >= 3660)/*&&(dataResult7== 1)*/)
                    {

                        relayOutState[6] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult7 == 0)
                                        {
                                            P4OUT &= ~BIT6;
                                            data[6] = SEND;
                                        }*/
                    else
                    {
                                                P4OUT &= ~BIT6;
                                                voltage[6] = SEND;
                                                /*val = Ares9 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares11 <= 4095)/*&&(Ares11 >= 3660)/*&&(dataResult5== 1)*/)
                    {
                        relayOutState[4] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult5 == 0)
                                        {
                                            P4OUT &= ~BIT4;
                                            data[4] = SEND;
                                        }*/
                    else
                    {
                                                P4OUT &= ~BIT4;
                                                voltage[4] = SEND;
                                                /*val = Ares11 * 100;
                                                tram = (int) (val / 100);
                                                chuc = (int) ((val - tram * 100) / 10);
                                                dv = (int) (val % 100);
                                                sendData(tram + 48);
                                                sendData(chuc + 48);
                                                sendData(dv + 48);*/
                    }
                    if ((Ares13 <= 4095)/*&&(Ares13 >= 3660)/*&&(dataResult6== 1)*/)
                    {
                        relayOutState[5] = ON;
                        errorCount += 1;
                    }
                    /*else if (dataResult6 == 0)
                                        {
                                            P4OUT &= ~BIT5;
                                            data[5] = SEND;
                                        }*/
                    else
                        {
                            P4OUT &= ~BIT5;
                            voltage[5] = SEND;
                           /* val = Ares13 * 100;
                            tram = (int) (val / 100);
                            chuc = (int) ((val - tram * 100) / 10);
                            dv = (int) (val % 100);
                            sendData(tram + 48);
                            sendData(chuc + 48);
                            sendData(dv + 48);*/
                        }
}

void currentCheck(void)
{
                    if ((RELAYOUT_VALUE1 & RELAY1) == RELAY1)
                    {
                        if ((Ares1 <= 4095)/*&&(Ares1 >= 3660) */&& (Ares0 >= 1215) && (Ares0 <= 1395))

                            ledOutState[6] = ON;

                        /*else if ((Ares1 > 4095)/*|(Ares1 < 3660))
                        {
                            P4OUT &= ~BIT0;
                                                    voltage[0] = SEND;
                                                    ledOutState[6] = OFF;
                                                    /*val = Ares0 * 100;
                                                    tram = (int) (val / 100);
                                                    chuc = (int) ((val - tram * 100) / 10);
                                                    dv = (int) (val % 100);
                                                    sendData(tram + 48);
                                                    sendData(chuc + 48);
                                                    sendData(dv + 48);
                         }*/
                        else
                        {
                            P4OUT &= ~BIT0;
                            current[0] = SEND;
                            ledOutState[6] = OFF;
                        }
                    }
                    if ((RELAYOUT_VALUE1 & RELAY2) == RELAY2)
                    {
                        if ((Ares3 <= 4095)/*&&(Ares3 >= 3660) */&& (Ares2 >= 1204) && (Ares2 <= 1384))

                            ledOutState[5] = ON;
                        /*else if ((Ares3 > 4095)/*|(Ares3 < 3660))
                            {
                            P4OUT &= ~BIT1;
                            voltage[1] = SEND;
                            ledOutState[5] = OFF;
                            }*/
                        else
                        {
                            P4OUT &= ~BIT1;
                            ledOutState[5] = OFF;
                                                    current[1] = SEND;
                                                    /*val = Ares2 * 100;
                                                    tram = (int) (val / 100);
                                                    chuc = (int) ((val - tram * 100) / 10);
                                                    dv = (int) (val % 100);
                                                    sendData(tram + 48);
                                                    sendData(chuc + 48);
                                                    sendData(dv + 48);*/
                        }
                    }
                    if ((RELAYOUT_VALUE1 & RELAY3) == RELAY3)
                    {
                        if ((Ares5 <= 4095)/*&&(Ares5 >= 3660) */&& (Ares4 >= 1208) && (Ares4 <= 1388))

                            ledOutState[4] = ON;
                       /* else if ((Ares5 > 4095)/*|(Ares5 < 3660))
                            {
                            P4OUT &= ~BIT2;
                            voltage[2] = SEND;
                            ledOutState[4] = OFF;
                            }*/
                        else
                        {
                            P4OUT &= ~BIT2;
                            ledOutState[4] = OFF;
                                                    current[2] = SEND;
                                                    /*val = Ares4 * 100;
                                                    tram = (int) (val / 100);
                                                    chuc = (int) ((val - tram * 100) / 10);
                                                    dv = (int) (val % 100);
                                                    sendData(tram + 48);
                                                    sendData(chuc + 48);
                                                    sendData(dv + 48);*/
                        }
                    }
                    if ((RELAYOUT_VALUE1 & RELAY4) == RELAY4)
                    {
                         if ((Ares7 <= 4095)/*&&(Ares7 >= 3660) */&& (Ares6 >= 1150) && (Ares6 <= 1330))

                             ledOutState[3] = ON;
                        /* else if ((Ares7 > 4095)/*|(Ares7 < 3660))
                             {
                             P4OUT &= ~BIT3;
                             voltage[3] = SEND;
                             ledOutState[3] = OFF;
                             }*/
                         else
                         {
                             P4OUT &= ~BIT3;
                             ledOutState[3] = OFF;
                                                     current[3] = SEND;
                                                    /* val = Ares6 * 100;
                                                     tram = (int) (val / 100);
                                                     chuc = (int) ((val - tram * 100) / 10);
                                                     dv = (int) (val % 100);
                                                     sendData(tram + 48);
                                                     sendData(chuc + 48);
                                                     sendData(dv + 48);*/
                          }
                    }
                   if ((RELAYOUT_VALUE2 & RELAY7) == RELAY7)
                    {
                         if ((Ares9 <= 4095)/*&&(Ares9 >= 3660) */&& (Ares8 >= 1199) && (Ares8 <= 1380))

                             ledOutState[0] = ON;
                         /*else if ((Ares9 > 4095)/*|(Ares9 < 3660))
                         {
                             P4OUT &= ~BIT6;
                             voltage[4] = SEND;
                             ledOutState[0] = OFF;
                         }*/
                         else
                         {
                             P4OUT &= ~BIT6;
                             ledOutState[0] = OFF;
                             current[4] = SEND;
                                                    /* val = Ares8 * 100;
                                                     tram = (int) (val / 100);
                                                     chuc = (int) ((val - tram * 100) / 10);
                                                     dv = (int) (val % 100);
                                                     sendData(tram + 48);
                                                     sendData(chuc + 48);
                                                     sendData(dv + 48);*/
                          }
                    }
                    if ((RELAYOUT_VALUE2 & RELAY5) == RELAY5)
                    {
                         if ((Ares11 <= 4095)/*&&(Ares11 >= 3660) */&& (Ares10 >= 1152) && (Ares10 <= 1332))

                             ledOutState[2] = ON;
                         /*else if ((Ares11 > 4095)/*|(Ares11 < 3660))
                         {
                             ledOutState[2] = OFF;
                             P4OUT &= ~BIT4;
                             voltage[5] = SEND;
                         }*/
                         else
                         {
                             P4OUT &= ~BIT4;
                             ledOutState[2] = OFF;
                             current[5] = SEND;
                                                     /*val = Ares10 * 100;
                                                     tram = (int) (val / 100);
                                                     chuc = (int) ((val - tram * 100) / 10);
                                                     dv = (int) (val % 100);
                                                     sendData(tram + 48);
                                                     sendData(chuc + 48);
                                                     sendData(dv + 48);*/
                         }
                    }
                    if ((RELAYOUT_VALUE2 & RELAY6) == RELAY6)
                    {
                         if ((Ares13 <= 4095)/*&&(Ares13 >= 3660) */&& (Ares12 >= 1157) && (Ares12 <= 1337))

                             ledOutState[1] = ON;
                         /*else if ((Ares13 > 4095))
                         {
                             P4OUT &= ~BIT5;
                             ledOutState[1] = OFF;
                             voltage[6] = SEND;
                         }*/
                         else
                         {
                             P4OUT &= ~BIT5;
                             ledOutState[1] = OFF;
                                                     current[6] = SEND;
                                                     /*val = Ares12 * 100;
                                                     tram = (int) (val / 100);
                                                     chuc = (int) ((val - tram * 100) / 10);
                                                     dv = (int) (val % 100);
                                                     sendData(tram + 48);
                                                     sendData(chuc + 48);
                                                     sendData(dv + 48);*/
                         }
                    }
                    /*dong tu 0.5-2 1167-1290
                     ap tu 4.8 den 5.2
                     */
}
void resetVol(void)
{
    Ares1 = 0;
    Ares3 = 0;
    Ares5 = 0;
    Ares7 = 0;
    Ares9 = 0;
    Ares11 = 0;
    Ares13 = 0;
}

void resetCurrent(void)
{
    Ares0 = 0;
    Ares2 = 0;
    Ares4 = 0;
    Ares6 = 0;
    Ares8 = 0;
    Ares10 = 0;
    Ares12 = 0;

}
