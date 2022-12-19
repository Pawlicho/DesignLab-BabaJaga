/*-------------------------------------------------------------------------------------
					Technika Mikroprocesorowa 2 - laboratorium
					Lab 8 - Cwiczenie 1: szukanie urzadzen na magistrali I2C
					autor: Mariusz Sokolowski
					wersja: 10.10.2022r.
----------------------------------------------------------------------------*/

#include <stdlib.h>
#include "frdm_bsp.h" 
#include "stdio.h"
#include "i2c.h"
#include "lcd1602.h"
#include "MKL05Z4.h"
#include "uart0.h"
#include "UART_abs.h"


#define MAX_LEN 512

char rx_buf[]={0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
char temp;
char buff[] = "Merry Christmas";
uint8_t rx_FULL=0;


int main (void)
{ 
	char display[]={0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
	
	LCD1602_Init();	// Tu jest równiez inicjalizacja portu I2C0
	LCD1602_Backlight(TRUE);
	
	uart_INIT();
	uint8_t error;
		
	
	LCD1602_SetCursor(0,0);
	sprintf(display, buff);
	LCD1602_Print(display);
	
	while(1){
		
	
	} 
}
