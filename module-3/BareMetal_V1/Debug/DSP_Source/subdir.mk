################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Source/mac.c

OBJS += \
./DSP_Source/mac.o 

# Each subdirectory must supply rules for building sources it contributes
DSP_Source/%.o: ../DSP_Source/%.c
	@echo 'Building file: $^'
	@echo 'Invoking: ARM-GCC C Compiler'
	$(CC) $(CFLAGS) $(INCLUDEFLAGS) -c -o $@ $^  
	@echo 'Finished building: $^'

