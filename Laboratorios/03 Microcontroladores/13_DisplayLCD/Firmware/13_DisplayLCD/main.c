#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD16X2/LCD16X2.h"

char PRUEBA[] = "PRUEBA,";
char prueba[] = "prueba ";

int main(void)
{
    lcd_init();

    while (1)
	{
		lcd_write(LCD_INST, CLEAR);
		lcd_print("SSSSSSSSSSSHOLA");
		_delay_ms(2000);
		
		lcd_write(LCD_INST, CLEAR);
		lcd_print("84 PPM");
		_delay_ms(2000);
		
		lcd_write(LCD_INST, LINEA2);
		lcd_print("CIAO");
		_delay_ms(2000);				
		/*
		lcd_write(LCD_INST, LINEA2);
		lcd_print(prueba);
		lcd_write(LCD_DATA, ':');
		lcd_write(LCD_DATA, 'D');
		_delay_ms(3000);
		*/
	}
}

