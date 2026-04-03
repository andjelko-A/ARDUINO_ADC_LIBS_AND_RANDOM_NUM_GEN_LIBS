################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc_utils.c \
../logic_utils.c \
../main.c \
../pin.c \
../pulsing.c \
../rand_otm.c \
../timer0.c \
../utils.c 

OBJS += \
./adc_utils.o \
./logic_utils.o \
./main.o \
./pin.o \
./pulsing.o \
./rand_otm.o \
./timer0.o \
./utils.o 

C_DEPS += \
./adc_utils.d \
./logic_utils.d \
./main.d \
./pin.d \
./pulsing.d \
./rand_otm.d \
./timer0.d \
./utils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


