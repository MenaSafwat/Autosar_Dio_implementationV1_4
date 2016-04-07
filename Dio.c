/*
 * Dio.c
 *
 *  Created on: Mar 25, 2016
 *      Author: Mena Safwat
 */

/*************************includes***********************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Std_Types.h"
#include "Det.h"
#include "common_macros.h"
#include "Dio.h"
/**********************global variables declaration*******************/
STATIC VAR(uint8,AUTOMATIC)Dio_init_flag=false;
STATIC volatile P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ptr_to_channel_group_cfg;
STATIC volatile P2CONST(Dio_channel_ConfigType,AUTOMATIC,PTR_FAR) ptr_to_channel_cfg;


/********************function definition***********************/

/*****************definition of DIO initialization function*******************
 * copy pointer to array of channel cfg and pointer to array of channel cfg
 * to static global pointers*/
FUNC(void,DIO_MEM_CLASS) Dio_Init( P2CONST(Dio_ConfigType,AUTOMATIC,PTR_FAR) ConfigPtr ){
	if(ConfigPtr!=NULL){
		ptr_to_channel_cfg=ConfigPtr->channel_cfg_ptr;
		#ifdef CHANNEL_GROUP
			ptr_to_channel_group_cfg=ConfigPtr->channel_group_cfg_ptr;
		#endif
		Dio_init_flag=true;
	}
	else{
			#if (1==DIO_DEV_ERROR_DETECT)
				Det_ReportError(1,1,DIO_INIT_ID,1);
			#endif
	}
}
/*****************************DIO read single channel level*****************/
FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_ReadChannel(VAR(Dio_ChannelType,AUTOMATIC)ChannelId ){
	VAR(Dio_LevelType,AUTOMATIC) pin_level;
	P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_pin_register;
	 /* check this channel in which port A, B, C, D*/
	if((true==Dio_init_flag)&&(ChannelId<MAX_CHANNEL_NO)){
				switch(ptr_to_channel_cfg[ChannelId].port_id){
					case DIO_PORT_A:
						ptr_to_pin_register=&PINA;
						break;
					case DIO_PORT_B:
						ptr_to_pin_register=&PINB;
						break;
					case DIO_PORT_C:
						ptr_to_pin_register=&PINC;
						break;
					case DIO_PORT_D:
						ptr_to_pin_register=&PIND;
						break;
				}
				if(BIT_IS_SET(*ptr_to_pin_register,ptr_to_channel_cfg[ChannelId].pin_num)){
					pin_level=STD_HIGH;
				}
				else if(BIT_IS_CLEAR(*ptr_to_pin_register,ptr_to_channel_cfg[ChannelId].pin_num)){
					pin_level=STD_LOW;
				}
				return pin_level;
			}
	else{
			#if (1==DIO_DEV_ERROR_DETECT)
				Det_ReportError(1,1,DIO_READCHANNEL_ID,1);
			#endif
		}
}

FUNC(void,DIO_MEM_CLASS) Dio_WriteChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId,VAR(Dio_LevelType,AUTOMATIC) Level ){
	P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_port_register;
	/* check this channel in which port A, B, C, D*/
	if(true==Dio_init_flag&&(ChannelId<MAX_CHANNEL_NO)){
				switch(ptr_to_channel_cfg[ChannelId].port_id){
					case DIO_PORT_A:
						ptr_to_port_register=&PORTA;
						break;
					case DIO_PORT_B:
						ptr_to_port_register=&PORTB;
						break;
					case DIO_PORT_C:
						ptr_to_port_register=&PORTC;
						break;
					case DIO_PORT_D:
						ptr_to_port_register=&PORTD;
						break;
				}
				if(STD_HIGH==Level){
					SET_BIT(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num);
				}
				else if(STD_LOW==Level){
					CLEAR_BIT(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num);
				}
			}
			else{
					#if (1==DIO_DEV_ERROR_DETECT)
						Det_ReportError(1,1,DIO_WRITECHANNEL_ID,1);
					#endif
			}
}
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadPort( VAR(Dio_PortType,AUTOMATIC) PortId ){
	if(true==Dio_init_flag){
				P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_pin_register;
					switch(PortId){
						case DIO_PORT_A:
							ptr_to_pin_register=&PINA;
							break;
						case DIO_PORT_B:
							ptr_to_pin_register=&PINB;
							break;
						case DIO_PORT_C:
							ptr_to_pin_register=&PINC;
							break;
						case DIO_PORT_D:
							ptr_to_pin_register=&PIND;
							break;
						default :
							#if (1==DIO_DEV_ERROR_DETECT)
								Det_ReportError(1,1,DIO_READPORT_ID,1);
							#endif
							break;
					}
					return *ptr_to_pin_register;
			}
		else{
				#if (1==DIO_DEV_ERROR_DETECT)
						Det_ReportError(1,1,DIO_READPORT_ID,1);
				#endif
		}
}
FUNC(void,DIO_MEM_CLASS) Dio_WritePort( VAR(Dio_PortType,AUTOMATIC) PortId, VAR(Dio_PortLevelType,AUTOMATIC) Level )
{
	if(true==Dio_init_flag){
				P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_port_register;
					switch(PortId){
						case DIO_PORT_A:
							ptr_to_port_register=&PORTA;
							break;
						case DIO_PORT_B:
							ptr_to_port_register=&PORTB;
							break;
						case DIO_PORT_C:
							ptr_to_port_register=&PORTC;
							break;
						case DIO_PORT_D:
							ptr_to_port_register=&PORTD;
							break;
						default :
							#if (1==DIO_DEV_ERROR_DETECT)
							Det_ReportError(1,1,DIO_WRITEPORT_ID,1);
							#endif
							break;
					}
					*ptr_to_port_register=Level;
			}
		else{
				#if (1==DIO_DEV_ERROR_DETECT)
						Det_ReportError(1,1,DIO_WRITEPORT_ID,1);
				#endif
		}

}
#ifdef CHANNEL_GROUP
FUNC(Dio_PortLevelType,DIO_MEM_CLASS) Dio_ReadChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr )
{
	P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_pin_register;
	VAR(bool,AUTOMATIC) error_flag=false;
	if((true==Dio_init_flag)&&(ChannelGroupIdPtr!=NULL)){
					switch(ChannelGroupIdPtr->port){
						case DIO_PORT_A:
								ptr_to_pin_register=&PINA;
						break;
						case DIO_PORT_B:
								ptr_to_pin_register=&PINB;
						break;
					    case DIO_PORT_C:
						     	ptr_to_pin_register=&PINC;
						break;
						case DIO_PORT_D:
								ptr_to_pin_register=&PIND;
					    break;
						default :
								error_flag=true;
						break;
					}
					return ((*ptr_to_pin_register&ChannelGroupIdPtr->mask)>>ChannelGroupIdPtr->offset);
			}
		else{
				error_flag=true;
		}
	if(true==error_flag){
				#if (1==DIO_DEV_ERROR_DETECT)
						Det_ReportError(1,1,DIO_READCHANNELGROUP_ID,1);
				#endif
	}
}

FUNC(void,DIO_MEM_CLASS) Dio_WriteChannelGroup( P2CONST(Dio_ChannelGroupType,AUTOMATIC,PTR_FAR) ChannelGroupIdPtr, VAR(Dio_PortLevelType,AUTOMATIC) Level )
{
	VAR(uint8,AUTOMATIC) error_flag=false;
	P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_port_register;
	     if((true==Dio_init_flag)&&(ChannelGroupIdPtr!=NULL)){
	    						switch(ChannelGroupIdPtr->port){
	    							case DIO_PORT_A:
	  									ptr_to_port_register=&PORTA;
	    							break;
	   								case DIO_PORT_B:
	    								ptr_to_port_register=&PORTB;
	    							break;
	    							case DIO_PORT_C:
	    								ptr_to_port_register=&PORTC;
	    							break;
	    							case DIO_PORT_D:
	    									ptr_to_port_register=&PORTD;
	    							break;
	    							default :
	    									error_flag=true;
	    							break;
	    							}
	    		Level=(ChannelGroupIdPtr->mask)&(Level<<(ChannelGroupIdPtr->offset));
	    		*ptr_to_port_register &=(~ChannelGroupIdPtr->mask);
	    		*ptr_to_port_register |=Level;
			}
			else{
					error_flag=true;
			}
	     if(true==error_flag){
					#if (1==DIO_DEV_ERROR_DETECT)
							Det_ReportError(1,1,1,DIO_WRITECHANNELGROUP_ID);
					#endif
	     }
}
#endif
FUNC(void,DIO_MEM_CLASS) Dio_GetVersionInfo( P2VAR(Std_VersionInfoType,AUTOMATIC,PTR_FAR) VersionInfo ){
           VersionInfo->moduleID=1;
           VersionInfo->sw_major_version=1;
           VersionInfo->sw_minor_version=1;
           VersionInfo->sw_patch_version=1;
           VersionInfo->vendorID=5;
}


FUNC(Dio_LevelType,DIO_MEM_CLASS) Dio_FlipChannel( VAR(Dio_ChannelType,AUTOMATIC) ChannelId )
{
	VAR(Dio_LevelType,AUTOMATIC) level;
	P2VAR(uint8,AUTOMATIC,PTR_FAR) ptr_to_port_register;
	if((true==Dio_init_flag)&&(ChannelId<MAX_CHANNEL_NO)){
					switch(ptr_to_channel_cfg[ChannelId].port_id){
						case DIO_PORT_A:
							ptr_to_port_register=&PORTA;
							break;
						case DIO_PORT_B:
							ptr_to_port_register=&PORTB;
							break;
						case DIO_PORT_C:
							ptr_to_port_register=&PORTC;
							break;
						case DIO_PORT_D:
							ptr_to_port_register=&PORTD;
							break;
					}
					if(BIT_IS_CLEAR(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num)){
						SET_BIT(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num);
						level=STD_HIGH;
					}
					else if(BIT_IS_SET(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num)){
						CLEAR_BIT(*ptr_to_port_register,ptr_to_channel_cfg[ChannelId].pin_num);
						level=STD_LOW;
					}
			}
		else{
				#if (1==DIO_DEV_ERROR_DETECT)
						Det_ReportError(1,1,DIO_FlipChannel_ID,1);
				#endif
		}
}
