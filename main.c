#include "STD_TYPES.h"
#include <util/delay.h>
#include "PORT_interface.h"
#include "CHAR_LCD_interface.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


void main(void)

{

    PORT_voidInt();

	CHAR_LCD_viodInit();
	CHAR_LCD_viodSendString("Basic Calculator");
	uint8 Copy_u8Num1=0,Local_Reading;
	uint8 Copy_u8Num2=0;
	uint16 Copy_u32FloatNum=0;
	uint16 Copy_u8Value=0;
	uint8 NUM1;
	uint8 OpCount=0;
	uint8 NUM2;
	uint8 Counter=0;
	uint8 Copy_u8Empty[]={
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000,
				0b00000000};

	while(1)
	{
	DIO_u8ReadPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&Local_Reading);
	 if(Local_Reading==1)
	 { _delay_ms(200);
		 Counter++;}
	switch (Counter)
	{
	case 0:  DIO_u8ReadPinValue(DIO_u8_PORTD,DIO_u8_PIN6,&Local_Reading);

		 if(Local_Reading==1)
		{_delay_ms(200);
		Copy_u8Num1=(Copy_u8Num1+1)%10;
		}
		 CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,0,1);
		 _delay_ms(40);
		CHAR_LCD_viodGoToXY(0,1);
		CHAR_LCD_viodSendData(Copy_u8Num1+'0');break;

	case 1:
		DIO_u8ReadPinValue(DIO_u8_PORTD,DIO_u8_PIN6,&Local_Reading);
		if(Local_Reading==1)
		{_delay_ms(200);
			OpCount=OpCount+1;}
	switch (OpCount)
	{
	case 0:CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,1,1);
	 _delay_ms(40);
		CHAR_LCD_viodGoToXY(1,1);
	  CHAR_LCD_viodSendData('+');break;
	case 1:CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,1,1);
	 _delay_ms(40);
		CHAR_LCD_viodGoToXY(1,1);
		  CHAR_LCD_viodSendData('-');break;
	case 2:CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,1,1);
	 _delay_ms(40);
		CHAR_LCD_viodGoToXY(1,1);
		  CHAR_LCD_viodSendData('x');break;
	case 3:CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,1,1);
	 _delay_ms(40);
		CHAR_LCD_viodGoToXY(1,1);
		  CHAR_LCD_viodSendData('/');break;
	default:OpCount=0;}break;

	case 2:  DIO_u8ReadPinValue(DIO_u8_PORTD,DIO_u8_PIN6,&Local_Reading);

			 if(Local_Reading==1)
			{_delay_ms(200);
			Copy_u8Num2=(Copy_u8Num2+1)%10;
			}
			 CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,2,1);
			 		 _delay_ms(40);
			CHAR_LCD_viodGoToXY(2,1);
			CHAR_LCD_viodSendData(Copy_u8Num2+'0');break;

	case 3:
		CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,3,1);
				 _delay_ms(40);
		CHAR_LCD_viodGoToXY(3,1);
		CHAR_LCD_viodSendData('=');

		DIO_u8ReadPinValue(DIO_u8_PORTD,DIO_u8_PIN2,&Local_Reading);
		if(Local_Reading==1)
		{_delay_ms(200);

		 switch (OpCount)
			{case 0:Copy_u8Value=Copy_u8Num1+Copy_u8Num2;
			CHAR_LCD_viodGoToXY(4,1);
			if (Copy_u8Value != 0 && Copy_u8Value>9)
			{ NUM2=Copy_u8Value%10;
			Copy_u8Value=Copy_u8Value/10;
			NUM1=Copy_u8Value%10;
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(NUM1+'0');
			CHAR_LCD_viodGoToXY(5,1);
			CHAR_LCD_viodSendData(NUM2+'0'); }
			else
			{   CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,5,1);
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(Copy_u8Value+'0');
			}break;
			case 1:
			CHAR_LCD_viodGoToXY(4,1);
			if (Copy_u8Num2 > Copy_u8Num1 )
			{Copy_u8Value=Copy_u8Num2-Copy_u8Num1;
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData('-');
			CHAR_LCD_viodGoToXY(5,1);
			CHAR_LCD_viodSendData(Copy_u8Value+'0'); }
			else
			{ Copy_u8Value=Copy_u8Num1-Copy_u8Num2;
			CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,5,1);
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(Copy_u8Value+'0');
			}break;
            case 2:Copy_u8Value=Copy_u8Num1*Copy_u8Num2;
			CHAR_LCD_viodGoToXY(4,1);
			if (Copy_u8Value != 0 && Copy_u8Value>9)
			{ NUM2=Copy_u8Value%10;
			Copy_u8Value=Copy_u8Value/10;
			NUM1=Copy_u8Value%10;
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(NUM1+'0');
			CHAR_LCD_viodGoToXY(5,1);
			CHAR_LCD_viodSendData(NUM2+'0'); }
			else
			{   CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,5,1);
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(Copy_u8Value+'0');
			}break;

        	case 3:CHAR_LCD_viodGoToXY(4,1);
			if (Copy_u8Num2 > Copy_u8Num1 )
			{Copy_u32FloatNum=(Copy_u8Num1*100)/Copy_u8Num2;
            NUM2=Copy_u32FloatNum%10;
			Copy_u32FloatNum=Copy_u32FloatNum/10;
			NUM1=Copy_u32FloatNum%10;
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData('0');
			CHAR_LCD_viodGoToXY(5,1);
			CHAR_LCD_viodSendData('.');
			CHAR_LCD_viodGoToXY(6,1);
			CHAR_LCD_viodSendData(NUM1+'0');
			CHAR_LCD_viodSendData(NUM2+'0');}
			else
			{ if(Copy_u8Num2 !=0)
			{Copy_u32FloatNum=(Copy_u8Num1*10)/Copy_u8Num2;
			NUM2=Copy_u32FloatNum%10;
			Copy_u32FloatNum=Copy_u32FloatNum/10;
			NUM1=Copy_u32FloatNum%10;
			CHAR_LCD_viodGoToXY(4,1);
			CHAR_LCD_viodSendData(NUM1+'0');
			CHAR_LCD_viodGoToXY(5,1);
			CHAR_LCD_viodSendData('.');
			CHAR_LCD_viodGoToXY(6,1);
			CHAR_LCD_viodSendData(NUM2+'0');}
			else
			{   CHAR_LCD_viodGoToXY(7,1);
				CHAR_LCD_viodSendString("Invalid");
				_delay_ms(1000);
				for(uint8 counter=7;counter<=14;counter++)
				CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,counter,1);
			}
			}break;
			default:OpCount=0;} }break;
	case 4: CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,4,1);
	CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,5,1);
	CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,6,1);
	CHAR_LCD_viodSendSpecialChar(Copy_u8Empty,1,7,1);break;
	default:Counter=0;}
	}
}
