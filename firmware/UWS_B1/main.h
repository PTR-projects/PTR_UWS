/*
 * main.h
 *
 * Created: 2017-11-15 14:59:52
 *  Author: bartekm
 */ 


#ifndef MAIN_H_
#define MAIN_H_

void adc_init(void);



uint16_t adc_read();
uint16_t bat_read();
uint8_t pulse_calc(uint16_t bat);
void bat_blink(uint8_t level);
void timer_init();
void inline LED_ON();
void inline LED_OFF();
#endif /* MAIN_H_ */
