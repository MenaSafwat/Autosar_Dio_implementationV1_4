/*
 * Std_Types.h
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#include "Platform_Types.h"
#include "compiler.h"


typedef uint8 Std_ReturnType;
/**define API's return if OK=1 or not OK=0**/
#define E_OK 1
#define E_NOT_OK 0

/*uint8 variable hold port ID(0-3)*/
typedef uint8 Dio_PortType;

/*structure hold group channel information*/
typedef struct{
	uint8 mask;
	uint8 offset;
	Dio_PortType port;
}Dio_ChannelGroupType;


/*These are the possible levels a DIO channel can have (input or output)*/
/*variable hold channel level STD_LOW=0 or STD_HIGH=1 */
typedef uint8 Dio_LevelType;
#define STD_LOW 0
#define STD_HIGH 1
typedef uint8 Dio_PortLevelType;

/*DIO channel configuration */
typedef struct {
	Dio_PortType port_id;
	uint8 pin_num;
}Dio_channel_ConfigType;

/*DIO_configuration structure deceleration*/
typedef struct {
	P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR)   channel_group_cfg_ptr;
	P2CONST(Dio_channel_ConfigType,AUTOMATIC,PTR_FAR) channel_cfg_ptr ;
}Dio_ConfigType;

/*declare structure which hold version type*/
typedef struct{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

#endif /* STD_TYPES_H_ */
