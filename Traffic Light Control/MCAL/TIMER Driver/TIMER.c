/*
 * TIMER.h
 *
 * Created: 10/13/2022 6:33:41 PM
 *  Author: Menna
 */ 


#ifndef TIMER_H_
#define TIMER_H_
 
#include "../../UTILITIES/REG.h"
#include "TIMER.h"

void TIMER_init(){
	
	//normal mode
	TCCR0 = 0x00; 
}
void TIMER_delay(uint16_t millisec){
	uint16_t No_Overflows,Timer_Initial;
	
	double TMax_Delay,T_tick;
	
	uint32_t OF_count=0;
	
	//max delay 256 micro second
	
	T_tick = 256.0/1000.0; //ms    T_tick = Presc/FCPU
	TMax_Delay= T_tick * 256; //ms		Tmaxdelay = T_tick * 2^8
	
	if(millisec<TMax_Delay)
	     {
		Timer_Initial = (TMax_Delay-millisec)/T_tick;
		No_Overflows = 1;
		
		}
	else if(millisec == (int)TMax_Delay)
		{
		Timer_Initial=0;
		No_Overflows=1;
		}
	else
		{
		No_Overflows = ceil((double)millisec/TMax_Delay);
		Timer_Initial = (1<<8) - ((double)millisec/T_tick)/No_Overflows;
		}
		
	TCNT0 = Timer_Initial;
	
	 //set 256 prescaler
	TCCR0 |= (1<<2);
	
	while(OF_count<No_Overflows)
	{
		
		//busy wait
		while(READ_BIT(TIFR,0)==0);
		
		//clear overflow flag
		SET_BIT(TIFR,0);
		
		//increment counter
		OF_count++;
	}
	
	//Timer stop
	TCCR0 = 0x00;
}




#endif /* TIMER_H_ */