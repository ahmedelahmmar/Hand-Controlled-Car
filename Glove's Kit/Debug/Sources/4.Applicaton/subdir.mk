################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/4.Applicaton/main.c 

OBJS += \
./Sources/4.Applicaton/main.o 

C_DEPS += \
./Sources/4.Applicaton/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/4.Applicaton/%.o: ../Sources/4.Applicaton/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\0.Library" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\ADC" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\5. Project\FlexSensor\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\5. Project\Glove_Sender\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\DIO\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\EXTINT\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\GINT\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\Timer0\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\1.MCAL\UART\Includes" -I"C:\Git Repositories\Glove-Controlled-Car\Glove's Kit\Sources\2.ECUAL\LCD\Include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


