################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g431rbtx.s 

OBJS += \
./Core/Startup/startup_stm32g431rbtx.o 

S_DEPS += \
./Core/Startup/startup_stm32g431rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"E:/tutorial/STM_G431/STM_G431_UART_TIM/App" -I"E:/tutorial/STM_G431/STM_G431_UART_TIM/App/src" -I"E:/tutorial/STM_G431/STM_G431_UART_TIM/App/include" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g431rbtx.d ./Core/Startup/startup_stm32g431rbtx.o

.PHONY: clean-Core-2f-Startup

