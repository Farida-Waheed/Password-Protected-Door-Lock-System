#include "button.h"
#include "delay.h"

// Function to control the bottun state
void BUTTON_status(unsigned char status) {
    if (status == BUTTON_ON) {
        BUTTON = BUTTON_ON; // Turn buzzer ON
    } 
		else  {
        BUTTON = BUTTON_OFF; // Turn buzzer OFF
    }
}
