#include "leds.h"

sbit R_led  = P0^5;
sbit G_led  = P0^4;

void RED_ledStatus(unsigned char status)
{
		if(status == LED_ON)
		{
			R_led = LED_ON;
		}
		else
		{
			R_led = LED_OFF;
		}
}

void GREEN_ledStatus(unsigned char status)
{
	if(status == LED_ON)
		{
			G_led = LED_ON;
		}
		else
		{
			G_led = LED_OFF;
		}
}