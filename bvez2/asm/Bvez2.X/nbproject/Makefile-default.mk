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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Bvez2.c ../Bvez2Int.c ../Timer_Int.c ../SorosMod232.c ../SorosModNet.c ../OraKorr.c ../GyorsGra.c ../Sflash16M.c ../TextStr.c ../ScrA1.c ../ScrA2.c ../Lcd.c ../ScrA3.c ../ScrA4.c ../ScrA5.c ../ScrA6.c ../ScrA7.c ../ScrA8.c ../ScrH1.c ../ScrH2.c ../ScrH3.c ../ScrS10.c ../ScrS1.c ../ScrS2.c ../ScrS3.c ../ScrS4.c ../ScrS5.c ../ScrS6.c ../ScrS7.c ../ScrS8.c ../ScrS9.c ../ScrS11.c ../Bfls.c ../CardRead.c ../Printer.c ../RsSzint.c ../ScrA9.c ../ScrA10.c ../asmFlash.s ../ScrA0.c ../ScrAstop.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/Bvez2.o ${OBJECTDIR}/_ext/1472/Bvez2Int.o ${OBJECTDIR}/_ext/1472/Timer_Int.o ${OBJECTDIR}/_ext/1472/SorosMod232.o ${OBJECTDIR}/_ext/1472/SorosModNet.o ${OBJECTDIR}/_ext/1472/OraKorr.o ${OBJECTDIR}/_ext/1472/GyorsGra.o ${OBJECTDIR}/_ext/1472/Sflash16M.o ${OBJECTDIR}/_ext/1472/TextStr.o ${OBJECTDIR}/_ext/1472/ScrA1.o ${OBJECTDIR}/_ext/1472/ScrA2.o ${OBJECTDIR}/_ext/1472/Lcd.o ${OBJECTDIR}/_ext/1472/ScrA3.o ${OBJECTDIR}/_ext/1472/ScrA4.o ${OBJECTDIR}/_ext/1472/ScrA5.o ${OBJECTDIR}/_ext/1472/ScrA6.o ${OBJECTDIR}/_ext/1472/ScrA7.o ${OBJECTDIR}/_ext/1472/ScrA8.o ${OBJECTDIR}/_ext/1472/ScrH1.o ${OBJECTDIR}/_ext/1472/ScrH2.o ${OBJECTDIR}/_ext/1472/ScrH3.o ${OBJECTDIR}/_ext/1472/ScrS10.o ${OBJECTDIR}/_ext/1472/ScrS1.o ${OBJECTDIR}/_ext/1472/ScrS2.o ${OBJECTDIR}/_ext/1472/ScrS3.o ${OBJECTDIR}/_ext/1472/ScrS4.o ${OBJECTDIR}/_ext/1472/ScrS5.o ${OBJECTDIR}/_ext/1472/ScrS6.o ${OBJECTDIR}/_ext/1472/ScrS7.o ${OBJECTDIR}/_ext/1472/ScrS8.o ${OBJECTDIR}/_ext/1472/ScrS9.o ${OBJECTDIR}/_ext/1472/ScrS11.o ${OBJECTDIR}/_ext/1472/Bfls.o ${OBJECTDIR}/_ext/1472/CardRead.o ${OBJECTDIR}/_ext/1472/Printer.o ${OBJECTDIR}/_ext/1472/RsSzint.o ${OBJECTDIR}/_ext/1472/ScrA9.o ${OBJECTDIR}/_ext/1472/ScrA10.o ${OBJECTDIR}/_ext/1472/asmFlash.o ${OBJECTDIR}/_ext/1472/ScrA0.o ${OBJECTDIR}/_ext/1472/ScrAstop.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/Bvez2.o.d ${OBJECTDIR}/_ext/1472/Bvez2Int.o.d ${OBJECTDIR}/_ext/1472/Timer_Int.o.d ${OBJECTDIR}/_ext/1472/SorosMod232.o.d ${OBJECTDIR}/_ext/1472/SorosModNet.o.d ${OBJECTDIR}/_ext/1472/OraKorr.o.d ${OBJECTDIR}/_ext/1472/GyorsGra.o.d ${OBJECTDIR}/_ext/1472/Sflash16M.o.d ${OBJECTDIR}/_ext/1472/TextStr.o.d ${OBJECTDIR}/_ext/1472/ScrA1.o.d ${OBJECTDIR}/_ext/1472/ScrA2.o.d ${OBJECTDIR}/_ext/1472/Lcd.o.d ${OBJECTDIR}/_ext/1472/ScrA3.o.d ${OBJECTDIR}/_ext/1472/ScrA4.o.d ${OBJECTDIR}/_ext/1472/ScrA5.o.d ${OBJECTDIR}/_ext/1472/ScrA6.o.d ${OBJECTDIR}/_ext/1472/ScrA7.o.d ${OBJECTDIR}/_ext/1472/ScrA8.o.d ${OBJECTDIR}/_ext/1472/ScrH1.o.d ${OBJECTDIR}/_ext/1472/ScrH2.o.d ${OBJECTDIR}/_ext/1472/ScrH3.o.d ${OBJECTDIR}/_ext/1472/ScrS10.o.d ${OBJECTDIR}/_ext/1472/ScrS1.o.d ${OBJECTDIR}/_ext/1472/ScrS2.o.d ${OBJECTDIR}/_ext/1472/ScrS3.o.d ${OBJECTDIR}/_ext/1472/ScrS4.o.d ${OBJECTDIR}/_ext/1472/ScrS5.o.d ${OBJECTDIR}/_ext/1472/ScrS6.o.d ${OBJECTDIR}/_ext/1472/ScrS7.o.d ${OBJECTDIR}/_ext/1472/ScrS8.o.d ${OBJECTDIR}/_ext/1472/ScrS9.o.d ${OBJECTDIR}/_ext/1472/ScrS11.o.d ${OBJECTDIR}/_ext/1472/Bfls.o.d ${OBJECTDIR}/_ext/1472/CardRead.o.d ${OBJECTDIR}/_ext/1472/Printer.o.d ${OBJECTDIR}/_ext/1472/RsSzint.o.d ${OBJECTDIR}/_ext/1472/ScrA9.o.d ${OBJECTDIR}/_ext/1472/ScrA10.o.d ${OBJECTDIR}/_ext/1472/asmFlash.o.d ${OBJECTDIR}/_ext/1472/ScrA0.o.d ${OBJECTDIR}/_ext/1472/ScrAstop.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Bvez2.o ${OBJECTDIR}/_ext/1472/Bvez2Int.o ${OBJECTDIR}/_ext/1472/Timer_Int.o ${OBJECTDIR}/_ext/1472/SorosMod232.o ${OBJECTDIR}/_ext/1472/SorosModNet.o ${OBJECTDIR}/_ext/1472/OraKorr.o ${OBJECTDIR}/_ext/1472/GyorsGra.o ${OBJECTDIR}/_ext/1472/Sflash16M.o ${OBJECTDIR}/_ext/1472/TextStr.o ${OBJECTDIR}/_ext/1472/ScrA1.o ${OBJECTDIR}/_ext/1472/ScrA2.o ${OBJECTDIR}/_ext/1472/Lcd.o ${OBJECTDIR}/_ext/1472/ScrA3.o ${OBJECTDIR}/_ext/1472/ScrA4.o ${OBJECTDIR}/_ext/1472/ScrA5.o ${OBJECTDIR}/_ext/1472/ScrA6.o ${OBJECTDIR}/_ext/1472/ScrA7.o ${OBJECTDIR}/_ext/1472/ScrA8.o ${OBJECTDIR}/_ext/1472/ScrH1.o ${OBJECTDIR}/_ext/1472/ScrH2.o ${OBJECTDIR}/_ext/1472/ScrH3.o ${OBJECTDIR}/_ext/1472/ScrS10.o ${OBJECTDIR}/_ext/1472/ScrS1.o ${OBJECTDIR}/_ext/1472/ScrS2.o ${OBJECTDIR}/_ext/1472/ScrS3.o ${OBJECTDIR}/_ext/1472/ScrS4.o ${OBJECTDIR}/_ext/1472/ScrS5.o ${OBJECTDIR}/_ext/1472/ScrS6.o ${OBJECTDIR}/_ext/1472/ScrS7.o ${OBJECTDIR}/_ext/1472/ScrS8.o ${OBJECTDIR}/_ext/1472/ScrS9.o ${OBJECTDIR}/_ext/1472/ScrS11.o ${OBJECTDIR}/_ext/1472/Bfls.o ${OBJECTDIR}/_ext/1472/CardRead.o ${OBJECTDIR}/_ext/1472/Printer.o ${OBJECTDIR}/_ext/1472/RsSzint.o ${OBJECTDIR}/_ext/1472/ScrA9.o ${OBJECTDIR}/_ext/1472/ScrA10.o ${OBJECTDIR}/_ext/1472/asmFlash.o ${OBJECTDIR}/_ext/1472/ScrA0.o ${OBJECTDIR}/_ext/1472/ScrAstop.o

# Source Files
SOURCEFILES=../Bvez2.c ../Bvez2Int.c ../Timer_Int.c ../SorosMod232.c ../SorosModNet.c ../OraKorr.c ../GyorsGra.c ../Sflash16M.c ../TextStr.c ../ScrA1.c ../ScrA2.c ../Lcd.c ../ScrA3.c ../ScrA4.c ../ScrA5.c ../ScrA6.c ../ScrA7.c ../ScrA8.c ../ScrH1.c ../ScrH2.c ../ScrH3.c ../ScrS10.c ../ScrS1.c ../ScrS2.c ../ScrS3.c ../ScrS4.c ../ScrS5.c ../ScrS6.c ../ScrS7.c ../ScrS8.c ../ScrS9.c ../ScrS11.c ../Bfls.c ../CardRead.c ../Printer.c ../RsSzint.c ../ScrA9.c ../ScrA10.c ../asmFlash.s ../ScrA0.c ../ScrAstop.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128GP708A
MP_LINKER_FILE_OPTION=,--script=p33FJ128GP708A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Bvez2.o: ../Bvez2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bvez2.c  -o ${OBJECTDIR}/_ext/1472/Bvez2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bvez2.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bvez2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Bvez2Int.o: ../Bvez2Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2Int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bvez2Int.c  -o ${OBJECTDIR}/_ext/1472/Bvez2Int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bvez2Int.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bvez2Int.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Timer_Int.o: ../Timer_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer_Int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer_Int.c  -o ${OBJECTDIR}/_ext/1472/Timer_Int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Timer_Int.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Timer_Int.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SorosMod232.o: ../SorosMod232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosMod232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosMod232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SorosMod232.c  -o ${OBJECTDIR}/_ext/1472/SorosMod232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SorosMod232.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SorosMod232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SorosModNet.o: ../SorosModNet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosModNet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosModNet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SorosModNet.c  -o ${OBJECTDIR}/_ext/1472/SorosModNet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SorosModNet.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SorosModNet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/OraKorr.o: ../OraKorr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OraKorr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OraKorr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../OraKorr.c  -o ${OBJECTDIR}/_ext/1472/OraKorr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/OraKorr.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/OraKorr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GyorsGra.o: ../GyorsGra.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GyorsGra.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GyorsGra.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GyorsGra.c  -o ${OBJECTDIR}/_ext/1472/GyorsGra.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GyorsGra.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GyorsGra.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Sflash16M.o: ../Sflash16M.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Sflash16M.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Sflash16M.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sflash16M.c  -o ${OBJECTDIR}/_ext/1472/Sflash16M.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Sflash16M.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Sflash16M.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/TextStr.o: ../TextStr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TextStr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TextStr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../TextStr.c  -o ${OBJECTDIR}/_ext/1472/TextStr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/TextStr.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TextStr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA1.o: ../ScrA1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA1.c  -o ${OBJECTDIR}/_ext/1472/ScrA1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA1.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA2.o: ../ScrA2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA2.c  -o ${OBJECTDIR}/_ext/1472/ScrA2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA2.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Lcd.o: ../Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Lcd.c  -o ${OBJECTDIR}/_ext/1472/Lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Lcd.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA3.o: ../ScrA3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA3.c  -o ${OBJECTDIR}/_ext/1472/ScrA3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA3.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA4.o: ../ScrA4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA4.c  -o ${OBJECTDIR}/_ext/1472/ScrA4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA4.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA5.o: ../ScrA5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA5.c  -o ${OBJECTDIR}/_ext/1472/ScrA5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA5.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA6.o: ../ScrA6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA6.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA6.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA6.c  -o ${OBJECTDIR}/_ext/1472/ScrA6.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA6.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA6.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA7.o: ../ScrA7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA7.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA7.c  -o ${OBJECTDIR}/_ext/1472/ScrA7.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA7.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA7.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA8.o: ../ScrA8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA8.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA8.c  -o ${OBJECTDIR}/_ext/1472/ScrA8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA8.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH1.o: ../ScrH1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH1.c  -o ${OBJECTDIR}/_ext/1472/ScrH1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH1.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH2.o: ../ScrH2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH2.c  -o ${OBJECTDIR}/_ext/1472/ScrH2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH2.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH3.o: ../ScrH3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH3.c  -o ${OBJECTDIR}/_ext/1472/ScrH3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH3.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS10.o: ../ScrS10.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS10.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS10.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS10.c  -o ${OBJECTDIR}/_ext/1472/ScrS10.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS10.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS10.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS1.o: ../ScrS1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS1.c  -o ${OBJECTDIR}/_ext/1472/ScrS1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS1.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS2.o: ../ScrS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS2.c  -o ${OBJECTDIR}/_ext/1472/ScrS2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS2.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS3.o: ../ScrS3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS3.c  -o ${OBJECTDIR}/_ext/1472/ScrS3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS3.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS4.o: ../ScrS4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS4.c  -o ${OBJECTDIR}/_ext/1472/ScrS4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS4.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS5.o: ../ScrS5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS5.c  -o ${OBJECTDIR}/_ext/1472/ScrS5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS5.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS6.o: ../ScrS6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS6.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS6.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS6.c  -o ${OBJECTDIR}/_ext/1472/ScrS6.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS6.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS6.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS7.o: ../ScrS7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS7.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS7.c  -o ${OBJECTDIR}/_ext/1472/ScrS7.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS7.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS7.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS8.o: ../ScrS8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS8.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS8.c  -o ${OBJECTDIR}/_ext/1472/ScrS8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS8.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS9.o: ../ScrS9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS9.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS9.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS9.c  -o ${OBJECTDIR}/_ext/1472/ScrS9.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS9.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS9.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS11.o: ../ScrS11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS11.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS11.c  -o ${OBJECTDIR}/_ext/1472/ScrS11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS11.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS11.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Bfls.o: ../Bfls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bfls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bfls.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bfls.c  -o ${OBJECTDIR}/_ext/1472/Bfls.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bfls.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bfls.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CardRead.o: ../CardRead.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CardRead.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CardRead.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CardRead.c  -o ${OBJECTDIR}/_ext/1472/CardRead.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CardRead.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CardRead.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Printer.o: ../Printer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Printer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Printer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Printer.c  -o ${OBJECTDIR}/_ext/1472/Printer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Printer.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Printer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/RsSzint.o: ../RsSzint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/RsSzint.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/RsSzint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RsSzint.c  -o ${OBJECTDIR}/_ext/1472/RsSzint.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/RsSzint.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/RsSzint.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA9.o: ../ScrA9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA9.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA9.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA9.c  -o ${OBJECTDIR}/_ext/1472/ScrA9.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA9.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA9.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA10.o: ../ScrA10.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA10.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA10.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA10.c  -o ${OBJECTDIR}/_ext/1472/ScrA10.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA10.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA10.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA0.o: ../ScrA0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA0.c  -o ${OBJECTDIR}/_ext/1472/ScrA0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA0.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA0.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrAstop.o: ../ScrAstop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrAstop.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrAstop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrAstop.c  -o ${OBJECTDIR}/_ext/1472/ScrAstop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrAstop.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrAstop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1472/Bvez2.o: ../Bvez2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bvez2.c  -o ${OBJECTDIR}/_ext/1472/Bvez2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bvez2.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bvez2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Bvez2Int.o: ../Bvez2Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bvez2Int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bvez2Int.c  -o ${OBJECTDIR}/_ext/1472/Bvez2Int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bvez2Int.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bvez2Int.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Timer_Int.o: ../Timer_Int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer_Int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer_Int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Timer_Int.c  -o ${OBJECTDIR}/_ext/1472/Timer_Int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Timer_Int.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Timer_Int.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SorosMod232.o: ../SorosMod232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosMod232.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosMod232.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SorosMod232.c  -o ${OBJECTDIR}/_ext/1472/SorosMod232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SorosMod232.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SorosMod232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/SorosModNet.o: ../SorosModNet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosModNet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SorosModNet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../SorosModNet.c  -o ${OBJECTDIR}/_ext/1472/SorosModNet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/SorosModNet.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SorosModNet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/OraKorr.o: ../OraKorr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/OraKorr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/OraKorr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../OraKorr.c  -o ${OBJECTDIR}/_ext/1472/OraKorr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/OraKorr.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/OraKorr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/GyorsGra.o: ../GyorsGra.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GyorsGra.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GyorsGra.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../GyorsGra.c  -o ${OBJECTDIR}/_ext/1472/GyorsGra.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/GyorsGra.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GyorsGra.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Sflash16M.o: ../Sflash16M.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Sflash16M.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Sflash16M.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Sflash16M.c  -o ${OBJECTDIR}/_ext/1472/Sflash16M.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Sflash16M.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Sflash16M.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/TextStr.o: ../TextStr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/TextStr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/TextStr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../TextStr.c  -o ${OBJECTDIR}/_ext/1472/TextStr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/TextStr.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/TextStr.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA1.o: ../ScrA1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA1.c  -o ${OBJECTDIR}/_ext/1472/ScrA1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA1.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA2.o: ../ScrA2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA2.c  -o ${OBJECTDIR}/_ext/1472/ScrA2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA2.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Lcd.o: ../Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Lcd.c  -o ${OBJECTDIR}/_ext/1472/Lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Lcd.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Lcd.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA3.o: ../ScrA3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA3.c  -o ${OBJECTDIR}/_ext/1472/ScrA3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA3.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA4.o: ../ScrA4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA4.c  -o ${OBJECTDIR}/_ext/1472/ScrA4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA4.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA5.o: ../ScrA5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA5.c  -o ${OBJECTDIR}/_ext/1472/ScrA5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA5.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA6.o: ../ScrA6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA6.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA6.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA6.c  -o ${OBJECTDIR}/_ext/1472/ScrA6.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA6.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA6.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA7.o: ../ScrA7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA7.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA7.c  -o ${OBJECTDIR}/_ext/1472/ScrA7.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA7.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA7.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA8.o: ../ScrA8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA8.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA8.c  -o ${OBJECTDIR}/_ext/1472/ScrA8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA8.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH1.o: ../ScrH1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH1.c  -o ${OBJECTDIR}/_ext/1472/ScrH1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH1.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH2.o: ../ScrH2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH2.c  -o ${OBJECTDIR}/_ext/1472/ScrH2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH2.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrH3.o: ../ScrH3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrH3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrH3.c  -o ${OBJECTDIR}/_ext/1472/ScrH3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrH3.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrH3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS10.o: ../ScrS10.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS10.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS10.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS10.c  -o ${OBJECTDIR}/_ext/1472/ScrS10.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS10.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS10.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS1.o: ../ScrS1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS1.c  -o ${OBJECTDIR}/_ext/1472/ScrS1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS1.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS2.o: ../ScrS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS2.c  -o ${OBJECTDIR}/_ext/1472/ScrS2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS2.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS3.o: ../ScrS3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS3.c  -o ${OBJECTDIR}/_ext/1472/ScrS3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS3.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS4.o: ../ScrS4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS4.c  -o ${OBJECTDIR}/_ext/1472/ScrS4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS4.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS5.o: ../ScrS5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS5.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS5.c  -o ${OBJECTDIR}/_ext/1472/ScrS5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS5.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS5.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS6.o: ../ScrS6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS6.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS6.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS6.c  -o ${OBJECTDIR}/_ext/1472/ScrS6.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS6.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS6.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS7.o: ../ScrS7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS7.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS7.c  -o ${OBJECTDIR}/_ext/1472/ScrS7.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS7.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS7.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS8.o: ../ScrS8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS8.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS8.c  -o ${OBJECTDIR}/_ext/1472/ScrS8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS8.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS9.o: ../ScrS9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS9.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS9.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS9.c  -o ${OBJECTDIR}/_ext/1472/ScrS9.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS9.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS9.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrS11.o: ../ScrS11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrS11.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrS11.c  -o ${OBJECTDIR}/_ext/1472/ScrS11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrS11.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrS11.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Bfls.o: ../Bfls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Bfls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Bfls.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Bfls.c  -o ${OBJECTDIR}/_ext/1472/Bfls.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Bfls.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Bfls.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/CardRead.o: ../CardRead.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CardRead.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CardRead.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CardRead.c  -o ${OBJECTDIR}/_ext/1472/CardRead.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/CardRead.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CardRead.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/Printer.o: ../Printer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Printer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Printer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Printer.c  -o ${OBJECTDIR}/_ext/1472/Printer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Printer.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Printer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/RsSzint.o: ../RsSzint.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/RsSzint.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/RsSzint.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../RsSzint.c  -o ${OBJECTDIR}/_ext/1472/RsSzint.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/RsSzint.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/RsSzint.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA9.o: ../ScrA9.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA9.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA9.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA9.c  -o ${OBJECTDIR}/_ext/1472/ScrA9.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA9.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA9.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA10.o: ../ScrA10.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA10.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA10.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA10.c  -o ${OBJECTDIR}/_ext/1472/ScrA10.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA10.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA10.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrA0.o: ../ScrA0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA0.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrA0.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrA0.c  -o ${OBJECTDIR}/_ext/1472/ScrA0.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrA0.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrA0.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/ScrAstop.o: ../ScrAstop.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrAstop.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ScrAstop.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ScrAstop.c  -o ${OBJECTDIR}/_ext/1472/ScrAstop.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/ScrAstop.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mlarge-code -mlarge-data -mlarge-scalar -mconst-in-code -O0 -I".." -msmart-io=0 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/ScrAstop.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/asmFlash.o: ../asmFlash.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/asmFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/asmFlash.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../asmFlash.s  -o ${OBJECTDIR}/_ext/1472/asmFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I".." -Wa,-MD,"${OBJECTDIR}/_ext/1472/asmFlash.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax,-g$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/asmFlash.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1472/asmFlash.o: ../asmFlash.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/asmFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/asmFlash.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../asmFlash.s  -o ${OBJECTDIR}/_ext/1472/asmFlash.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -I".." -Wa,-MD,"${OBJECTDIR}/_ext/1472/asmFlash.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax,-g$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/asmFlash.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--no-pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="${DISTDIR}/Bvez2.X.${IMAGE_TYPE}.map",--report-mem,--cref,--warn-section-align,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--no-pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="..",--no-force-link,--smart-io,-Map="${DISTDIR}/Bvez2.X.${IMAGE_TYPE}.map",--report-mem,--cref,--warn-section-align,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Bvez2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
