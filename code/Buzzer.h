#ifndef BUZZER_H
#define BUZZER_H

#include <reg51.h>
#include "delay.h"

// Define the buzzer pin
sbit BUZZER = P3^6; // Buzzer connected to Port 3, Pin 6

// Define buzzer states
#define BUZZER_ON  1
#define BUZZER_OFF 0

// Function prototypes
void BUZZER_status(unsigned char status);

#endif