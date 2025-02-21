/*
 * MotorDriver.c
 *
 *  Created on: Dec 7, 2024
 *      Author: LOLO
 */

#include "MotorDriver.h"

// Initialize motor control pins and Timer for PWM
void MotorDriver_Init(void) {
    // Set motor control pins as output
    P1_1 = 0;  // Set IN1 to 0
    P1_2 = 0;  // Set IN2 to 0
    MOTOR_ENA_PIN = 0;  // Set enable pin to 0 (to disable motor initially)

    // Configure Timer for PWM (for speed control)
    TMOD |= 0x02;  // Set Timer0 to Mode 2 (8-bit auto-reload)
    TH0 = 0x00;    // Load the timer high byte
    TL0 = 0x00;    // Load the timer low byte
    TR0 = 1;       // Start Timer0
}

// Set motor speed using PWM (0-100% speed)
void MotorDriver_SetSpeed(uint8_t speedPercent) {
    // Calculate the PWM value from the speed percentage (0 to 255)
    uint8_t pwmValue = (speedPercent * 255) / 100;
    TH0 = pwmValue;  // Set high byte of PWM duty cycle
    TL0 = pwmValue;  // Set low byte of PWM duty cycle
}

// Set motor direction: FORWARD, BACKWARD, or STOP
void MotorDriver_SetDirection(uint8_t direction) {
    switch(direction) {
        case FORWARD:
            P1_1 = 1;  // IN1 = 1
            P1_2 = 0;  // IN2 = 0
            break;
        case BACKWARD:
            P1_1 = 0;  // IN1 = 0
            P1_2 = 1;  // IN2 = 1
            break;
        case STOP:
            P1_1 = 0;  // IN1 = 0
            P1_2 = 0;  // IN2 = 0
            break;
        default:
            MotorDriver_Stop();  // Stop motor if invalid direction
            break;
    }
}

// Stop the motor by setting both inputs low
void MotorDriver_Stop(void) {
    P1_1 = 0;  // IN1 = 0
    P1_2 = 0;  // IN2 = 0
}

