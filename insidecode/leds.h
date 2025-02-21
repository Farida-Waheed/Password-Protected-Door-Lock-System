#ifndef __LEDS_H__
#define __LEDS_H__
#include <reg51.h>

sbit W_led  = P0^5;
sbit B_led  = P0^4;
sbit Y_led  = P0^3;
sbit O_led  = P0^2;

#define LED_ON          0
#define LED_OFF         1

void WHITE_ledStatus(unsigned char status);

void BLUE_ledStatus(unsigned char status);

void YELLOW_ledStatus(unsigned char status);

void ORANGE_ledStatus(unsigned char status);

#endif