/*
 * DIO.c
 *
 * Created: 10/11/2022 2:44:24 PM
 *  Author: Menna
 */ 

#include "DIO.h"


ERROR_STATE DIO_init    (uint8_t PortNum , uint8_t PinNum , uint8_t Direction) // initialize DIO direction
{
	switch (PortNum) 
	{
		case PORT_A :
		  if (Direction == INPUT)
		  {
			  CLR_BIT (DDRA,PinNum);
			  return TRUE;
		  }
		  else if (Direction == OUTPUT)
		  {
			  SET_BIT(DDRA,PinNum);
			  return TRUE;
		  }
		  else
		  {
			  return FALSE;
		  }
		  
		  
		case PORT_B :
		  if (Direction == INPUT)
		  {
			  CLR_BIT (DDRB,PinNum);
			  return TRUE;

		  }
		  else if (Direction == OUTPUT)
		  {
			  SET_BIT(DDRB,PinNum);
		      return TRUE;

		  }
		 else
		 {
			 return FALSE;
		 }
		  
		  
		case PORT_C :
		  if (Direction == INPUT)
		  {
			  CLR_BIT (DDRC,PinNum);
			  return TRUE;
		  }
		  else if (Direction == OUTPUT)
		  {
			  SET_BIT(DDRC,PinNum);
			  return TRUE;
		  }
		  else
		  {
			  return FALSE;
		  }
		  
		  
		case PORT_D :
		  if (Direction == INPUT)
		  {
			  CLR_BIT (DDRD,PinNum);
			  return TRUE;
		  }
		  else if (Direction == OUTPUT)
		  {
			  SET_BIT(DDRD,PinNum);
			  return TRUE;
		  }
		  else
		  {
			  return FALSE;
		  }
		  
		
		default:
		  return FALSE;  
	}
	
}
ERROR_STATE DIO_write   (uint8_t PortNum , uint8_t PinNum , uint8_t Value)     // write data to DIO
{
    switch (PortNum)
    {
	  case PORT_A :
	    if (Value == LOW)
	    {
		    CLR_BIT (PORTA,PinNum);
			return TRUE;
	    }
	    else if (Value == HIGH)
	    {
		    SET_BIT(PORTA,PinNum);
			return TRUE;
	    }
		else
		{
			return FALSE;
		}
	   
	    
	  case PORT_B :
	    if (Value == LOW)
	    {
		    CLR_BIT (PORTB,PinNum);
			return TRUE;
	    }
	    else if (Value == HIGH)
	    {
		    SET_BIT(PORTB,PinNum);
			return TRUE;
	    }
		else
		{
			return FALSE;
		}
	    
	    
	  case PORT_C :
	    if (Value == LOW)
	    {
		    CLR_BIT (PORTC,PinNum);
			return TRUE;
	    }
	    else if (Value == HIGH)
	    {
		    SET_BIT(PORTC,PinNum);
			return TRUE;
	    }
	    else
	    {
		    return FALSE;
	    }
		
	    
	  case PORT_D :
	    if (Value == LOW)
	    {
		    CLR_BIT (PORTD,PinNum);
			return TRUE;
	    }
	    else if (Value == HIGH)
	    {
		    SET_BIT(PORTD,PinNum);
			return TRUE;
	    }
	    else
	    {
		    return FALSE;
	    }
		
		
	  default :
		return FALSE;
}
}
ERROR_STATE DIO_toggle  (uint8_t PortNum , uint8_t PinNum )                     //Toggle DIO
{
	switch (PortNum)
	{
		case PORT_A :
		   TOGGLE_BIT(PORTA , PinNum);
		   return TRUE;
		
		case PORT_B :
		   TOGGLE_BIT(PORTB , PinNum);
		   return TRUE;
		   
		case PORT_C :
		   TOGGLE_BIT(PORTC , PinNum);
		   return TRUE;
		   
		case PORT_D :
		   TOGGLE_BIT(PORTD , PinNum);  
		   return TRUE;      
		   
		default:
		   return FALSE;    
	}
}

ERROR_STATE DIO_read    (uint8_t PortNum , uint8_t PinNum , uint8_t *Value)     // read DIO
{
	switch (PortNum)
	{
		case PORT_A :
		   *Value= READ_BIT (PINA , PinNum);
		   return TRUE;
		
		case PORT_B :
		   *Value= READ_BIT (PINB , PinNum);
		   return TRUE;
		
		case PORT_C :
		   *Value= READ_BIT (PINC ,PinNum);
		   return TRUE;
		
		case PORT_D :
		   *Value= READ_BIT (PIND ,PinNum);
		   return TRUE;
		   
		default:
		  return FALSE;   
		   
	}
}