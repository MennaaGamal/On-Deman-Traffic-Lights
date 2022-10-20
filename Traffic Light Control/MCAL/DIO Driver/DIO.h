/*
 * DIO.h
 *
 * Created: 10/11/2022 2:44:12 PM
 *  Author: Menna
 */ 

#include "../../UTILITIES/REG.h"



#ifndef DIO_H_
#define DIO_H_


//ALL MACROS

#define PORT_A   'A'
#define PORT_B   'B'
#define PORT_C   'C'
#define PORT_D   'D'

//Direction defines
#define INPUT     0
#define OUTPUT    1

//Value Defines
#define HIGH    1
#define LOW     0

//Error States
typedef enum ERROR_STATE 
{
	FALSE , TRUE 
	
}ERROR_STATE;



// ALL FUNCTIONS PROTOTYPES

ERROR_STATE DIO_init    (uint8_t PortNum , uint8_t PinNum , uint8_t Direction); // initialize DIO direction

ERROR_STATE DIO_write   (uint8_t PortNum , uint8_t PinNum , uint8_t Value);     // write data to DIO

ERROR_STATE DIO_toggle  (uint8_t PortNum , uint8_t PinNum );                    //Toggle DIO

ERROR_STATE DIO_read    (uint8_t PortNum , uint8_t PinNum , uint8_t *Value);    // read DIO






#endif /* DIO_H_ */