#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include <reg51.h>

// Motor Control Pins 
sbit MOTOR_PIN_0 = P2^0;  // Pin 0 for motor control
sbit MOTOR_PIN_1 = P2^1;  // Pin 1 for motor control
sbit MOTOR_PIN_2 = P2^2;  // Pin 2 for motor control

// Motor Rotation Directions
#define ROTATE_LEFT    0
#define ROTATE_RIGHT   1
#define ROTATE_STOP    2

// Motor Control Function Prototypes
void Dc_Motor_Init(void);
void Dc_Motor_Rotate(unsigned char  direction);

#endif /* DC_MOTOR_H */ 