/*
 * testerADC.c
 *
 * Created: 2017-11-15 14:25:49
 * Author : bartekm
 */

#include <avr/io.h>
#include <util/delay.h>
//#include <stdlib.h>
#include <avr/interrupt.h>
#include "main.h"

volatile uint8_t bat_trigger = 1;

ISR(TIM0_COMPA_vect){
	bat_trigger = 1;
// 	LED_ON();
// 	_delay_ms(100);
// 	LED_OFF();
}

void adc_init() {
    // Set the ADC input to PB1/ADC1
    ADMUX = (1 << MUX0);	//PB1
    DIDR0 |= (1 << ADC1D);

    //Freerun mode
    ADCSRB = 0x00;

    //prescaler 128 + Atuotrigger + ADC enable
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) | (1 << ADATE);
	ADCSRA |= (1 << ADEN);
	_delay_ms(100);
	ADCSRA |= (1 << ADSC);
	_delay_ms(100);
}

uint16_t adc_read(void) {
    return ADCL;
}

uint16_t bat_read() {
    return (uint16_t)(63744UL/ADCL);	//napiêcie x100 -> 3.74V = 375
}

uint8_t pulse_calc(uint16_t bat) {
    if(bat <= 360) return 0;
    else if(bat <= 370) return 1;
    else if(bat <= 380) return 2;
    else if(bat <= 390) return 3;
    else if(bat <= 400) return 4;
    else return 5;
}

void bat_blink(uint8_t level) {
    if(level) {
        for(uint8_t i = 0; i<level; i++) {
            LED_ON();
            _delay_ms(250);
            LED_OFF();
            _delay_ms(250);
        }
    } else {
        while(1) {
            LED_ON();
            _delay_ms(50);
            LED_OFF();
            _delay_ms(1000);
        }
    }
}

void timer_init() {
    //1MHz
    TCCR0B = (1 << CS02) | (1 << CS00);

    // Set to 'CTC' mode
    TCCR0B |= (1 << WGM02);
	OCR0A = 4882UL;
	
	//przerwanie na compare
    TIMSK0 |= (1 << OCIE0A);
}

inline void LED_ON() {
    PORTB |= (1 << PB0);
}

inline void LED_OFF() {
    PORTB &= ~(1 << PB0);
}

int main(void) {
    DDRB |= (1 << PB0) | (1 << PB2);	//PB0 i PB1 jako wyjœcie; PB0 - LED, PB2 Vref
    PORTB &= ~(1 << PB2);				//w³¹cz Vref

	uint16_t bat_volt = 0;
	uint8_t bat_lvl = 0;
	_delay_ms(1000);
	adc_init();
	timer_init();
	sei();
	
    while (1) {
		if(bat_trigger){
 			bat_trigger = 0;
			 PORTB &= ~(1 << PB2);
			 _delay_ms(10);
 			bat_volt = bat_read();
			 PORTB |= (1 << PB2);
 			bat_lvl = pulse_calc(bat_volt);
 			bat_blink(bat_lvl);
		}
    }
}

