/*
 * DIO_Driver.h
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Abdelrazik
 */

#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

/**************** Include Part Start ************************/

// This part could be removed if proper .h files were included.
// Bitwise.h and std_types.h
#define Clr_Bit(reg,bit_no)             reg&=~(1<<bit_no)
#define Set_Bit(reg,bit_no)             reg|=(1<<bit_no)
#define Read_Bit(reg,bit_no)	      	reg>>bit_no & 1

typedef unsigned char 		uint8;

/**************** Include Part End ************************/

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

enum PORTS {PORTA, PORTB, PORTC, PORTD};

enum PINS {
		PORTA0, PORTA1, PORTA2, PORTA3, PORTA4, PORTA5, PORTA6, PORTA7,
		PORTB0, PORTB1, PORTB2, PORTB3, PORTB4, PORTB5, PORTB6, PORTB7,
		PORTC0, PORTC1, PORTC2, PORTC3, PORTC4, PORTC5, PORTC6, PORTC7,
		PORTD0, PORTD1, PORTD2, PORTD3, PORTD4, PORTD5, PORTD6, PORTD7,
};

void DIO_init(uint8 PORTNAME, uint8 PORTVALUE);					// Will initialize DDRD
void DIO_WriteChannel(uint8 PIN, uint8 BIT);
uint8 DIO_ReadChannel(uint8 PIN);

#endif /* DIO_DRIVER_H_ */
