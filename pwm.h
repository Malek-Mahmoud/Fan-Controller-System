 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Malek Mahmoud Mohammmed
 *
 *******************************************************************************/
#ifndef PWM_H_
#define PWM_H_
/*******************************************************************************
 *                            Includes Libraries                               *
 *******************************************************************************/
#include"std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DUTY_CYCLE_RESOLUTION 256
#define MAX_PERCENTAGE_DUTY_CYCLE 100
/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed be update the value in
 * The Compare Register
 */
void Timer0_PWM_Init(uint8 set_duty_cycle);

#endif /* PWM_H_ */
