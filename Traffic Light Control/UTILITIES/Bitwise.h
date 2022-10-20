/*
 * Bitwise.h
 *
 * Created: 10/11/2022 3:09:37 PM
 *  Author: Menna
 */ 

#ifndef BITWISE_H_
#define BITWISE_H_


#define SET_BIT( REG , BIT_NO)       (REG|=(1<<BIT_NO))

#define CLR_BIT( REG , BIT_NO)       (REG &= ~(1<<BIT_NO))

#define TOGGLE_BIT( REG , BIT_NO)    (REG ^= (1<<BIT_NO))

#define READ_BIT( REG , BIT_NO)    ((REG & (1<<BIT_NO))>>BIT_NO)



 




#endif /* BITWISE_H_ */