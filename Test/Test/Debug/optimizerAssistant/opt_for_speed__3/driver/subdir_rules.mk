################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
driver/adc.obj: ../driver/adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --opt_for_speed=3 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/adc.d" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driver/io.obj: ../driver/io.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --opt_for_speed=3 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/io.d" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driver/lcd.obj: ../driver/lcd.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --opt_for_speed=3 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/lcd.d" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

driver/timer.obj: ../driver/timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --opt_for_speed=3 --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/timer.d" --obj_directory="driver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


