#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL //1 Mhz
#include <util/delay.h>

#define DISPLAY PORTB
#define MUX_DIS_1 PORTD0
#define MUX_DIS_2 PORTD1


void init_ports(void);
void RET1S(void);
void MOSTRAR(void);

int CONT = 0;
int CONTRET = 0;


int main(void)
{

	init_ports();

	
	CONT = 0;
    while (1) 
    {
		CONT = 0;
		while ( CONT < 100)
		{
			RET1S();	
			CONT++;
				
		}
			
    }
}

void init_ports()
{
	// Salidas
	DDRB    = 0xFF; // Declarar salidas
	DISPLAY = 0x00; // Colocar en LOW las salidas
	
	DDRD  |=  ( _BV(MUX_DIS_1) | _BV(MUX_DIS_2)	);
	PORTD &= ~( _BV(MUX_DIS_1) | _BV(MUX_DIS_2)	 );	
}

void RET1S(void)
{
	CONTRET = 10;
	while ( CONTRET > 0)
	{
		MOSTRAR();
		CONTRET--;
	}
	
}

void MOSTRAR(void)
{
	int UNI, DEC;
	UNI = (CONT % 100) / 10;  // Display decenas
	DEC = CONT % 10;
	
	DISPLAY = UNI;
	PORTD  |=  _BV(MUX_DIS_1);
	_delay_ms(0.5);
	PORTD  &=  ~_BV(MUX_DIS_1);
	DISPLAY = DEC;
	PORTD  |=  _BV(MUX_DIS_2);
	_delay_ms(0.5);
	PORTD  &=  ~_BV(MUX_DIS_2);	
}