#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <reg51.h>
#include "lcd.h"
#include "delay.h"

/* Define the number of rows and columns */
#define KEYPAD_NUM_COLS 3
#define KEYPAD_NUM_ROWS 4

/* Define port for rows and columns */
#define KEYPAD_ROW_PORT P2
#define KEYPAD_COL_PORT P2

/* Define button states */
#define KEYPAD_BUTTON_PRESSED 0
#define KEYPAD_BUTTON_RELEASED 1

/* Define pin mappings for rows */
sbit KEYPAD_ROW_Pin_1 = KEYPAD_ROW_PORT^3;
sbit KEYPAD_ROW_Pin_2 = KEYPAD_ROW_PORT^4;
sbit KEYPAD_ROW_Pin_3 = KEYPAD_ROW_PORT^5;
sbit KEYPAD_ROW_Pin_4 = KEYPAD_ROW_PORT^6;

/* Define pin mappings for columns */
sbit KEYPAD_COL_Pin_1 = KEYPAD_COL_PORT^0;
sbit KEYPAD_COL_Pin_2 = KEYPAD_COL_PORT^1;
sbit KEYPAD_COL_Pin_3 = KEYPAD_COL_PORT^2;

/* Function prototype */
unsigned char KEYPAD_getPressedKey(void);

#endif
