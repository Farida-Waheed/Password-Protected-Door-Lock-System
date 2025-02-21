#include "leds.h"

void WHITE_ledStatus(unsigned char status)
{
		if(status == LED_ON)
		{
			W_led = LED_ON;
		}
		else
		{
			W_led = LED_OFF;
		}
}

void BLUE_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			B_led = LED_ON;
		}
		else
		{
			B_led = LED_OFF;
		}
}

void YELLOW_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			Y_led = LED_ON;
		}
		else
		{
			Y_led = LED_OFF;
		}
}

void ORANGE_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			O_led = LED_ON;
		}
		else
		{
			O_led = LED_OFF;
		}
}


