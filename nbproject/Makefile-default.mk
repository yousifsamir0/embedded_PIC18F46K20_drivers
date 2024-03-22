#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MBProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MBProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/LED/ecu_led.c MCA_Layer/ADC/hal_adc.c MCA_Layer/EEPROM/hal_eeprom.c MCA_Layer/GPIO/hal_gpio.c MCA_Layer/Interrupt/mcal_external_interrupt.c MCA_Layer/Interrupt/mcal_internal_interrupt.c MCA_Layer/Interrupt/mcal_interrupt_manager.c MCA_Layer/TIMER0/hal_timer0.c MCA_Layer/TIMER1/hal_timer1.c MCA_Layer/TIMER2/hal_timer2.c MCA_Layer/device_config.c Application/application.c MCA_Layer/TIMER3/hal_timer3.c MCA_Layer/USART/hal_usart.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCA_Layer/device_config.p1 ${OBJECTDIR}/Application/application.p1 ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d ${OBJECTDIR}/MCA_Layer/device_config.p1.d ${OBJECTDIR}/Application/application.p1.d ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 ${OBJECTDIR}/MCA_Layer/device_config.p1 ${OBJECTDIR}/Application/application.p1 ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1

# Source Files
SOURCEFILES=ECU_Layer/LED/ecu_led.c MCA_Layer/ADC/hal_adc.c MCA_Layer/EEPROM/hal_eeprom.c MCA_Layer/GPIO/hal_gpio.c MCA_Layer/Interrupt/mcal_external_interrupt.c MCA_Layer/Interrupt/mcal_internal_interrupt.c MCA_Layer/Interrupt/mcal_interrupt_manager.c MCA_Layer/TIMER0/hal_timer0.c MCA_Layer/TIMER1/hal_timer1.c MCA_Layer/TIMER2/hal_timer2.c MCA_Layer/device_config.c Application/application.c MCA_Layer/TIMER3/hal_timer3.c MCA_Layer/USART/hal_usart.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MBProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1: MCA_Layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 MCA_Layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.d ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1: MCA_Layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 MCA_Layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1: MCA_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 MCA_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1: MCA_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 MCA_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1: MCA_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 MCA_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1: MCA_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 MCA_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1: MCA_Layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 MCA_Layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.d ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1: MCA_Layer/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 MCA_Layer/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.d ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1: MCA_Layer/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 MCA_Layer/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.d ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/device_config.p1: MCA_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer" 
	@${RM} ${OBJECTDIR}/MCA_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/device_config.p1 MCA_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/device_config.d ${OBJECTDIR}/MCA_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application/application.p1: Application/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Application" 
	@${RM} ${OBJECTDIR}/Application/application.p1.d 
	@${RM} ${OBJECTDIR}/Application/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application/application.p1 Application/application.c 
	@-${MV} ${OBJECTDIR}/Application/application.d ${OBJECTDIR}/Application/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1: MCA_Layer/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 MCA_Layer/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.d ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1: MCA_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1 MCA_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.d ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1: ECU_Layer/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1 ECU_Layer/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.d ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1: MCA_Layer/ADC/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1 MCA_Layer/ADC/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.d ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/ADC/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1: MCA_Layer/EEPROM/hal_eeprom.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/EEPROM" 
	@${RM} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1 MCA_Layer/EEPROM/hal_eeprom.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.d ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/EEPROM/hal_eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1: MCA_Layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1 MCA_Layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.d ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1: MCA_Layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1 MCA_Layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1: MCA_Layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1 MCA_Layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1: MCA_Layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1 MCA_Layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1: MCA_Layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER0" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1 MCA_Layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.d ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1: MCA_Layer/TIMER1/hal_timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER1" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1 MCA_Layer/TIMER1/hal_timer1.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.d ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER1/hal_timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1: MCA_Layer/TIMER2/hal_timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1 MCA_Layer/TIMER2/hal_timer2.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.d ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER2/hal_timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/device_config.p1: MCA_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer" 
	@${RM} ${OBJECTDIR}/MCA_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/device_config.p1 MCA_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/device_config.d ${OBJECTDIR}/MCA_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application/application.p1: Application/application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Application" 
	@${RM} ${OBJECTDIR}/Application/application.p1.d 
	@${RM} ${OBJECTDIR}/Application/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application/application.p1 Application/application.c 
	@-${MV} ${OBJECTDIR}/Application/application.d ${OBJECTDIR}/Application/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1: MCA_Layer/TIMER3/hal_timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/TIMER3" 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1 MCA_Layer/TIMER3/hal_timer3.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.d ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/TIMER3/hal_timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1: MCA_Layer/USART/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCA_Layer/USART" 
	@${RM} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1 MCA_Layer/USART/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.d ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCA_Layer/USART/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MBProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MBProject.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MBProject.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/MBProject.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/MBProject.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/MBProject.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/MBProject.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
