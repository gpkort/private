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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/202695825/CargoHold.o \
	${OBJECTDIR}/_ext/202695825/DuarableComponent.o \
	${OBJECTDIR}/_ext/202695825/Engine.o \
	${OBJECTDIR}/_ext/202695825/FuelTank.o \
	${OBJECTDIR}/_ext/202695825/LandingCraft.o \
	${OBJECTDIR}/_ext/202695825/ManueveringComponent.o \
	${OBJECTDIR}/_ext/202695825/Pad.o \
	${OBJECTDIR}/_ext/202695825/ShipComponent.o \
	${OBJECTDIR}/_ext/202695825/Strut.o \
	${OBJECTDIR}/_ext/202695825/Thruster.o \
	${OBJECTDIR}/_ext/202695825/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-static-libgcc -static-libstdc++ -std=c++0x -Weffc++
CXXFLAGS=-static-libgcc -static-libstdc++ -std=c++0x -Weffc++

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/crashpad.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/crashpad.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/crashpad ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/202695825/CargoHold.o: ../../../code/src/CargoHold.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/CargoHold.o ../../../code/src/CargoHold.cpp

${OBJECTDIR}/_ext/202695825/DuarableComponent.o: ../../../code/src/DuarableComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/DuarableComponent.o ../../../code/src/DuarableComponent.cpp

${OBJECTDIR}/_ext/202695825/Engine.o: ../../../code/src/Engine.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/Engine.o ../../../code/src/Engine.cpp

${OBJECTDIR}/_ext/202695825/FuelTank.o: ../../../code/src/FuelTank.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/FuelTank.o ../../../code/src/FuelTank.cpp

${OBJECTDIR}/_ext/202695825/LandingCraft.o: ../../../code/src/LandingCraft.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/LandingCraft.o ../../../code/src/LandingCraft.cpp

${OBJECTDIR}/_ext/202695825/ManueveringComponent.o: ../../../code/src/ManueveringComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/ManueveringComponent.o ../../../code/src/ManueveringComponent.cpp

${OBJECTDIR}/_ext/202695825/Pad.o: ../../../code/src/Pad.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/Pad.o ../../../code/src/Pad.cpp

${OBJECTDIR}/_ext/202695825/ShipComponent.o: ../../../code/src/ShipComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/ShipComponent.o ../../../code/src/ShipComponent.cpp

${OBJECTDIR}/_ext/202695825/Strut.o: ../../../code/src/Strut.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/Strut.o ../../../code/src/Strut.cpp

${OBJECTDIR}/_ext/202695825/Thruster.o: ../../../code/src/Thruster.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/Thruster.o ../../../code/src/Thruster.cpp

${OBJECTDIR}/_ext/202695825/main.o: ../../../code/src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/202695825
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I../../../code/inc -static-libgcc -static-libstdc++ -std=c++0x -Weffc++ -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/202695825/main.o ../../../code/src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/crashpad.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
