#ifndef BUTTON_H
#define BUTTON_H

#include <reg51.h>
#include "delay.h"

// Define the button pin
sbit AC_button = P3^2; 
sbit Light_button = P3^3;

// Define button states
#define BUTTON_ON  1
#define BUTTON_OFF 0

// Function prototypes
void AC_button_status(unsigned char status);
void Light_button_status(unsigned char status);

#endif