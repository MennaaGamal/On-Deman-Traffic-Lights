/*
 * LED.h
 *
 * Created: 10/13/2022 6:52:17 PM
 *  Author: Menna
 */ 

#include "../../MCAL/DIO Driver/DIO.h"

#ifndef LED_H_
#define LED_H_


// Car port and pins
#define LED_CAR_PORT      PORT_A

#define LED_CAR_G_PIN       0

#define LED_CAR_Y_PIN       1

#define LED_CAR_R_PIN       2


// Pedestrian port and pins
#define LED_PED_PORT      PORT_B

#define LED_PED_G_PIN       0

#define LED_PED_Y_PIN       1

#define LED_PED_R_PIN       2


//led initialize
ERROR_STATE LED_init(uint8_t ledPort,uint8_t ledPin);

ERROR_STATE LED_on(uint8_t ledPort,uint8_t ledPin);

ERROR_STATE LED_off(uint8_t ledPort,uint8_t ledPin);

ERROR_STATE LED_toggle(uint8_t ledPort,uint8_t ledPin);



#endif /* LED_H_ */