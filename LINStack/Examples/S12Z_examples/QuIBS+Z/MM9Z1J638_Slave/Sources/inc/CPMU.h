/*
 * CPMU.h
 *
 *  Created on: Sep 19, 2012
 *      Author: B35993
 */

#ifndef CPMU_H_
#define CPMU_H_

#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char CPMU_IsPLLlocked();
void CPMU_InitBusCLK();
void CPMU_InitD2DCLK(unsigned char);

#endif /* CPMU_H_ */
