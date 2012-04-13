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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/ApartadoD



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
PROJECT_TARGETS = ApartadoD/$(MODE_DIR)/ApartadoD.vxe


#Rules

# ApartadoD
ifeq ($(DEBUG_MODE),1)
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
ApartadoD/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO 
endif
ApartadoD/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
ApartadoD/$(MODE_DIR)/% : IDE_LIBRARIES = 
ApartadoD/$(MODE_DIR)/% : PROJECT_TYPE = RTP
ApartadoD/$(MODE_DIR)/% : DEFINES = 
ApartadoD/$(MODE_DIR)/% : DO_STRIP = 0
ApartadoD/$(MODE_DIR)/% : EXPAND_DBG = 0
ApartadoD/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
ApartadoD/$(MODE_DIR)/% : CPU = SIMPENTIUM
ApartadoD/$(MODE_DIR)/% : TOOL_FAMILY = diab
ApartadoD/$(MODE_DIR)/% : TOOL = diab
ApartadoD/$(MODE_DIR)/% : TOOL_PATH = 
ApartadoD/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:rtpsim
ApartadoD/$(MODE_DIR)/% : LIBPATH = 
ApartadoD/$(MODE_DIR)/% : LIBS = -lstlstd
ApartadoD/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
ApartadoD/$(MODE_DIR)/% : OBJ_DIR := ApartadoD/$(MODE_DIR)

ApartadoD/$(MODE_DIR)/Objects/ApartadoD/controladorD.o : $(PRJ_ROOT_DIR)/controladorD.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


ApartadoD/$(MODE_DIR)/Objects/ApartadoD/displayD.o : $(PRJ_ROOT_DIR)/displayD.c
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   $(DEFINES) -o "$@" -c "$<"


OBJECTS_ApartadoD = ApartadoD/$(MODE_DIR)/Objects/ApartadoD/controladorD.o \
	 ApartadoD/$(MODE_DIR)/Objects/ApartadoD/displayD.o

ApartadoD/$(MODE_DIR)/ApartadoD.vxe : $(OBJECTS_ApartadoD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dplus $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(WIND_BASE)/target/lib -Xforce-declarations   -Xmake-dependency=0xd -f 0x90,1,1 -o "$@" $(OBJECTS_ApartadoD) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS)   && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

ApartadoD/$(MODE_DIR)/ApartadoD_compile_file : $(FILE) ;

_clean :: ApartadoD/$(MODE_DIR)/ApartadoD_clean

ApartadoD/$(MODE_DIR)/ApartadoD_clean : 
	$(TRACE_FLAG)if [ -d "ApartadoD" ]; then cd "ApartadoD"; rm -rf $(MODE_DIR); fi

DEP_FILES := ApartadoD/$(MODE_DIR)/Objects/ApartadoD/controladorD.d ApartadoD/$(MODE_DIR)/Objects/ApartadoD/displayD.d
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
