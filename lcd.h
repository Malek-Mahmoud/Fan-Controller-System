 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for LCD driver
 *
 * Author: Malek Mahmmud
 *
 *******************************************************************************/
#ifndef LCD_H_
#define LCD_H_
#include"std_types.h"
/* LCD Commands */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80

#define CONTROL_PORT   PORTD_ID
#define RS_PIN         PIN0_ID
#define RW_PIN         PIN1_ID
#define E_PIN		   PIN2_ID
#define DATA_BUS_PORT  PORTC_ID

void LCD_init (void);
void LCD_sendCommand   (uint8 command);
void LCD_sendCharacter (char data);
void LCD_displayString (const char *str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *str);
void LCD_clearSCreen(void);
void LCD_integerToString(int data);
#endif /* LCD_H_ */
