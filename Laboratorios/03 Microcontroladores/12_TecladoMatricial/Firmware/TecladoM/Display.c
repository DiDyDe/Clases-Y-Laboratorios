/*
 * Display.c
 *
 * Created: 28/09/2022 03:44:40 p. m.
 *  Author: jdgar
 */ 

//Bibliotecas
//-Internas
#include <avr/io.h> //se incluyen las bibioletcas de E/S del AVR
//-Externas
#include "Display.h"

/*
+-----------------------------------------------+
| Prototype:   void init_display(void);         |
| Return Type: None                             |
| Arguments:   None                             |
| Description:                                  |
+-----------------------------------------------+
*/
void init_display(void)
{
	//Segementos
	DDRB  |=  (_BV(SEGA) | _BV(SEGB) | _BV(SEGC) | _BV(SEGD));
	DDRB  |=  (_BV(SEGE) | _BV(SEGF));
	DDRB  |=   _BV(SEGG);
	//-Apagados
	PORTB  &= ~(_BV(SEGA) | _BV(SEGB) | _BV(SEGC) | _BV(SEGD));
	PORTB  &= ~(_BV(SEGE) | _BV(SEGF));
	PORTB  &= ~ _BV(SEGG);
}
/*
+-----------------------------------------------+
| Prototype:   void show_number(uint8_t x);     |
| Return Type: void                             |
| Arguments:   uint8_t x                        |
| Description:                                  |
+-----------------------------------------------+
*/
void show_number(uint8_t x)
{
	switch (x)
	{
		//Muestra numero 0
		case 0:
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_OFF;
		break;
		//Muestra numero 1
		case 1:
			SEGA_OFF;
			SEGB_ON;
			SEGC_ON;
			SEGD_OFF;
			SEGE_OFF;
			SEGF_OFF;
			SEGG_OFF;
		break;
		//Muestra numero 2
		case 2:
			SEGA_ON;
			SEGB_ON;
			SEGC_OFF;
			SEGD_ON;
			SEGE_ON;
			SEGF_OFF;
			SEGG_ON;
		break;
		//Muestra numero 3
		case 3:
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_ON;
			SEGE_OFF;
			SEGF_OFF;
			SEGG_ON;
		break;
		//Muestra numero 4
		case 4:
			SEGA_OFF;
			SEGB_ON;
			SEGC_ON;
			SEGD_OFF;
			SEGE_OFF;
			SEGF_ON;
		SEGG_ON;
		break;
		//Muestra numero 5
		case 5:
			SEGA_ON;
			SEGB_OFF;
			SEGC_ON;
			SEGD_ON;
			SEGE_OFF;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero 6
		case 6:
			SEGA_ON;
			SEGB_OFF;
			SEGC_ON;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero 7
		case 7:
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_OFF;
			SEGE_OFF;
			SEGF_OFF;
			SEGG_OFF;
		break;
		//Muestra numero 8
		case 8:
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero 9
		case 9:
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_ON;
			SEGE_OFF;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero A
		case 10://A
			SEGA_ON;
			SEGB_ON;
			SEGC_ON;
			SEGD_OFF;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero B
		case 11:
			SEGA_OFF;
			SEGB_OFF;
			SEGC_ON;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero C
		case 12:
			SEGA_ON;
			SEGB_OFF;
			SEGC_OFF;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_OFF;
		break;
		//Muestra numero D
		case 13:
			SEGA_OFF;
			SEGB_ON;
			SEGC_ON;
			SEGD_ON;
			SEGE_ON;
			SEGF_OFF;
			SEGG_ON;
		break;
		//Muestra numero E
		case 14:
			SEGA_ON;
			SEGB_OFF;
			SEGC_OFF;
			SEGD_ON;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
		//Muestra numero F
		case 15:
			SEGA_ON;
			SEGB_OFF;
			SEGC_OFF;
			SEGD_OFF;
			SEGE_ON;
			SEGF_ON;
			SEGG_ON;
		break;
	}//FIN switch case
}//FIN show_number