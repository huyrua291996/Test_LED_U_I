/*
 * system.h
 *
 *  Created on: Mar 10, 2017
 *      Author: Huy
 */

#ifndef HANDLE_SYSTEM_H_
#define HANDLE_SYSTEM_H_

#define START_TIMEOUT 2300
#define BUTTON_TIMEOUT 300
#define VOLTAGE_TIMEOUT 2000
#define CURRENT_TIMEOUT 1000
#define START 0
#define VOLTAGE 1
#define CURRENT 2
#define NOTIFICATION 3

#define VOLT85 0
#define VOLT220 1
#define VOLT265 2

void systemInit(void);

#endif /* HANDLE_SYSTEM_H_ */
