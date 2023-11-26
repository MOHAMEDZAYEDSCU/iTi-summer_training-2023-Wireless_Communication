/*
 * DIO.h
 *
 *  Created on: Aug 11, 2023
 *      Author: MOHAMED ZAYED
 */

#ifndef DIO_H_
#define DIO_H_

#define PORTA_REG (*(volatile uint8*)0x3B)
#define PORTB_REG (*(volatile uint8*)0x38)
#define PORTC_REG (*(volatile uint8*)0x35)
#define PORTD_REG (*(volatile uint8*)0x32)

#define DDRA_REG (*(volatile uint8*)0x3A)
#define DDRB_REG (*(volatile uint8*)0x37)
#define DDRC_REG (*(volatile uint8*)0x34)
#define DDRD_REG (*(volatile uint8*)0x31)

#define PINA_REG (*(volatile uint8*)0x39)
#define PINB_REG (*(volatile uint8*)0x36)
#define PINC_REG (*(volatile uint8*)0x33)
#define PIND_REG (*(volatile uint8*)0x30)


#endif /* DIO_H_ */
