#ifndef __UART_H__
#define __UART_H__

#include <reg51.h>

sbit RX_pin = P3^0;
sbit TX_pin = P3^1;


void uart_Init(void);
void uart_Sendbyte(unsigned char ch);
unsigned char uart_Receivebyte(void);

#endif