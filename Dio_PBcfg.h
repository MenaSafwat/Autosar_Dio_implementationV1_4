/*
 * Dio_PBcfg.h
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

#ifndef DIO_PBCFG_H_
#define DIO_PBCFG_H_



/***********************DEFINITION*********************/
#define CHANNEL_GROUP
/**define enum hold channelID which represent array of channel cfg array index**/
typedef enum{
	LED_1=0,
	button_1,
	MAX_CHANNEL_NO
}Dio_ChannelType;
/**define enum hold channelID which represent array of channel group cfg array index**/
typedef enum{
	ch_group1=0,
	ch_group2,
	MAX_CHANNEL_GROUP
}DIO_channelgroup_type;

extern const Dio_channel_ConfigType Dio_channel_config[MAX_CHANNEL_NO];
extern const Dio_ChannelGroupType Dio_channelGroup[MAX_CHANNEL_GROUP];
extern Dio_ConfigType Dio_config;
/*************define two channel group for two motors********************/
#define F_B_MOTOR (&Dio_channelGroup[ch_group1])
#define L_R_MOTOR (&Dio_channelGroup[ch_group2])

#endif /* DIO_PBCFG_H_ */
