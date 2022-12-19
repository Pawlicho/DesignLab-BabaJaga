
#include "UART_abs.h"

void uart_INIT(void){

	UART0_Init();
	uart_send("AT+NAMEBJTX");
}

/*
param: pointer to array we want to send
*/
void uart_send(char* pbuf){
	
	UART0->C2 |= UART0_C2_TE_MASK;
	for(int i=0;pbuf[i]!=0;i++)	// Zla komenda
	{
		while(!(UART0->S1 & UART0_S1_TDRE_MASK));	// Czy nadajnik gotowy?
		UART0->D = pbuf[i];
	}		
	
}