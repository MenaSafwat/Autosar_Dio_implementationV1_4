
#include "avr/io.h"
#include "Platform_Types.h"
#include "Std_Types.h"
#include "util/delay.h"
#include "common_macros.h"
#include "compiler.h"
#include "Dio.h"

int main()
{
	/*initialize pins as GPIO instead of PORT module*/
	CLEAR_BIT(DDRA,PA7);
	SET_BIT(DDRA,PA5);
	DDRC=0xff;
	DDRD=0xff;
	/*initialize DIO module*/
	Dio_Init(&Dio_config);
	/*test write Channel API*/
	Dio_WriteChannelGroup(L_R_MOTOR,0xff);
	while(1){
		/*test channel flip API*/
		Dio_FlipChannel(LED_1);
			_delay_ms(1000);
			/*test read API check button pressed or not*/
		if(STD_HIGH==Dio_ReadChannel(button_1)){
			/*test write API by turn on LED */
			Dio_WriteChannel(LED_1,STD_HIGH);
			_delay_ms(1000);
			Dio_WriteChannel(LED_1,STD_LOW);
			_delay_ms(1000);
		}
	}
	return 0;
}
