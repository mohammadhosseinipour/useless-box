/*
 * GccApplication1.c
 *
 * Created: 8/3/2020 5:48:55 PM
 * Author : mohammad
 */ 

#define F_CPU 8000000UL		/* Define CPU Frequency e.g. here its 8MHz */
#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <stdlib.h>
#include <time.h>
#include <util/delay.h>		/* Include Delay header file */

int main(void)
{
	DDRD |= (1<<PD5);		/* Make OC1A pin as output */
	DDRA =0xFF;
	PORTA=0x00;
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	int c=0,mode=0,counter=0;
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	mode=1;
	while(1)
	{
		if(mode==7)
			mode=1;
		counter++;
		OCR1A=65;
		if(PINC==0x01)
		{
		_delay_ms(5);
		if(PINC==0x01)
		{
			/*srand(time(0));
			mode=(rand()%6)+1;*/
			switch(mode)
			{
				case 1:
				mode++;
				srand(time(0));
				c=(rand()%5+1)*6;
				
				for(int i=65;i<=300;i++)
				{
					OCR1A=i;
					for(int j=0;j<=c;j++)
					{
						_delay_ms(1);
					}
					if(i==220)
					{
						OCR1A=300;
						_delay_ms(1000);
						break;
					}
				}
				break;
				
				
				case 2:
				mode++;
				OCR1A=65;
				_delay_ms(1000);
				OCR1A=300;
				PORTA=0X09;
				_delay_ms(3000);
				PORTA=0X06;
				_delay_ms(2000);
				PORTA=0x00;
				break;
				
				
				case 3:
				mode++;
				OCR1A=65;
				_delay_ms(1000);
				OCR1A=175;
				_delay_ms(1000);
				OCR1A=65;
				srand(time(0));
				c=(rand()%5+1)*6;
				for(int i=65;i<=300;i++)
				{
					OCR1A=i;
					for(int j=0;j<=c;j++)
					{
						_delay_ms(1);
					}
					if(i==220)
					{
						OCR1A=300;
						_delay_ms(1000);
						break;
					}
				}
				PORTA=0X0A;
				_delay_ms(2000);
				PORTA=0X05;
				_delay_ms(2000);
				PORTA=0x00;
				break;
				
				
				case 4:
				mode++;
				OCR1A=65;
				_delay_ms(1000);
				OCR1A=300;
				_delay_ms(2000);
				srand(time(0));
				c=(rand()%5+1)*6;
				for(int i=300;i<=170;i++)
				{
					OCR1A=i;
					for(int j=0;j<=c;j++)
					{
						_delay_ms(1);
					}
				}
				for(int i=170;i<=300;i++)
				{
					OCR1A=i;
					for(int j=0;j<=c;j++)
					{
						_delay_ms(1);
					}
				}
				_delay_ms(1000);
				OCR1A=65;
				break;
				
				case 5:
				mode++;
				OCR1A=65;
				_delay_ms(500);
				OCR1A=170;
				_delay_ms(500);
				OCR1A=65;
				_delay_ms(500);
				OCR1A=170;
				_delay_ms(500);
				OCR1A=65;
				_delay_ms(500);
				OCR1A=170;
				_delay_ms(500);
				OCR1A=65;
				_delay_ms(500);
				OCR1A=300;
				_delay_ms(500);
				break;
				
				
				case 6:
				mode++;
				OCR1A=65;
				_delay_ms(1000);
				OCR1A=300;
				PORTA=0X0A;
				_delay_ms(2000);
				PORTA=0X05;
				_delay_ms(2000);
				PORTA=0X0A;
				_delay_ms(2000);
				PORTA=0X05;
				_delay_ms(2000);
				PORTA=0X0A;
				_delay_ms(2000);
				PORTA=0X05;
				_delay_ms(2000);
				PORTA=0x00;
				break;
			}
			
/*		OCR1A = 65;	// Set servo shaft at -90° position 
		_delay_ms(1500);
		//OCR1A = 150;	// Set servo shaft at 0° position 
		//_delay_ms(1500);
		OCR1A = 300;	// Set servo at +90° position 
		_delay_ms(3000);
		*/
		}
		}
	}
}