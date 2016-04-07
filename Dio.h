/*
 * Dio.h
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

#ifndef DIO_H_
#define DIO_H_

#include "Dio_Cfg.h"
#include "Dio_PBcfg.h"

/*define null value*/
#define NULL 0

typedef enum{
	pin_0=0,
	pin_1,
	pin_2,
	pin_3,
	pin_4,
	pin_5,
	pin_6,
	pin_7
}pin_id;


typedef enum{
	DIO_PORT_A=0,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D
}port_id;
extern FUNC(void,DIO_MEM_CLASS) Dio_Init(P2CONST(Dio_ConfigType,AUTOMATIC,PTR_FAR) ConfigPtr);
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(VAR(Dio_ChannelType,AUTOMATIC)ChannelId );
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId,VAR(Dio_LevelType,AUTOMATIC) Level );
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort( VAR(Dio_PortType,AUTOMATIC) PortId );
extern FUNC(void,DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType,AUTOMATIC) PortId, VAR(Dio_PortLevelType,AUTOMATIC) Level );
extern FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr );
extern FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level );
extern FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo );
extern FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId );

#endif /* DIO_H_ */
