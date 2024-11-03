################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Uart_Lib/uart_lib.c 

OBJS += \
./Uart_Lib/uart_lib.o 

C_DEPS += \
./Uart_Lib/uart_lib.d 


# Each subdirectory must supply rules for building sources it contributes
Uart_Lib/%.o Uart_Lib/%.su Uart_Lib/%.cyclo: ../Uart_Lib/%.c Uart_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ASUS/STM32CubeIDE/workspace_1.16.1/Uart_lib/Uart_Lib" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Uart_Lib

clean-Uart_Lib:
	-$(RM) ./Uart_Lib/uart_lib.cyclo ./Uart_Lib/uart_lib.d ./Uart_Lib/uart_lib.o ./Uart_Lib/uart_lib.su

.PHONY: clean-Uart_Lib

