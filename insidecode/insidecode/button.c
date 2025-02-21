#include "button.h"
#include "delay.h"

// Function to control the bottun state
void AC_button_status(unsigned char status){
    if (status == BUTTON_ON) {
        AC_button = BUTTON_ON; // Turn buzzer ON
    } 
		else  {
        AC_button = BUTTON_OFF; // Turn buzzer OFF
    }
}
void Light_button_status(unsigned char status){
    if (status == BUTTON_ON) {
        Light_button = BUTTON_ON; // Turn buzzer ON
    } 
		else  {
        Light_button = BUTTON_OFF; // Turn buzzer OFF
    }
}
