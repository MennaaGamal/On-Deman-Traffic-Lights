/*
 * LED.h
 *
 * Created: 10/13/2022 6:52:28 PM
 *  Author: Menna
 */ 


#include "LED.h"


ERROR_STATE LED_init(uint8_t ledPort,uint8_t ledPin)
{
	if (DIO_init(ledPort,ledPin,OUTPUT))
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
	
}


ERROR_STATE LED_on(uint8_t ledPort,uint8_t ledPin)
{
	
	if (DIO_write(ledPort,ledPin,HIGH))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


ERROR_STATE LED_off(uint8_t ledPort,uint8_t ledPin)
{
	if (DIO_write(ledPort,ledPin,LOW))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


ERROR_STATE LED_toggle(uint8_t ledPort,uint8_t ledPin)
{
	;
	if (DIO_toggle(ledPort,ledPin))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


