#ifndef __LEDS_H__
#define __LEDS_H__

#include <reg51.h>
#define LED_ON          0
#define LED_OFF         1

void RED_ledStatus(unsigned char status);

void GREEN_ledStatus(unsigned char status);

#endif