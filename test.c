#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
volatile int flag1=0;
volatile int flag2=0;
volatile int flag3=0;

int main(void)
{
DDRD&=~(1<<2);
PORTD|=(1<<2);
DDRD&=~(1<<3);
PORTD|=(1<<3);
DDRB&=~(1<<0);
PORTB|=(1<<0);
DDRB|=(1<<PB2);
DDRB|=(1<<PB1);
DDRB|=(1<<PB3);
 EICRA|=(1<<ISC00);
 EICRA|=(1<<ISC10);
 PCICR|=(1<<PCIE0);  // Insert code
EIMSK|=(1<<INT0);
EIMSK|=(1<<INT1);
PCMSK0|=(1<<PCINT0);
sei();

    while(1)
    {
        if(flag1==1)
               {
            PORTB|=(1<<2);
             flag1=0;
            _delay_ms(100);

        }
        else
            {
            PORTB&=~(1<<2);
             _delay_ms(100);

        }


                if(flag2==1)
               {
            PORTB|=(1<<1);
             flag2=0;
            _delay_ms(100);

        }
        else
            {
            PORTB&=~(1<<1);
             _delay_ms(100);

        }
                        if(flag3==1)
               {
            PORTB|=(1<<3);
             flag3=0;
            _delay_ms(100);

        }
        else
            {
            PORTB&=~(1<<3);
             _delay_ms(100);

        }
    }

    return 0;
}
ISR(INT0_vect)
{
    flag1=1;

}
ISR(INT1_vect)
{
    flag2=1;

}
ISR(PCINT0_vect)
{
    flag3=1;
}
