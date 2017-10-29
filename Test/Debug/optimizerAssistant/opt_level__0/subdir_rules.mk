################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
adc.obj: ../adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="adc.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

calc.obj: ../calc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="calc.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

io.obj: ../io.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="io.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

lcd.obj: ../lcd.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="lcd.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system.obj: ../system.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="system.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: ../timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted -O0 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="timer.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


