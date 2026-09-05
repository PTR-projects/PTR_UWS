/*
 * testerADC.c
 *
 * Created: 2017-11-15 14:25:49
 * Author : bartekm
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "main.h"


void adc_init() {
    // Set the ADC input to PB2/ADC1
    ADMUX = (1 << MUX0);	//PB2
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
    return (uint16_t)(63744UL/(ADC>>2));	//napiêcie x100 -> 3.74V = 375
	ADCSRA |= (1 << ADSC);
}

uint8_t pulse_calc(uint16_t bat) {
    if(bat <= 320) return 0;
    else if(bat <= 340) return 1;
    else if(bat <= 360) return 2;
    else if(bat <= 380) return 3;
    else if(bat <= 390) return 4;
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



inline void LED_ON() {
	PORTB &= ~(1 << PB3);
}

inline void LED_OFF() {
    PORTB |= (1 << PB3);
}

int main(void) {
    DDRB |= (1 << PB3);	//PB3 wyjœcie; PB - LED
	DDRB |= (1 << PB4);	
	PORTB &= ~(1 << PB4);	
	LED_OFF();
	
	
	uint16_t bat_volt = 0;
	uint8_t bat_lvl = 0;
	adc_init();
		
    while (1) {
		
// 		uint8_t tmp = adc_read();
// 		if(tmp <800){
// 			while(1){
// 				LED_ON();
// 				_delay_ms(100);
// 				LED_OFF();
// 				_delay_ms(100);
// 			}
// 		}
 		bat_volt = bat_read();
 		bat_lvl = pulse_calc(bat_volt);
 		bat_blink(bat_lvl);
		 _delay_ms(5000);
    }
}

