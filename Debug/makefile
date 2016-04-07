################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Autosar_Dio_implementationV1_4.lss \

FLASH_IMAGE += \
Autosar_Dio_implementationV1_4.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Autosar_Dio_implementationV1_4.elf secondary-outputs

# Tool invocations
Autosar_Dio_implementationV1_4.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Autosar_Dio_implementationV1_4.map -mmcu=atmega16 -o "Autosar_Dio_implementationV1_4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Autosar_Dio_implementationV1_4.lss: Autosar_Dio_implementationV1_4.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Autosar_Dio_implementationV1_4.elf  >"Autosar_Dio_implementationV1_4.lss"
	@echo 'Finished building: $@'
	@echo ' '

Autosar_Dio_implementationV1_4.hex: Autosar_Dio_implementationV1_4.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Autosar_Dio_implementationV1_4.elf  "Autosar_Dio_implementationV1_4.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Autosar_Dio_implementationV1_4.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Autosar_Dio_implementationV1_4.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Autosar_Dio_implementationV1_4.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
