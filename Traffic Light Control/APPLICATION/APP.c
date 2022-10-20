/*
 * APP.c
 *
 * Created: 10/13/2022 7:02:17 PM
 *  Author: Menna
 */ 
#include "APP.h"

uint8_t CAR_STATE = GREEN; //0 green 1 yellow 2 red
uint8_t Prev_carLED = 1;
uint8_t normalmode = 1; //1 normal 0 pedestrian
uint8_t Press=0;  //counter for pressing time

void APP_init(void){
	
	//Car LED initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//Pedestrian LED initialization
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	//Button initialization
	BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN);
	
	//Timer initialization
	TIMER_init();
	
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}
void APP_start(void){
	//variable to be used in for loop
	uint8_t i;
	
	//if normal mode or need transition (i.e. car green led or yellow is on)
	if(normalmode || CAR_STATE==0 || CAR_STATE==1){
		if(!normalmode){
			CAR_STATE=1;
		}
		//Configuring Pedestrian LEDs
		LED_off(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		//LED_off(LED_PED_PORT,LED_PED_R_PIN);
		
		switch(CAR_STATE){
			//Case GREEN LED
			case 0:
			LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_R_PIN);

			
			for(i=0;i<50;i++){
				TIMER_delay(68);
				if(!normalmode)break;//check if ISR was called
			}
			CAR_STATE=1;
			Prev_carLED=0;
			break;
			//Case YELLOW LED
			case 1:
			//if not normalmode then we need to blink both
			
			if(!normalmode){
				if(Prev_carLED!=2){
					LED_off(LED_PED_PORT,LED_PED_G_PIN);
				    LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				    LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
					LED_off(LED_PED_PORT,LED_PED_R_PIN);
					//blink both yellow leds
					for(i=0;i<5;i++){
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						LED_on(LED_PED_PORT,LED_PED_Y_PIN);
						TIMER_delay(390);
						LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
						LED_off(LED_PED_PORT,LED_PED_Y_PIN);
						TIMER_delay(190);
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						LED_on(LED_PED_PORT,LED_PED_Y_PIN);
						TIMER_delay(390);
					}
				}
				Prev_carLED=1;//to go to Ped lights logic
				CAR_STATE=2;
				
				
				}else{
				
	                LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
					LED_off(LED_PED_PORT,LED_PED_G_PIN);
					LED_off(LED_PED_PORT,LED_PED_R_PIN);
					LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
				//blink car yellow led
				for(i=0;i<5;i++){

					LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
					TIMER_delay(380);
					LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
					TIMER_delay(180);
					LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
					TIMER_delay(380);
					if(!normalmode){//check if ISR was called
						Prev_carLED=1;
						break;
					}
				}
			}
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			//Configure variables for correct switching
			if(Prev_carLED==0){
				CAR_STATE=2;
				Prev_carLED=1;
				}else if(Prev_carLED==2){
				CAR_STATE=0;
				Prev_carLED=1;
			}
			break;
			//Case RED LED
			case 2:
			LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
			for(i=0;i<50;i++){
				TIMER_delay(68);
				if(!normalmode)break;
			}
			Prev_carLED=2;
			CAR_STATE=1;
			break;
			default:
			CAR_STATE=2;
			Prev_carLED=1;
			break;
		}
		
		}else{
		//Configure PED LEDs
		LED_on(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_R_PIN);
		
		//Configure CAR LEDs
		LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
		TIMER_delay(5000);//5 sec delay
		
		//make sure car red light is off
		LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
		
		//blink both yellow after ped green 
		LED_off(LED_PED_PORT,LED_PED_G_PIN); 
		for(i=0;i<5;i++){
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
			LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_off(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(190);
			LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
			LED_on(LED_PED_PORT,LED_PED_Y_PIN);
			TIMER_delay(390);
		}
		//Turn off yellow LEDs
		LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		//turn on PED red LED
		LED_on(LED_PED_PORT,LED_PED_R_PIN);
		//reset normalmode
		normalmode=1;
		//Configure carLED variables
		CAR_STATE=0;
		Prev_carLED=1;
	}
	
}

ISR(EXT_INT_0){
	
	BUTTON_read(BUTTON_1_PORT,BUTTON_1_PIN,&Press);
	
	if (Press>=50)
	{
	   normalmode=1;
	   Press=0;
	}
	else if (Press<50)
	{
		 normalmode=0;
		 Press=0;
	}
}