 /******************************************************************************
 *
 * Module:
 *
 * File Name: .c
 *
 * Description: Source file for the AVR ... driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/

#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use ADC Registers */
#include <avr/interrupt.h> /* For ADC ISR */

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
volatile uint16 g_adcResult = 0;
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC driver
 * 	1. select the reference voltage
 * 	2. select data adjust representation
 * 	3. select the required prescaler
 *  4. select the interrupt state.
 * 	4. enable the module.
 */
void ADC_init(const Adc_configType * config_PTr)
{
	ADMUX  = (ADMUX & 0X3F)  | (config_PTr->ref_voltage);
	ADMUX  = (ADMUX & 0XDf)  | ((config_PTr->data_adjust)<<5);
	ADCSRA = (ADCSRA & 0XF8) | (config_PTr->prescaler);
	ADCSRA = (ADCSRA & 0XF7) | ((config_PTr->interrupt_state)<<3);
	SET_BIT(ADCSRA,ADEN);
}

/*
 * Description: function to read the selected channel using polling technique.
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	ADMUX   = (ADMUX & 0XE0) |(ch_num & 0X07);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

/*
 * Description: function to read the selected channel using interrupt technique.
 */
void ADC_readChannelWithInterrupt (uint8 ch_num)
{
	ADMUX = (ADMUX & 0XE0) | (ch_num & 0X07);
	SET_BIT(ADCSRA,ADSC);
}
