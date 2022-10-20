/*
 * APP.h
 *
 * Created: 10/13/2022 7:02:03 PM
 *  Author: Menna
 */ 


#ifndef APP_H_
#define APP_H_

#include "../HAL/LED Driver/LED.h"
#include "../HAL/BUTTON Driver/BUTTON.h"
#include "../MCAL/TIMER Driver/TIMER.h"
#include "../MCAL/EXTERNAL INTERRUPT Driver/INTERRUPT.h"


#define GREEN   0
#define YELLOW  1
#define RED     2


void APP_init(void);
void APP_start(void);





#endif /* APP_H_ */