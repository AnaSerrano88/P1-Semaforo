#include <avr/io.h>
#include <util/delay.h>
 
#define BLINK_DELAY_MS 5000
 
int main (void)
{
 /* set pin 5 of PORTB for output*/
 DDRB |= _BV(DDB5); //Rojo  (13)
 DDRB |= _BV(DDB4); //Amarillo (12)
 DDRB |= _BV(DDB3); //Verde (11)
 DDRB |= _BV(DDB0); //Verde Usuario (8)
 DDRB |= _BV(DDB1); //Rojo Usuario (9)

 while(1) {
  
 PORTB |= _BV(PORTB5);
 PORTB |= _BV(PORTB0);
 PORTB &= ~_BV(PORT1);
 PORTB &= ~_BV(PORT3);
 _delay_ms(BLINK_DELAY_MS);
 PORTB &= ~_BV(PORT5);
 PORTB &= ~_BV(PORT0);
 PORTB |= _BV(PORTB4);
 PORTB |= _BV(PORTB1);
 _delay_ms(BLINK_DELAY_MS);
 PORTB |= _BV(PORTB3);
 PORTB &= ~_BV(PORT4);
 _delay_ms(BLINK_DELAY_MS);
  
 }
}
//avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o semaforo.o semaforo.c
//avr-gcc -mmcu=atmega328p semaforo.o -o semaforo
//avr-objcopy -O ihex -R .eeprom semaforo semaforo.hex
//sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:semaforo.hex
