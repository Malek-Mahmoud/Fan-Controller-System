 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/*******************************************************************************
 *                             External Variables                              *
 *******************************************************************************/
/* Extern Public global variables to be used by other modules */
extern volatile uint16 g_adcResult;
/*******************************************************************************
 *                             Types Declaration                               *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC=0X40,INTERNAL=0XC0
}Adc_refVoltage;

typedef enum
{
	RIGHT_ADJUST,LEFT_ADJUST
}Adc_dataRepresentation;

typedef enum
{
	CHANNEL_0,CHANNEL_1,CHANNEL_2,CHANNEL_3,CHANNEL_4,CHANNEL_5,CHANNEL_6,CHANNEL_7
}Adc_Channel;

typedef enum
{
	INTERRUPT_OFF,INTERRUPT_ON
}Adc_interruptState;

typedef enum
{
	PRESCALER_2,PRESCALER_4=2,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128
}Adc_prescaler;

typedef struct
{
	Adc_refVoltage ref_voltage;
	Adc_dataRepresentation data_adjust;
	Adc_interruptState interrupt_state;
	Adc_prescaler prescaler;
}Adc_configType;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define ADC_INTERRUPT_STATE  FULSE
/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC driver
 * 	1. select the reference voltage
 * 	2. select data adjust representation
 * 	3. select the required prescaler
 * 	4. enable the module
 */
void ADC_init(const Adc_configType * config_PTr);

/*
 * Description: function to read the selected channel using polling technique.
 */
uint16 ADC_readChannel(uint8 ch_num);

/*
 * Description: function to read the selected channel using interrupt technique.
 */
void ADC_readChannelWithInterrupt (uint8 ch_num);

#endif /* ADC_H_ */
