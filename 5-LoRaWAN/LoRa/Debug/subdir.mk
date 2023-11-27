################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CRC16.c \
../DIO.c \
../SLIP.c \
../UART.c \
../WiMOD_HCI_Layer.c \
../WiMOD_LoRaWAN_API.c \
../delay.c \
../lcd.c \
../main.c 

OBJS += \
./CRC16.o \
./DIO.o \
./SLIP.o \
./UART.o \
./WiMOD_HCI_Layer.o \
./WiMOD_LoRaWAN_API.o \
./delay.o \
./lcd.o \
./main.o 

C_DEPS += \
./CRC16.d \
./DIO.d \
./SLIP.d \
./UART.d \
./WiMOD_HCI_Layer.d \
./WiMOD_LoRaWAN_API.d \
./delay.d \
./lcd.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


