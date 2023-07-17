################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Sources/5.\ Project/Glove_Sender/Sources/subdir.mk
-include Sources/4.Applicaton/subdir.mk
-include Sources/2.ECUAL/LCD/Sources/subdir.mk
-include Sources/1.MCAL/UART/Sources/subdir.mk
-include Sources/1.MCAL/Timer0/Sources/subdir.mk
-include Sources/1.MCAL/GINT/Sources/subdir.mk
-include Sources/1.MCAL/EXTINT/Sources/subdir.mk
-include Sources/1.MCAL/DIO/Sources/subdir.mk
-include Sources/1.MCAL/ADC/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
R.E.M.lss \
R.E.M.lss \

FLASH_IMAGE += \
R.E.M.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: R.E.M.elf secondary-outputs

# Tool invocations
R.E.M.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,R.E.M.map -mmcu=atmega32 -o "R.E.M.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

R.E.M.lss: R.E.M.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S R.E.M.elf  >"R.E.M.lss"
	@echo 'Finished building: $@'
	@echo ' '

R.E.M.hex: R.E.M.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex R.E.M.elf  "R.E.M.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: R.E.M.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 R.E.M.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) R.E.M.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
