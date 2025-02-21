#include "IR_Sensor.h"

// Initialize the IR sensor (set it as input)
void IR_Sensor_Init(void) {
    IR_SENSOR_PIN == 1; // Set IR sensor pin as input
}

// Read the status of the IR sensor
unsigned char IR_Sensor_Read(void) {
    // Return the current status of the IR sensor pin
    // If the pin is low (0), object is detected
    if (IR_SENSOR_PIN == 0) {
        return IR_DETECT;  // Object detected
    } else {
        return IR_NO_DETECT;  // No object detected
    }
}
