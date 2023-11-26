/*
 * Bitwisen.h
 *
 *  Created on: Aug 11, 2023
 *      Author: MOHAMED ZAYED
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// bit operations
#define Clr_Bit(reg,bit_no)                reg&=~(1<<bit_no)
#define Set_Bit(reg,bit_no)                reg|=(1<<bit_no)
#define Read_Bit(reg,bit_no)	           reg>>bit_no & 1
#define Toggle_Bit(reg,bit_no)             reg^=(1<<bit_no)

//shift right and shift left
#define Rotate_Right(reg,no)              reg=(reg<<(8*sizeof(reg)-(no)))|(reg>>(no))
#define Rotate_Left(reg,no)               reg=(reg<<(no))|(reg>>(8*sizeof(reg)-(no)))

#define BIT_IS_SET(reg,bit_no)            if((reg&=(1<<bit_no))==1) return(True);
#define BIT_IS_CLR(reg,bit_no)            if((reg|=~(1<<bit_no))==1) return(False);




#endif /* BIT_MATH_H_ */
