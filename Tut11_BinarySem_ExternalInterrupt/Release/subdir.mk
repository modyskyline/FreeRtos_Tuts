################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../croutine.c \
../heap_1.c \
../init_external_interrupt.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../tasks.c \
../timers.c \
../usart.c 

OBJS += \
./croutine.o \
./heap_1.o \
./init_external_interrupt.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./tasks.o \
./timers.o \
./usart.o 

C_DEPS += \
./croutine.d \
./heap_1.d \
./init_external_interrupt.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./tasks.d \
./timers.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


