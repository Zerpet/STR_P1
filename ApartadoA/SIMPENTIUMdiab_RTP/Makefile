# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMPENTIUMdiab_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := D:/Documentos/STR/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ApartadoA



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpentium
CPU = SIMPENTIUM
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:rtpsim
LIBPATH = 
LIBS = -lstlstd
VSB_DIR = $(WIND_BASE)/target/lib

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO 
DEBUGFLAGS_C++-Compiler = -XO 
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO 
endif


#Project Targets
PROJECT_TARGETS = ApartadoA/$(MODE_DIR)/ApartadoA.vxe


#Rules

# ApartadoA
ifeq ($(DEBUG_MODE),1)
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ApartadoA/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO 
endif
ApartadoA/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
ApartadoA/$(MODE_DIR)/% : IDE_LIBRARIES = 
ApartadoA/$(MODE_DIR)/% : PROJECT_TYPE = RTP
ApartadoA/$(MODE_DIR)/% : DEFINES = 
ApartadoA/$(MODE_DIR)/% : DO_STRIP = 0
ApartadoA/$(MODE_DIR)/% : EXPAND_DBG = 0
ApartadoA/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
ApartadoA/$(MODE_DIR)/% : CPU = SIMPENTIUM
ApartadoA/$(MODE_DIR)/% : TOOL_FAMILY = diab
ApartadoA/$(MODE_DIR)/% : TOOL = diab
ApartadoA/$(MODE_DIR)/% : TOOL_PATH = 
ApartadoA/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:rtpsim
ApartadoA/$(MODE_DIR)/% : LIBPATH = 
ApartadoA/$(MODE_DIR)/% : LIBS = -lstlstd
ApartadoA/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
ApartadoA/$(MODE_DIR)/% : OBJ_DIR := ApartadoA/$(MODE_DIR)

ApartadoA/$(MODE_DIR)/Objects/ApartadoA/controladorA.o : $(PRJ_ROOT_DIR)/controladorA.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


ApartadoA/$(MODE_DIR)/Objects/ApartadoA/displayA.o : $(PRJ_ROOT_DIR)/displayA.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_ApartadoA = ApartadoA/$(MODE_DIR)/Objects/ApartadoA/controladorA.o \
	 ApartadoA/$(MODE_DIR)/Objects/ApartadoA/displayA.o

ApartadoA/$(MODE_DIR)/ApartadoA.vxe : $(OBJECTS_ApartadoA)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dplus $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd -f 0x90,1,1 -o "$@" $(OBJECTS_ApartadoA) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS)   && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

ApartadoA/$(MODE_DIR)/ApartadoA_compile_file : $(FILE) ;

_clean :: ApartadoA/$(MODE_DIR)/ApartadoA_clean

ApartadoA/$(MODE_DIR)/ApartadoA_clean : 
	$(TRACE_FLAG)if [ -d "ApartadoA" ]; then cd "ApartadoA"; rm -rf $(MODE_DIR); fi

DEP_FILES := ApartadoA/$(MODE_DIR)/Objects/ApartadoA/controladorA.d ApartadoA/$(MODE_DIR)/Objects/ApartadoA/displayA.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
