/*
 * ADC.h
 *
 *  Created on: Aug 11, 2023
 *      Author: MOHAMED ZAYED
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD_Types.h"

#define ADCHL (*(volatile uint16*)0x24)


#define ADMUX (*(volatile uint8*)0x27)

#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define ADLAR 5
#define REFS0 6
#define REFS1 7



#define ADCSRA (*(volatile uint8*)0x26)

#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7


#define DDRA_REG (*(volatile uint8*)0x3A)

#endif
