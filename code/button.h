#ifndef BUTTON_H
#define BUTTON_H

#include <reg51.h>
#include "delay.h"

// Define the button pin
sbit BUTTON = P3^6; // Button connected to Port 3, Pin 6

// Define button states
#define BUTTON_ON  1
#define BUTTON_OFF 0

// Function prototypes
void BUTTON_status(unsigned char status);

#endif