/******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for LCD driver
 *
 * Author: Malek Mahmmoud
 *
 *******************************************************************************/
#include "LCD.h"
#include "gpio.h"
#include <stdlib.h>
#include <avr/delay.h>

void LCD_sendCommand (uint8 command)
{
	GPIO_writePin(CONTROL_PORT, RS_PIN, LOGIC_LOW);
	GPIO_writePin(CONTROL_PORT, RW_PIN,LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(CONTROL_PORT, E_PIN,LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(DATA_BUS_PORT, command);
	_delay_ms(1);
	GPIO_writePin(CONTROL_PORT, E_PIN,LOGIC_LOW);
	_delay_ms(1);
}
void LCD_init(void)
{
	GPIO_setupPinDirection(CONTROL_PORT,RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(CONTROL_PORT,RW_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(CONTROL_PORT,E_PIN,PIN_OUTPUT);
	GPIO_setupPortDirection(DATA_BUS_PORT, PORT_OUTPUT);
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_sendCharacter (char data)
{
	GPIO_writePin(CONTROL_PORT, RS_PIN, LOGIC_HIGH);
	GPIO_writePin(CONTROL_PORT, RW_PIN, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(CONTROL_PORT, E_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(DATA_BUS_PORT, data);
	_delay_ms(1);
	GPIO_writePin(CONTROL_PORT, E_PIN, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayString (const char *str)
{
	uint8 counter=0;
	while( (*(str+counter)) != '\0')
	{
		LCD_sendCharacter(*(str+counter));
		counter++;
	}
}
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 LCD_mermory_address;
	switch(row)
	{
	case 0:
		LCD_mermory_address = col;
		break;
	case 1:
		LCD_mermory_address = 0x40+col;
		break;
	case 2:
		LCD_mermory_address = 0x10+col;
		break;
	case 3:
		LCD_mermory_address = 0x50+col;
		break;
	}

	LCD_sendCommand( LCD_mermory_address | LCD_SET_CURSOR_LOCATION);
}
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *str)
{
	LCD_moveCursor(row,col);
	LCD_displayString(str);
}
void LCD_clearSCreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}
void LCD_integerToString(int data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_displayString(buff);

}
