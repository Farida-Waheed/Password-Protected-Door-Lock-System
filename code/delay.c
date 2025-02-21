#include "delay.h"


void delay_ms(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<600;j++);
	}
}