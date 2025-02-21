#include "dc_motor.h"
#include <reg51.h>


// Initialize DC Motor (set motor pins as output)
void Dc_Motor_Init(void)
{
    P2 = 0x00;  // Set all Port 2 pins to low (turn off motor initially)
	  MOTOR_PIN_0 = 0;
	  MOTOR_PIN_1 = 0;
	  MOTOR_PIN_2 = 0;
}

// Rotate motor in specified direction
void Dc_Motor_Rotate(unsigned char direction)
{
    MOTOR_PIN_2 = 1;  // Enable motor (turn on motor driver, assuming active-high for control)

    switch(direction)
    {
        case ROTATE_LEFT:
            MOTOR_PIN_0 = 1;  // Set Pin 0 high (rotate left)
            MOTOR_PIN_1 = 0;  // Set Pin 1 low
            break;

        case ROTATE_RIGHT:
            MOTOR_PIN_1 = 1;  // Set Pin 1 high (rotate right)
            MOTOR_PIN_0 = 0;  // Set Pin 0 low
            break;

        case ROTATE_STOP:
            MOTOR_PIN_0 = 0;  // Set both pins low (stop motor)
            MOTOR_PIN_1 = 0;
            break;

        default:
            MOTOR_PIN_0 = 0;  // Default: Stop motor (set both pins low)
            MOTOR_PIN_1 = 0;
            break;
    }
}