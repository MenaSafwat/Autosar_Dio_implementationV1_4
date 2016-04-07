/*
 * Det.h
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

#ifndef DET_H_
#define DET_H_


#define DIO_READCHANNEL_ID 0x00
#define DIO_WRITECHANNEL_ID 0x01
#define DIO_READPORT_ID 0x02
#define DIO_WRITEPORT_ID 0x03
#define DIO_READCHANNELGROUP_ID 0x04
#define DIO_WRITECHANNELGROUP_ID 0x05
#define DIO_INIT_ID 0x10
#define DIO_GETVERSIONINFO_ID 0x12
#define DIO_FlipChannel_ID 0x11

extern FUNC(Std_ReturnType,DIO_MEM_CLASS) Det_ReportError( VAR(uint16,AUTOMATIC) ModuleId,\
		VAR(uint8,AUTOMATIC) InstanceId, VAR(uint8,AUTOMATIC) ApiId, VAR(uint8,AUTOMATIC) ErrorId);


#endif /* DET_H_ */
