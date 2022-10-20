/*
 * BUTTON.h
 *
 * Created: 10/13/2022 6:52:53 PM
 *  Author: Menna
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/DIO.h"



//Button port and pin

#define   BUTTON_1_PORT     'D'
#define   BUTTON_1_PIN       2


//initialize
ERROR_STATE BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

// button read
ERROR_STATE BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);




#endif /* BUTTON_H_ */