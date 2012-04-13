/* ctors and dtors arrays -- to be used by runtime system */
/*   to call static constructors and destructors          */
/*                                                        */
/* NOTE: Use a C compiler to compile this file. If you    */
/*       are using GNU C++, be sure to use compile this   */
/*       file using a GNU compiler with the               */
/*       -fdollars-in-identifiers flag.                   */


void _STI__07__diab_atomic_init();

void _STI__15__Locksyslock();

void _STI__15__frameinfo_add();

void _STI___12_iostream_cpp_3a72482d();

void _STI___10_locale_cpp_e467b151();

void _STI___11_locale0_cpp_36e19383();

void _STI___11_wlocale_cpp_e1d2c606();

void _STI___11_xlocale_cpp_f40ec04b();

void _STI___10_xstart_cpp__Atexit();

extern void (*_ctors[])();
void (*_ctors[])() =
    {
    _STI__07__diab_atomic_init,
    _STI__15__Locksyslock,
    _STI__15__frameinfo_add,
    _STI___12_iostream_cpp_3a72482d,
    _STI___10_locale_cpp_e467b151,
    _STI___11_locale0_cpp_36e19383,
    _STI___11_wlocale_cpp_e1d2c606,
    _STI___11_xlocale_cpp_f40ec04b,
    _STI___10_xstart_cpp__Atexit,
    0
    };

void _STD__15__Locksyslock();

void _STD__15__frameinfo_add();

void _STD__needed_destruction_list();

void _GLOBAL__D_0___gthread_once();

extern void (*_dtors[])();
void (*_dtors[])() =
    {
    _STD__15__Locksyslock,
    _STD__15__frameinfo_add,
    _STD__needed_destruction_list,
    _GLOBAL__D_0___gthread_once,
    0
    };

#include <vxWorks.h>
#include <config.h>

/* build variables */
#if defined(INCLUDE_LOADER) || defined(INCLUDE_WDB)
#ifdef __GNUC__
__asm("	.section \".wrs_build_vars\",\"a\"");
#endif
#ifdef __DCC__
__asm("	.section \".wrs_build_vars\",\"r\"");
#endif
__asm("	.global _wrs_build_vars");
__asm("	.global _wrs_build_vars_end");
__asm("_wrs_build_vars:");
#else
#ifdef __GNUC__
__asm("	.section \".wrs_build_vars\"");
#endif
#ifdef __DCC__
__asm("	.section \".wrs_build_vars\",\"n\"");
#endif
#endif
__asm("	.ascii \"set WIND_HOME D:/Programas/WindRiver\"");
__asm("	.byte 0");
__asm("	.ascii \"set WIND_BASE $(WIND_HOME)/vxworks-6.8\"");
__asm("	.byte 0");
__asm("	.ascii \"set PRJ_FULL_PATH D:/Documentos/STR/workspace/STR\"");
__asm("	.byte 0");
__asm("	.ascii \"set VSB_DIR $(WIND_BASE)/target/lib\"");
__asm("	.byte 0");
__asm("	.ascii \"set BSP_DIR $(WIND_BASE)/target/config/simpc\"");
__asm("	.byte 0");
__asm("	.ascii \"set ANALYSIS_DKM_DIR $(VSB_DIR)/simpc/SIMNT/common/dkm/analysis\"");
__asm("	.byte 0");
__asm(" .ascii \"tag SMP 0\"");
__asm(" .byte 0");
__asm(" .ascii \"assert $(SMP)==0\"");
__asm(" .byte 0");
#if defined(INCLUDE_LOADER) || defined(INCLUDE_WDB)
__asm("_wrs_build_vars_end:");
#endif
__asm("	.ascii \"end\"");
__asm("	.byte 0");
__asm("	.previous");
