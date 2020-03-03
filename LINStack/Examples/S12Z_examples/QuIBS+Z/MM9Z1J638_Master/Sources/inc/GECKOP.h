/*
 * GECKOP.h
 *
 *  Created on: Sep 27, 2012
 *      Author: B35993
 */

#ifndef GECKOP_H_
#define GECKOP_H_

#define GECKO_MODE_NORMAL		0
#define GECKO_MODE_STOP			1
#define GECKO_MODE_SLEEP		2
#define GECKO_MODE_CRANK		3


void GECKOP_SetNormalMode();
void GECKOP_SetStopMode();
void GECKOP_SetSleepMode();
unsigned char GECKOP_GetCurrentMode();
unsigned char GECKOP_IsHWRST();
void GECKOP_Reset();

void GECKOP_LoadTrim(char vchain);

void GECKOP_Timer10msInit(void);

#endif /* GECKOP_H_ */
