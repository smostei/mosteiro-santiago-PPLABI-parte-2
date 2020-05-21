################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/color.c \
../src/main.c \
../src/mascota.c \
../src/menu.c \
../src/servicio.c \
../src/stringutils.c \
../src/tipo.c \
../src/trabajo.c 

OBJS += \
./src/color.o \
./src/main.o \
./src/mascota.o \
./src/menu.o \
./src/servicio.o \
./src/stringutils.o \
./src/tipo.o \
./src/trabajo.o 

C_DEPS += \
./src/color.d \
./src/main.d \
./src/mascota.d \
./src/menu.d \
./src/servicio.d \
./src/stringutils.d \
./src/tipo.d \
./src/trabajo.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


