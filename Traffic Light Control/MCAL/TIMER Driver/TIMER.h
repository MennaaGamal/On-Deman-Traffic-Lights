/*
 * TIMER.h
 *
 * Created: 10/13/2022 6:33:28 PM
 *  Author: Menna
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../UTILITIES/REG.h"

//initialize Timer0
void TIMER_init();

//delay of specific amount default uses PRESCALAR 256
void TIMER_delay(uint16_t millisec); 



#endif /* TIMER_H_ */