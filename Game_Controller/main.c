
#include <stdlib.h>
#include "frdm_bsp.h" 
#include "stdio.h"
#include "i2c.h"
#include "lcd1602.h"
#include "MKL05Z4.h"
#include "UART_abs.h"
#include "GPIO_IRQ.h"


#define MAX_LEN 512

char rx_buf[]={0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
char temp;
char buff[] = "Merry Christmas";
uint8_t rx_FULL=0;





void PORTB_IRQHAndler(void){
	volatile uint8_t sw;
	sw = PORTB->ISFR & (C4_Mask | C3_Mask | C2_Mask | C1_Mask);
	
	switch(sw){
		case C4_Mask:
			if(!(PTA->PDIR & C4_Mask)){
				
			}
			break;
		case C3_Mask:
			if(!(PTA->PDIR & C3_Mask)){
				
			}
			break;
		case C2_Mask:
			if(!(PTA->PDIR & C2_Mask)){
				
			}
			break;
		case C1_Mask:
			if(!(PTA->PDIR & C2_Mask)){
				
			}
			break;
		default:
			break;
	}

}


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
