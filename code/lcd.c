#include <reg51.h>
#include "delay.h"
#include "lcd.h"

sbit LCD_RS = P0^0; 
sbit LCD_En = P0^1; 

void LCD_init(void) {
    /* Configure the Direction of Rs Pin to output pin */
    LCD_RS = 0;
    /* Configure the Direction of En Pin to output pin */
    LCD_En = 0;
    /* This Delay 20ms needed from datasheet */
    delay_ms(20);
    /* Set the LCD_DATA_PORT to output port */
    LCD_DATA_PORT = 0x00;
    /* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
    LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
    /* cursor off */
    LCD_sendCommand(LCD_CURSOR_OFF);
    /* clear LCD at the beginning */
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_sendCommand(unsigned char command) {
    LCD_RS = 0;      // RS = 0 for command
    delay_ms(1);
    LCD_En = 1;      // Enable high
    delay_ms(1);
    LCD_DATA_PORT = command; // Set command to data port
    delay_ms(1);
    LCD_En = 0;      // Enable low
    delay_ms(1);
}

void LCD_displayCharacter(unsigned char my_data) {
    LCD_RS = 1;      // RS = 1 for data
    delay_ms(1);
    LCD_En = 1;      // Enable high
    delay_ms(1);
    LCD_DATA_PORT = my_data; // Set data to data port
    delay_ms(1);
    LCD_En = 0;      // Enable low
    delay_ms(1);
}

void LCD_displayString(const char *Str) {
    unsigned char i;
    for(i = 0; Str[i] != '\0'; i++) {
        LCD_displayCharacter(Str[i]);
    }
}

void LCD_clearScreen(void) {
    LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_moveCursor(unsigned char row, unsigned char col) {
    unsigned char memory_address;
    
    /* Calculate the required address in the LCD DDRAM */
    switch(row) {
        case 0: memory_address = col; break;
        case 1: memory_address = col + 0x40; break;
        case 2: memory_address = col + 0x10; break;
        case 3: memory_address = col + 0x50; break;
    }                    
    /* Move the LCD cursor to this specific address */
    LCD_sendCommand(memory_address | LCD_SET_CURSOR_LOCATION);
}
