#include <reg51.h>
#include "LCD.h"
#include "DC_Motor.h"
#include "delay.h"
#include "UART.h"
#include "button.h"
#include "leds.h"

unsigned char AC_button_count = 0;
unsigned char Light_button_count = 0;

void Lcd_SmartFeatures(void);
void Lcd_HomeScreen(void);

void main(void) {
	  unsigned char Button_Read;
    unsigned char received_byte ;	
	
    uart_Init();
    LCD_init();
    Dc_Motor_Init();
	  WHITE_ledStatus(LED_OFF);
    BLUE_ledStatus(LED_OFF);
    YELLOW_ledStatus(LED_OFF);
    ORANGE_ledStatus(LED_OFF);

    Lcd_HomeScreen();

    while (1) {
        received_byte = uart_Receivebyte() ;

        if (received_byte == 'S') {
            Lcd_SmartFeatures();
            while (received_byte == 'S') {
                // AC Button Handling
                if (AC_button == 0) {  // Check if AC button is pressed (active low)
                    delay_ms(30);  

                    if ((AC_button) == 0) {
                        AC_button_count++;
                        if (AC_button_count == 1) {
                            LCD_moveCursor(0, 10);
                            LCD_displayString("ON ");
                            Dc_Motor_Rotate(ROTATE_RIGHT);
                            delay_ms(1000);
                        } else if (AC_button_count == 2) {
                            AC_button_count = 0;
                            LCD_moveCursor(0, 10);
                            LCD_displayString("OFF");
                            Dc_Motor_Rotate(ROTATE_STOP);
                            delay_ms(1000);
                        }
                        while ((AC_button) == 0);  // Wait for button release
                    }
                }

                // Light Button Handling
                if ((Light_button) == 0) {  // Check if Light button is pressed (active low)
                    delay_ms(30);  // Debounce delay

                    if ((Light_button) == 0) {
                        Light_button_count++;
                        if (Light_button_count == 1) {
                            LCD_moveCursor(1, 14);
                            LCD_displayString("M1 ");
                            P0 = P0 & ~(1<<2);  // Set the LEDs for Mode 1
                            delay_ms(500);
                        } else if (Light_button_count == 2) {
                            LCD_moveCursor(1, 14);
                            LCD_displayString("M2 ");
                            P0 = P0 & ~(1<<3);  // Set the LEDs for Mode 2
                            delay_ms(500);
                        } else if (Light_button_count == 3) {
                            LCD_moveCursor(1, 14);
                            LCD_displayString("M3 ");
                            P0 = P0 & ~(1<<4);  // Set the LEDs for Mode 3
                            delay_ms(500);
                        } else if (Light_button_count == 4) {
                            LCD_moveCursor(1, 14);
                            LCD_displayString("M4 ");
                            P0 = P0 & ~(1<<5);  // Set the LEDs for Mode 4
                            delay_ms(500);
                        } else if (Light_button_count == 5) {
                            Light_button_count = 0;
                            LCD_moveCursor(1, 13);
                            LCD_displayString("OFF");
                            P0 = P0 | (15<<2); 
                            delay_ms(500);
                        }
                        while ((Light_button) == 0);  // Wait for button release
                    }
                }
            }
        }
        if (received_byte != 'S') {
            Lcd_HomeScreen();
        }
    }
}

void Lcd_SmartFeatures(void) {
    LCD_moveCursor(0, 0);
    LCD_displayString("AC Status:   ");
    LCD_moveCursor(1, 0);
    LCD_displayString("Light Status:   ");
}

void Lcd_HomeScreen(void) {
    LCD_clearScreen();
    LCD_displayString("   Smart Home   ");
    LCD_moveCursor(1, 0);
    LCD_displayString(" We Always Here ");
}
