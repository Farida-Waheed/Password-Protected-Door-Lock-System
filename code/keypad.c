#include "keypad.h"
#include "delay.h"

/* Function to get the pressed key */
unsigned char KEYPAD_getPressedKey(void)
{
    while (1)
    {
        // Initialize all columns to high
        KEYPAD_COL_Pin_1 = 1;
        KEYPAD_COL_Pin_2 = 1;
        KEYPAD_COL_Pin_3 = 1;

        delay_ms(50);

        // Activate each row and check the columns
        KEYPAD_ROW_Pin_1 = 0;
        KEYPAD_ROW_Pin_2 = 1;
        KEYPAD_ROW_Pin_3 = 1;
        KEYPAD_ROW_Pin_4 = 1;

        if (KEYPAD_COL_Pin_1 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_1 == 0); return '1'; }
        if (KEYPAD_COL_Pin_2 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_2 == 0); return '2'; }
        if (KEYPAD_COL_Pin_3 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_3 == 0); return '3'; }

        KEYPAD_ROW_Pin_1 = 1;
        KEYPAD_ROW_Pin_2 = 0;
        KEYPAD_ROW_Pin_3 = 1;
        KEYPAD_ROW_Pin_4 = 1;

        if (KEYPAD_COL_Pin_1 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_1 == 0); return '4'; }
        if (KEYPAD_COL_Pin_2 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_2 == 0); return '5'; }
        if (KEYPAD_COL_Pin_3 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_3 == 0); return '6'; }

        KEYPAD_ROW_Pin_1 = 1;
        KEYPAD_ROW_Pin_2 = 1;
        KEYPAD_ROW_Pin_3 = 0;
        KEYPAD_ROW_Pin_4 = 1;

        if (KEYPAD_COL_Pin_1 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_1 == 0); return '7'; }
        if (KEYPAD_COL_Pin_2 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_2 == 0); return '8'; }
        if (KEYPAD_COL_Pin_3 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_3 == 0); return '9'; }

        KEYPAD_ROW_Pin_1 = 1;
        KEYPAD_ROW_Pin_2 = 1;
        KEYPAD_ROW_Pin_3 = 1;
        KEYPAD_ROW_Pin_4 = 0;

        if (KEYPAD_COL_Pin_1 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_1 == 0); return '*'; }
        if (KEYPAD_COL_Pin_2 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_2 == 0); return '0'; }
        if (KEYPAD_COL_Pin_3 == 0) { delay_ms(50); while (KEYPAD_COL_Pin_3 == 0); return '#'; }
    }
}

