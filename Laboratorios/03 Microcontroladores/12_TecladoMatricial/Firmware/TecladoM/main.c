/****************************************************
 * Nombre: Eduardo Vicente Reyna Villela			*
 * Hora clase: M4-M6								*
 * Día: Jueves										*
 * N° de lista:                                     *
 * N° de Equipo: No aplica					        *
 * Dispositivo: Atmega328P							*
 * Rev: 1.0                                         *
 * Propósito de la actividad:                       *
 * Sistema con 2 botones y un contador mostrado en  *
 * un display de 7 segmentos						*
 *                                Fecha: 27/07/2021 *
 ***************************************************/

/*******************Bibliotecas****************************/
#include <avr/io.h>
// Velocidad del micro
#define F_CPU 1000000UL
#include <util/delay.h>
#include "Display.h"


/*****************Macros y constantes**********************/
#define BTN		 PIND
#define COL_ROWS PORTD 

#define BTN_ROW1 PIND0
#define BTN_ROW2 PIND1
#define BTN_ROW3 PIND2
#define BTN_ROW4 PIND3

#define BTN_COL1 PIND4
#define BTN_COL2 PIND5
#define BTN_COL3 PIND6
#define BTN_COL4 PIND7


#define value 0

#define read_row1 bit_is_set(BTN, BTN_ROW1)
#define read_row2 bit_is_set(BTN, BTN_ROW2) 
#define read_row3 bit_is_set(BTN, BTN_ROW3) 
#define read_row4 bit_is_set(BTN, BTN_ROW4) 

#define read_col1 bit_is_set(BTN, BTN_COL1) 
#define read_col2 bit_is_set(BTN, BTN_COL2) 
#define read_col3 bit_is_set(BTN, BTN_COL3) 
#define read_col4 bit_is_set(BTN, BTN_COL4) 

#define A1 read_row1 == value && read_col1 == value
#define A2 read_row1 == value && read_col2 == value
#define A3 read_row1 == value && read_col3 == value
#define A4 read_row1 == value && read_col4 == value

#define B1 read_row2 == value && read_col1 == value
#define B2 read_row2 == value && read_col2 == value
#define B3 read_row2 == value && read_col3 == value
#define B4 read_row2 == value && read_col4 == value

#define C1 read_row3 == value && read_col1 == value
#define C2 read_row3 == value && read_col2 == value
#define C3 read_row3 == value && read_col3 == value
#define C4 read_row3 == value && read_col4 == value

#define D1 read_row4 == value && read_col1 == value
#define D2 read_row4 == value && read_col2 == value
#define D3 read_row4 == value && read_col3 == value
#define D4 read_row4 == value && read_col4 == value


#define	CERO	0x7E // 0
#define	UNO		0x30 // 1
#define	DOS		0x6D // 2
#define	TRES	0x79 // 3
#define	CUATRO	0x33 // 4
#define	CINCO	0x5B // 5
#define	SEIS	0x5F // 6
#define	SIETE	0x70 // 7
#define	OCHO	0x7F // 8
#define	NUEVE	0x73 // 9
#define	LETRA_A 0x77 // A
#define	LETRA_B 0x1F // B
#define	LETRA_C 0x4E // C
#define	LETRA_D 0x3D // D
#define	LETRA_E 0x4F // E
#define	LETRA_F 0x47 // F



/*******************Variables globales*********************/

/***********************Funciones**************************/
void init_ports(void);

/*******************Programa principal*********************/
int main(void)
{
	init_ports();
	
    while (1) 
    {
		COL_ROWS &= ~(1 << BTN_ROW1);
		COL_ROWS |= (1 << BTN_ROW2);
		COL_ROWS |= (1 << BTN_ROW3);
		COL_ROWS |= (1 << BTN_ROW4);
		if (A1) show_number(7);
		if (A2) show_number(8);
		if (A3) show_number(9);
		if (A4) show_number(10);
		
			 
		COL_ROWS |= (1 << BTN_ROW1);
		COL_ROWS &= ~(1 << BTN_ROW2);
		COL_ROWS |= (1 << BTN_ROW3);
		COL_ROWS |= (1 << BTN_ROW4);			
		if (B1) show_number(4);
		if (B2) show_number(5);
		if (B3) show_number(6);
		if (B4) show_number(11);	
		
		
		
		COL_ROWS |= (1 << BTN_ROW1);
		COL_ROWS |= (1 << BTN_ROW2);
		COL_ROWS &= ~(1 << BTN_ROW3);
		COL_ROWS |= (1 << BTN_ROW4);			
		if (C1) show_number(1);
		if (C2) show_number(2);
		if (C3) show_number(3);
		if (C4) show_number(12);
		
		
		
		COL_ROWS |= (1 << BTN_ROW1);
		COL_ROWS |= (1 << BTN_ROW2);
		COL_ROWS |= (1 << BTN_ROW3);
		COL_ROWS &= ~(1 << BTN_ROW4);			
		if (D1) show_number(13);
		if (D2) show_number(0);
		if (D3) show_number(14);
		if (D4) show_number(15);
	}	
}


void init_ports(void)
{
	
	
	// Entradas
	DDRD  &= ~( (1 << BTN_COL1) | (1 << BTN_COL2) | (1 << BTN_COL3) | (1 << BTN_COL4) ); // Declarar entradas
	PORTD |= ( (1 << BTN_COL1) | (1 << BTN_COL2) | (1 << BTN_COL3) | (1 << BTN_COL4) ); // Pull up


	// Salidas
	DDRD  |=  ( (1 << BTN_ROW1) | (1 << BTN_ROW2) | (1 << BTN_ROW3) | (1 << BTN_ROW4) ); // Declarar Salidas
	PORTD |=  ( (1 << BTN_ROW1) | (1 << BTN_ROW2) | (1 << BTN_ROW3) | (1 << BTN_ROW4) );
	
	DDRB    = 0xFF; // Declarar salidas
	DISPLAY = 0xFF; // Colocar en LOW las salidas
	
}
