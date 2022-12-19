
#include <stdlib.h>

#include "MKL05Z4.h"
#include "uart0.h"
#include "frdm_bsp.h"

#define PING "AT"	        //OK	         	 Used to verify communication
#define VERSION "AT+VERSION"	//OKlinvorV1.8		The firmware version (version might depend on firmware)
#define SET_PIN "AT+PIN1234"	//OKsetPIN	   		Sets the module PIN to 1234
#define BR1200 "AT+BAUD1"	//	OK1200	      Sets the baud rate to 1200
#define BR2400 "AT+BAUD2"	//	OK2400	      Sets the baud rate to 2400
#define BR4800 "AT+BAUD3"	//	OK4800	     /Sets the baud rate to 4800
#define BR9600 "AT+BAUD4"	//	OK9600	      Sets the baud rate to 9600
#define BR19200 "AT+BAUD5"	//	OK19200	     Sets the baud rate to 19200
#define BR38400 "AT+BAUD6"	//	OK38400	     Sets the baud rate to 38400
#define BR57600 "AT+BAUD7"	//	OK57600	     Sets the baud rate to 57600
#define BR115200 "AT+BAUD8"	//	OK115200	    Sets the baud rate to 115200
#define BR230400 "AT+BAUD9"	//	OK230400	   Sets the baud rate to 230400
#define BR460800 "AT+BAUDA"	//	OK460800	    Sets the baud rate to 460800
#define BR921600 "AT+BAUDB"	//	OK921600	   	Sets the baud rate to 921600
#define BR1382400 "AT+BAUDC"	//	OK1382400	   Sets the baud rate to 1382400
#define LF 0xA
#define CR 0xD

void uart_INIT(void);
void uart_send(char* pbuf);




/*

TODO(PREPARE RIGHT UART FRAME FOR GAME SETUP)


*/