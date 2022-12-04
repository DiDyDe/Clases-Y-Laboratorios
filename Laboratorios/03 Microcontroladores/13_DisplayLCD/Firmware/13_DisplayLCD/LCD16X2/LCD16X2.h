#ifndef LCD16X2_H_
#define LCD16X2_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define LCD_INST	0
#define LCD_DATA	1

#define LINEA1		0x80
#define LINEA2		0xC0
#define LINEA3		0x94
#define LINEA4		0xD4
#define CLEAR		0x01

void lcd_start();
void lcd_write(uint8_t type, uint8_t inst_data);
void lcd_init();

void lcd_print(char *s);

#endif 