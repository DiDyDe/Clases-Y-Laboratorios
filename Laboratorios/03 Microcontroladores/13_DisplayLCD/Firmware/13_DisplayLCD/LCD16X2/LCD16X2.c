/****************************************************

*****************************************************/

/*******************Conexiones***********************/
 /*    
 //-- Source        ==>   ATmega328P--//
 *    VSS           ==>     GND (0v)     
 *    VDD           ==>     Vcc (+5v)
 //-- Outputs		==>   ATmega328P--//
 *    ENABLE	    ==>     PIN PORTB0      
 *    RS			==>     PIN PORTB1       
 *    RW			==>     PIN PORTB2
 *    D4			==>     PIN PORTD4  
 *    D5			==>     PIN PORTD5
 *    D6			==>     PIN PORTD6
 *    D7			==>     PIN PORTD7
 */    
/*******************FIN Conexiones********************/

#include "LCD16X2.h"

#define CONTROLPORT	PORTB
#define ENABLE		PORTB0
#define RS			PORTB1

#define DATAPORT	PORTD

 void lcd_start()
 {
	CONTROLPORT &=~ (1<<ENABLE); 
	_delay_ms(1);
	CONTROLPORT |=  (1<<ENABLE);
 }

 void lcd_write(uint8_t type, uint8_t inst_data)
 {
	if (type)
		// DR - DATA REGISTER
		CONTROLPORT |=  (1<<RS);
	else
		// IR - INSTRUCTION REGISTER
		CONTROLPORT &=~ (1<<RS);

	DATAPORT = (PIND & 0x0F) | ( (inst_data)	& 0xF0);
	lcd_start();
	DATAPORT = (PIND & 0x0F) | ( (inst_data<<4) & 0xF0);
	lcd_start();
	_delay_ms(2);
 }

 void lcd_init()
 {
	DDRB  |=  (1<<DDB0) | (1<<DDB1);	
	DDRD  |=  (1<<DDB4) | (1<<DDB5) | (1<<DDB6) | (1<<DDB7);
	
	CONTROLPORT &=~ ((1<<ENABLE) | (1<<ENABLE));
	
	DATAPORT  = (PIND & 0x0F) | 0x30;

	lcd_start();

	DATAPORT = (PIND & 0x0F) | 0x20;
	
	lcd_start();

	lcd_write(LCD_INST, 0x2C);
	lcd_write(LCD_INST, 0x08);
	lcd_write(LCD_INST, 0x01);
	lcd_write(LCD_INST, 0x06);
	lcd_write(LCD_INST, 0x0C);
 }

void lcd_print(char *s)
{
	while(*s)
	{
		lcd_write(LCD_DATA, *s);
		s++;
	}
}