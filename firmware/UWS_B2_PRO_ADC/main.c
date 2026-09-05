/*
 * testerADC.c
 *
 * Created: 2017-11-15 14:25:49
 * Author : bartekm
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "main.h"

void adc_init() {
    // Set the ADC input to PB2/ADC6
    ADMUX = (1 << REFS1) |  (1 << MUX2) | (1 << MUX1);	//PB2 & 2.2V
    DIDR0 |= (1 << ADC6D);

    //Freerun mode
    ADCSRB = (1 << ADLAR);

    //prescaler 2 + Autotrigger + ADC enable
    ADCSRA =   (1 << ADPS0);
	ADCSRA |= (1 << ADEN);
	_delay_ms(100);
	ADCSRA |= (1 << ADSC);
	_delay_ms(100);
}

uint16_t bat_adc() {
	return (ADCH<<8) | ADCL;	
}

uint16_t bat_read() {
    return (uint16_t)( (740*((ADCH<<8) | ADCL))/1023 );	//dzielnik 1/3, Vref 2.2V, 10bitów
}

uint8_t pulse_calc(uint16_t bat) {
    if(bat <= 3200) return 0;
    else if(bat <= 3700) return 1;
    else if(bat <= 3800) return 2;
    else if(bat <= 3900) return 3;
    else if(bat <= 4000) return 4;
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
            _delay_ms(2000);
        }
    }
}

inline void LED_OFF() {
	PORTB &= ~(1 << PB1);
}

inline void LED_ON() {
    PORTB |= (1 << PB1);
}

int main(void) {
	CCP = 0xD8;
	CLKPSR = 0x05;	//prescales 32 -> 250kHz	
	
    DDRB |= (1 << PB1);	//PB1 wyjœcie; PB - LED
	LED_OFF();
	sei();
	
	uint16_t bat_volt = 0;
	uint8_t bat_lvl = 0;
	_delay_ms(1000);
	adc_init();
		
	uint32_t adc_raw = 0;
	
    while (1) {
		adc_raw = 0;
		
		for(uint16_t i = 0; i<1024; i++){
			ADCSRA |= (1 << ADSC);          // start ADC measurement
			while (ADCSRA & (1 << ADSC) );  // wait till conversion complete
			adc_raw += ADCH;
		}
		adc_raw >>= 8;
		uint16_t vbat = (7486 * adc_raw)/1024;

		bat_blink(pulse_calc(vbat));
		
		_delay_ms(5000);
    }
}

