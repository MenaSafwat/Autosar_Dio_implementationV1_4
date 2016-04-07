/*
 * Dio_PBcfg.c
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

/********************************INCLUDES**********************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Dio_PBcfg.h"


/********define channel configuration for array of structure**********/
const Dio_channel_ConfigType Dio_channel_config[MAX_CHANNEL_NO]={
	/*LED_1*/		{DIO_PORT_A,pin_5},
	/*button_1*/	{DIO_PORT_A,pin_7}
};
/********define channel groups configuration for array of structure**********/
const Dio_ChannelGroupType Dio_channelGroup[MAX_CHANNEL_GROUP]={
		{12,2,DIO_PORT_C},
		{12,2,DIO_PORT_D}
};
/**************define structure for Dio configuration module****************/
Dio_ConfigType Dio_config={&Dio_channelGroup,&Dio_channel_config};
