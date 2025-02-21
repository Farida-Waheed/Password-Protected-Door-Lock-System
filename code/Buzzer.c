#include "Buzzer.h"
#include "delay.h"

// Function to control the buzzer state
void BUZZER_status(unsigned char status) {
    if (status == BUZZER_ON) {
        BUZZER = BUZZER_ON; // Turn buzzer ON
    } 
		else  {
        BUZZER = BUZZER_OFF; // Turn buzzer OFF
    }
}
