################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/buzzer.c \
../HAL/flame.c \
../HAL/lcd.c \
../HAL/ldr.c \
../HAL/led.c \
../HAL/lm35_sensor.c \
../HAL/motor.c 

OBJS += \
./HAL/buzzer.o \
./HAL/flame.o \
./HAL/lcd.o \
./HAL/ldr.o \
./HAL/led.o \
./HAL/lm35_sensor.o \
./HAL/motor.o 

C_DEPS += \
./HAL/buzzer.d \
./HAL/flame.d \
./HAL/lcd.d \
./HAL/ldr.d \
./HAL/led.d \
./HAL/lm35_sensor.d \
./HAL/motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


