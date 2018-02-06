################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
handle/calc.obj: ../handle/calc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="C:/Users/huyru/Downloads/Test/driver" --include_path="C:/Users/huyru/Downloads/Test/handle" --include_path="C:/ti/ccsv7/ccs_base/msp430/include" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="handle/calc.d" --obj_directory="handle" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

handle/display.obj: ../handle/display.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="C:/Users/huyru/Downloads/Test/driver" --include_path="C:/Users/huyru/Downloads/Test/handle" --include_path="C:/ti/ccsv7/ccs_base/msp430/include" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="handle/display.d" --obj_directory="handle" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

handle/system.obj: ../handle/system.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx" --include_path="D:/ti/msp/MSP430Ware_3_60_00_10/driverlib/driverlib/MSP430F5xx_6xx/inc" --include_path="C:/Users/huyru/Downloads/Test/driver" --include_path="C:/Users/huyru/Downloads/Test/handle" --include_path="C:/ti/ccsv7/ccs_base/msp430/include" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.1.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="handle/system.d" --obj_directory="handle" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


