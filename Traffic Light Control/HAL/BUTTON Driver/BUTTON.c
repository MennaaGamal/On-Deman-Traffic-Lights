/*
 * BUTTON.h
 *
 * Created: 10/13/2022 6:53:12 PM
 *  Author: Menna
 */ 


#include "BUTTON.h"

//initialize
ERROR_STATE BUTTON_init(uint8_t buttonPort, uint8_t buttonPin)
{
	if (DIO_init(buttonPort,buttonPin,INPUT))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


// button read
ERROR_STATE BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value)
{
	if (READ_BIT(PIND,2))
	{
	while(READ_BIT(PIND,2))
	{
		++*value;
	}
	return TRUE;
	}
	
	else
	{
		return FALSE;
	}
	
	
}



