#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include"dcmotor.h"
#include "std_types.h"
#include "avr/io.h"

int main (void)
{
	uint8 temp;
	Adc_configType Adc_config= {INTERNAL,RIGHT_ADJUST,INTERRUPT_OFF,PRESCALER_8};

	LCD_init();
	ADC_init(&Adc_config);
	DcMotor_Init();

	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");

	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");
	while(1)
	{
		temp = LM35_getTemperature();
		LCD_moveCursor(1,10);

		if(temp >= 100)
		{
			LCD_integerToString(temp);
		}
		else
		{
			LCD_integerToString(temp);
			LCD_sendCharacter(' ');
		}

		if(temp < 30)
		{
			DcMotor_Rotate(STOP_ROTATION,SPEED_0);
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			LCD_sendCharacter(' ');
		}
		else if(temp >= 30 && temp < 60)
		{
			DcMotor_Rotate(CW_ROTATION,SPEED_25);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_sendCharacter(' ');
		}
		else if(temp >= 60 && temp < 90)
		{
			DcMotor_Rotate(CW_ROTATION,SPEED_50);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_sendCharacter(' ');
		}
		else if(temp >= 90 && temp < 120)
		{
			DcMotor_Rotate(CW_ROTATION,SPEED_75);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_sendCharacter(' ');
		}
		else if(temp >= 120)
		{
			DcMotor_Rotate(CW_ROTATION,SPEED_100);
			LCD_moveCursor(0,10);
			LCD_displayString("ON");
			LCD_sendCharacter(' ');
		}
	}
	return 0;
}
