#include <reg51.h>
#include "lcd.h"
#include "keypad.h"
#include "servo.h"
#include "uart.h"
#include "IR_sensor.h"
#include "Buzzer.h"
#include "leds.h"
#include "delay.h"

/* The pointer to char_ act as array of char_ (string) for the saved pass */
const unsigned char  saved_pass[5] = {'1','2','3','4','\0'};
/* The array that store the current password the user enterd */
unsigned char entered_pass[5];
/* The flag used for check if the flag is true or not */
unsigned char correct_pass_flag = 0;
/* This flag needed for checking if the re-enterd password correct or not */
unsigned char reEnter_pass_flag = 0;
/* This counter indicats to limitation of password entering times */
unsigned char num_ofCorrect_Password = 3;


void receive_PasswordfromUser(void);
void password_isCorrect(void);
void servoMotor_Action(void);
void LCD_homeScreen(void);

void main ()
{	
	/* Local var for reading sensor value */
	unsigned char IR_Read; 
	/* Init LCD to be able to display */
	LCD_init();
	/* Prepare timer 1 to start */
	Timer0_Start();
	/* Init Servo at inital angle */
	SERVO_init();
	/* Init uart for serial communication */
	uart_Init();
	/* Init IR */
	IR_Sensor_Init();
	/* Put the initial state of buzzer is off */
	BUZZER_status(BUZZER_OFF);
	/* Put the initial state of red led is off */
	RED_ledStatus(LED_OFF);
	/* Put the initial state of green led is off */
	GREEN_ledStatus(LED_OFF);
	/* Function to display the home screen */
	LCD_homeScreen();

for(;;){
		  /* Store the read of the sensor in this variable and check on it */
		IR_Read = IR_Sensor_Read();
	
		if( IR_Read == IR_DETECT )
		{
		/* If sensor detect there is a person it will change screen to password screen */
		LCD_clearScreen();	
		LCD_displayString("Enter Password:");
		LCD_moveCursor(1,0);
			
		/* Call this function for receiving password */
		receive_PasswordfromUser();
		password_isCorrect();
		
		/* Check on the password was matched to saved password */
		if( correct_pass_flag == 0)
		{
			/* Make sure that the counter still contains it is value if the user enters matched password */
			num_ofCorrect_Password = 3;
			/* Function for making the servo motor rotate */
			servoMotor_Action();
			/* Send to internal system 'S' as Start your System */
			uart_Sendbyte('S');
			delay_ms(1000);
			}
		else
		{
			/* Decrement the counter by 1 due to the wrong password */
			num_ofCorrect_Password--;
			/* This case means that the useer enter the wrong password */
			RED_ledStatus(LED_ON);
			/* Enter this loop if the password is not true*/
			while( num_ofCorrect_Password != 0 )
			{
			
			LCD_clearScreen();
			LCD_displayString("WRONG PASS");
			delay_ms(150);
			
			RED_ledStatus(LED_OFF);
			
			LCD_clearScreen();
			LCD_displayString("Enter Password:");
			LCD_moveCursor(1,0);
			
			receive_PasswordfromUser();
			password_isCorrect();
			
			if( correct_pass_flag == 1)
			{
				num_ofCorrect_Password--;
				delay_ms(150);
				RED_ledStatus(LED_ON);
				BUZZER_status(BUZZER_ON);

			}
			else if( correct_pass_flag == 0)
			{
				reEnter_pass_flag = 1;
				num_ofCorrect_Password = 3;
				break;
			}
			else
			{
				/* Do No Thing */
			}		 
			}//End of While
		}//End of else if the password is not true

		if(reEnter_pass_flag == 1 )
		{
			/* Reset the flag to be able to enter here again */
			reEnter_pass_flag = 0;
			/* Function for making the servo motor rotate */
			servoMotor_Action();
			/* After finishing return to the home page */
		  LCD_homeScreen();
			/* Send to internal system 'S' as Start your features */
			uart_Sendbyte('S');
			delay_ms(1000);
		}
			while(num_ofCorrect_Password == 0)
			{
				RED_ledStatus(LED_ON);
				GREEN_ledStatus(LED_ON);
				BUZZER_status(BUZZER_ON);
				
				LCD_clearScreen();
        LCD_moveCursor(0, 4);
        LCD_displayString("ACCESS DENIED");
        LCD_moveCursor(1, 0);
        LCD_displayString("INTRUDER ALERT!");
        delay_ms(5000);
				// Keep system locked until reset
        while (1) {
            // Wait for reset 
        }
			}
		}
		else
		{
			LCD_homeScreen();
		}
	}
}

void receive_PasswordfromUser(void) {
    unsigned char i;
    unsigned char key;
    
    // Initialize the entered_pass array to 0
    for (i = 0; i < 4; i++) {
        entered_pass[i] = 0;
    }
    // Receive up to 4 digits
    i = 0;
    while (i < 4) {
        key = KEYPAD_getPressedKey();
			  
			  if (key == '#') {
            break; // Exit the loop
        }
				
        // Check if the entered key is a digit
        if (key >= '0' && key <= '9') {
            entered_pass[i] = key;
            LCD_displayCharacter(entered_pass[i]);
            delay_ms(50);
            i++;
        }
        // Check if the entered key is '*', to undo the last entered number
        else if (key == '*') {
            if (i > 0) {
                i--; // Move back to the previous position
                entered_pass[i] = 0; // Clear the last entered number
                LCD_moveCursor(1, i); // Move the cursor to the position of the last number
                LCD_displayCharacter(' '); // Erase the last character on the LCD
                LCD_moveCursor(1, i); // Move the cursor back to the cleared position
            }
        }
        // Ignore any other key
        else {
            // No action for non-digit and non-'*' keys
        }
        delay_ms(50);
    }
    // Wait until the user presses '#'
    while (KEYPAD_getPressedKey() != '#');
}


void password_isCorrect(void){
	unsigned char i;
	correct_pass_flag = 0;
	for( i = 0; i < 4 ; i++ )		{
			if(entered_pass[i] != saved_pass[i])// 1331 != 1221
			{
				/* if the password not true the flag will rise */
				 correct_pass_flag = 1;
			}
		}
}

void servoMotor_Action(void){
			/* Make sure that the counter still contains it is value if the user enters matched password */
			num_ofCorrect_Password = 3;
			/* This case means that the useer enter the correct password */
			GREEN_ledStatus(LED_ON);
			LCD_clearScreen();
			delay_ms(50);
			
			/* Dispaly that the door is opened and open the door */
		 LCD_moveCursor(0,6);
		 LCD_displayString("Door");
		 LCD_moveCursor(1,4);
		 LCD_displayString("is Opened");
	
		 SERVO_rotateDegree(0XF9,0X34);
		 delay_ms(1500);
		 
		 /* Dispaly tehat the door is closed and close the door */
		 LCD_clearScreen();
		 LCD_moveCursor(0,6);
		 LCD_displayString("Door");
		 LCD_moveCursor(1,4);
		 LCD_displayString("is Closed");
		 
		 SERVO_rotateDegree(0XFA,0X24);
		 delay_ms(500);
		 
		 /*Finally, turn off the green led because the door was closed*/
		 GREEN_ledStatus(LED_OFF);
		 
		 LCD_clearScreen();
}

void LCD_homeScreen(void)
{
			LCD_moveCursor(0,0);
		  LCD_displayString("Welcome Home -_-");
}