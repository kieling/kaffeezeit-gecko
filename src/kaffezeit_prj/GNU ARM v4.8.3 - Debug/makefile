################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed/TARGET_EFM32GG_STK3700/TOOLCHAIN_GCC_ARM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: mbed_blinky.axf

# Tool invocations
mbed_blinky.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\efm32gg.ld" -L"C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM" -Wl,--wrap=main --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="mbed_blinky.map" --specs=nano.specs -o mbed_blinky.axf "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\board.o" "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\cmsis_nvic.o" "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\mbed_overrides.o" "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\retarget.o" "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\startup_efm32gg.o" "C:\Users\vitor\Downloads\mbed_blinky\mbed\TARGET_EFM32GG_STK3700\TOOLCHAIN_GCC_ARM\system_efm32gg.o" "./LogType.o" "./MFRC522.o" "./User.o" "./main.o" "-lstdc++" "-lsupc++" "-lm" "-lnosys" "-lc" "-lgcc" "-lmbed" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: mbed_blinky.hex'
	arm-none-eabi-objcopy -O ihex "mbed_blinky.axf" "mbed_blinky.hex"
	@echo ' '

	@echo 'Building bin file: mbed_blinky.bin'
	arm-none-eabi-objcopy -O binary "mbed_blinky.axf" "mbed_blinky.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "mbed_blinky.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) mbed_blinky.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
