#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Relay.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/server.o \
	${OBJECTDIR}/wiringPi/drcSerial.o \
	${OBJECTDIR}/wiringPi/max31855.o \
	${OBJECTDIR}/wiringPi/max5322.o \
	${OBJECTDIR}/wiringPi/mcp23008.o \
	${OBJECTDIR}/wiringPi/mcp23016.o \
	${OBJECTDIR}/wiringPi/mcp23017.o \
	${OBJECTDIR}/wiringPi/mcp23s08.o \
	${OBJECTDIR}/wiringPi/mcp23s17.o \
	${OBJECTDIR}/wiringPi/mcp3002.o \
	${OBJECTDIR}/wiringPi/mcp3004.o \
	${OBJECTDIR}/wiringPi/mcp3422.o \
	${OBJECTDIR}/wiringPi/mcp4802.o \
	${OBJECTDIR}/wiringPi/pcf8574.o \
	${OBJECTDIR}/wiringPi/pcf8591.o \
	${OBJECTDIR}/wiringPi/piHiPri.o \
	${OBJECTDIR}/wiringPi/piThread.o \
	${OBJECTDIR}/wiringPi/sn3218.o \
	${OBJECTDIR}/wiringPi/softPwm.o \
	${OBJECTDIR}/wiringPi/softServo.o \
	${OBJECTDIR}/wiringPi/softTone.o \
	${OBJECTDIR}/wiringPi/sr595.o \
	${OBJECTDIR}/wiringPi/wiringPi.o \
	${OBJECTDIR}/wiringPi/wiringPiI2C.o \
	${OBJECTDIR}/wiringPi/wiringPiSPI.o \
	${OBJECTDIR}/wiringPi/wiringSerial.o \
	${OBJECTDIR}/wiringPi/wiringShift.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eaglemon

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eaglemon: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/eaglemon ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Relay.o: Relay.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Relay.o Relay.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/server.o: server.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/server.o server.cpp

${OBJECTDIR}/wiringPi/drcSerial.o: wiringPi/drcSerial.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/drcSerial.o wiringPi/drcSerial.c

${OBJECTDIR}/wiringPi/max31855.o: wiringPi/max31855.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/max31855.o wiringPi/max31855.c

${OBJECTDIR}/wiringPi/max5322.o: wiringPi/max5322.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/max5322.o wiringPi/max5322.c

${OBJECTDIR}/wiringPi/mcp23008.o: wiringPi/mcp23008.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp23008.o wiringPi/mcp23008.c

${OBJECTDIR}/wiringPi/mcp23016.o: wiringPi/mcp23016.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp23016.o wiringPi/mcp23016.c

${OBJECTDIR}/wiringPi/mcp23017.o: wiringPi/mcp23017.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp23017.o wiringPi/mcp23017.c

${OBJECTDIR}/wiringPi/mcp23s08.o: wiringPi/mcp23s08.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp23s08.o wiringPi/mcp23s08.c

${OBJECTDIR}/wiringPi/mcp23s17.o: wiringPi/mcp23s17.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp23s17.o wiringPi/mcp23s17.c

${OBJECTDIR}/wiringPi/mcp3002.o: wiringPi/mcp3002.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp3002.o wiringPi/mcp3002.c

${OBJECTDIR}/wiringPi/mcp3004.o: wiringPi/mcp3004.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp3004.o wiringPi/mcp3004.c

${OBJECTDIR}/wiringPi/mcp3422.o: wiringPi/mcp3422.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp3422.o wiringPi/mcp3422.c

${OBJECTDIR}/wiringPi/mcp4802.o: wiringPi/mcp4802.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/mcp4802.o wiringPi/mcp4802.c

${OBJECTDIR}/wiringPi/pcf8574.o: wiringPi/pcf8574.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/pcf8574.o wiringPi/pcf8574.c

${OBJECTDIR}/wiringPi/pcf8591.o: wiringPi/pcf8591.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/pcf8591.o wiringPi/pcf8591.c

${OBJECTDIR}/wiringPi/piHiPri.o: wiringPi/piHiPri.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/piHiPri.o wiringPi/piHiPri.c

${OBJECTDIR}/wiringPi/piThread.o: wiringPi/piThread.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/piThread.o wiringPi/piThread.c

${OBJECTDIR}/wiringPi/sn3218.o: wiringPi/sn3218.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/sn3218.o wiringPi/sn3218.c

${OBJECTDIR}/wiringPi/softPwm.o: wiringPi/softPwm.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/softPwm.o wiringPi/softPwm.c

${OBJECTDIR}/wiringPi/softServo.o: wiringPi/softServo.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/softServo.o wiringPi/softServo.c

${OBJECTDIR}/wiringPi/softTone.o: wiringPi/softTone.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/softTone.o wiringPi/softTone.c

${OBJECTDIR}/wiringPi/sr595.o: wiringPi/sr595.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/sr595.o wiringPi/sr595.c

${OBJECTDIR}/wiringPi/wiringPi.o: wiringPi/wiringPi.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/wiringPi.o wiringPi/wiringPi.c

${OBJECTDIR}/wiringPi/wiringPiI2C.o: wiringPi/wiringPiI2C.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/wiringPiI2C.o wiringPi/wiringPiI2C.c

${OBJECTDIR}/wiringPi/wiringPiSPI.o: wiringPi/wiringPiSPI.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/wiringPiSPI.o wiringPi/wiringPiSPI.c

${OBJECTDIR}/wiringPi/wiringSerial.o: wiringPi/wiringSerial.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/wiringSerial.o wiringPi/wiringSerial.c

${OBJECTDIR}/wiringPi/wiringShift.o: wiringPi/wiringShift.c
	${MKDIR} -p ${OBJECTDIR}/wiringPi
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/wiringPi/wiringShift.o wiringPi/wiringShift.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
