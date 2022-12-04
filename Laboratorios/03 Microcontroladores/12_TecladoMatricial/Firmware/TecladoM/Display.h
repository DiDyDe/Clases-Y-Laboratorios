/*
 * Display.h
 *
 * Created: 28/09/2022 03:44:52 p. m.
 *  Author: jdgar
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

//Segementos
//-Puerto D
#define DISPLAY PORTB
//--Segemento A
#define SEGA PORTB6
#define SEGA_OFF  DISPLAY |=  _BV(SEGA); //Enciende
#define SEGA_ON DISPLAY &= ~_BV(SEGA); //Apaga
//--Segemento B
#define SEGB PORTB5
#define SEGB_OFF  DISPLAY |=  _BV(SEGB);
#define SEGB_ON DISPLAY &= ~_BV(SEGB);
//--Segemento C
#define SEGC PORTB4
#define SEGC_OFF  DISPLAY |=  _BV(SEGC);
#define SEGC_ON DISPLAY &= ~_BV(SEGC);
//--Segemento D
#define SEGD PORTB3
#define SEGD_OFF  DISPLAY |=  _BV(SEGD);
#define SEGD_ON DISPLAY &= ~_BV(SEGD);
//--Segemento E
#define SEGE PORTB2
#define SEGE_OFF  DISPLAY |=  _BV(SEGE);
#define SEGE_ON DISPLAY &= ~_BV(SEGE);
//--Segemento F
#define SEGF PORTB1
#define SEGF_OFF  DISPLAY |=  _BV(SEGF);
#define SEGF_ON DISPLAY &= ~_BV(SEGF);
//-Puerto B
//--Segemento G
#define SEGG PORTB0
#define SEGG_OFF  PORTB   |=  _BV(SEGG);
#define SEGG_ON PORTB   &= ~_BV(SEGG);

//Declaracion
void show_number(uint8_t x); // Función para mostar mostar
void init_display(void);

#endif /* DISPLAY_H_ */