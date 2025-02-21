#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <reg51.h>

// Define the IR sensor pin
sbit IR_SENSOR_PIN = P3^3; // Pin connected to the IR sensor

// Define the states of the IR sensor
#define IR_DETECT  0  // Object detected
#define IR_NO_DETECT 1 // No object detected

// Function prototypes
void IR_Sensor_Init(void);
unsigned char IR_Sensor_Read(void);

#endif
