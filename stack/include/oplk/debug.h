/**
********************************************************************************
\file   debug.h

\brief  Definitions for debugging

The file contains definitions used the debugging.
*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2014, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
Copyright (c) 2013, SYSTEC electronic GmbH
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/

#ifndef _INC_oplk_debug_H_
#define _INC_oplk_debug_H_

//------------------------------------------------------------------------------
// includes
//------------------------------------------------------------------------------
#include <oplk/oplkinc.h>

//------------------------------------------------------------------------------
// const defines
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// These definitions are important for level-debug traces.
// A macro DEBUG_GLB_LVL defines the current debug-level using following bis.
// If the corresponding bit is set then trace message will be printed out
// (only if NDEBUG is not defined). The upper debug-levels are reserved for
// the debug-levels ALWAYS, ERROR and ASSERT.
#define DEBUG_LVL_EDRV                  0x00000001
#define DEBUG_LVL_DLL                   0x00000002
#define DEBUG_LVL_OBD                   0x00000004
#define DEBUG_LVL_NMTK                  0x00000008
#define DEBUG_LVL_NMTCN                 0x00000010
#define DEBUG_LVL_NMTU                  0x00000020
#define DEBUG_LVL_NMTMN                 0x00000040
#define DEBUG_LVL_CFM                   0x00000080
#define DEBUG_LVL_TIMERU                0x00000100
#define DEBUG_LVL_TIMERH                0x00000200

#define DEBUG_LVL_PDO                   0x00800000
#define DEBUG_LVL_SDO                   0x01000000
#define DEBUG_LVL_VETH                  0x02000000
#define DEBUG_LVL_EVENTK                0x04000000
#define DEBUG_LVL_EVENTU                0x08000000

#define DEBUG_LVL_ASSERT                0x20000000
#define DEBUG_LVL_ERROR                 0x40000000
#define DEBUG_LVL_ALWAYS                0x80000000

//------------------------------------------------------------------------------
// this macro defines a version string
#define MAKE_VERSION_STRING(product,appname,verstr,author) \
    "$prd$:" product ",$app$:" appname ",$ver$:" verstr ",$dat$:" __DATE__ ",$aut$:" author


//------------------------------------------------------------------------------
// this macro defines a build info string (e.g. for using in printf())
#define DEBUG_MAKE_BUILD_INFO(prefix,product,prodid,descr,verstr,author) "\n" \
    prefix "***************************************************\n" \
    prefix "Project:   " product ", " prodid                  "\n" \
    prefix "Descript.: " descr                                "\n" \
    prefix "Author:    " author                               "\n" \
    prefix "Date:      " __DATE__                             "\n" \
    prefix "Version:   " verstr                               "\n" \
    prefix "***************************************************\n\n"

//---------------------------------------------------------------------------
// The default debug-level is: ERROR and ALWAYS.
// You can define an other debug-level in project settings.
#ifndef DEF_DEBUG_LVL
#define DEF_DEBUG_LVL                   (DEBUG_LVL_ALWAYS | DEBUG_LVL_ERROR)
#endif

#ifndef DEBUG_GLB_LVL
#define DEBUG_GLB_LVL                   (DEF_DEBUG_LVL)
#endif

//---------------------------------------------------------------------------
#if (DEV_SYSTEM == _DEV_WIN32_) && defined (TRACE_MSG)

// For WIN32 the macro DEBUG_TRACE can be defined as function call TraceLvl()
// or as macro TRACE().
// Here the parameter 'lvl' can be used with more than one
// debug-level (using OR).
// Example: DEBUG_TRACE(DEBUG_LVL_30 | DEBUG_LVL_02, "Hello %d", bCount);

#define DEBUG_TRACE(lvl,...)                TraceLvl((lvl),__VA_ARGS__)
#define DEBUG_GLB_LVL                       debugLevel_g

#else

// At microcontrollers we do reduce the memory usage by deleting DEBUG_TRACE-lines
// (compiler does delete the lines).
// Here the parameter 'lvl' can only be used with one debug-level.
// Example: DEBUG_TRACE(DEBUG_LVL_ERROR, "error code %d", dwRet);

#if (DEBUG_GLB_LVL & DEBUG_LVL_ALWAYS)
#define DEBUG_LVL_ALWAYS_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_ALWAYS_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_ERROR)
#define DEBUG_LVL_ERROR_TRACE(...)                 TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_ERROR_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_ASSERT)
#define DEBUG_LVL_ASSERT_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_ASSERT_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_EVENTU)
#define DEBUG_LVL_EVENTU_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_EVENUT_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_EVENTK)
#define DEBUG_LVL_EVENTK_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_EVENTK_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_VETH)
#define DEBUG_LVL_VETH_TRACE(...)                  TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_VETH_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_SDO)
#define DEBUG_LVL_SDO_TRACE(...)                   TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_SDO_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_PDO)
#define DEBUG_LVL_PDO_TRACE(...)                   TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_PDO_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_TIMERH)
#define DEBUG_LVL_TIMERH_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_TIMERH_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_TIMERU)
#define DEBUG_LVL_TIMERU_TRACE(...)                TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_TIMERU_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_CFM)
#define DEBUG_LVL_CFM_TRACE(...)                   TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_CFM_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_NMTMN)
#define DEBUG_LVL_NMTMN_TRACE(...)                 TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_NMTMN_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_NMTU)
#define DEBUG_LVL_NMTU_TRACE(...)                  TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_NMTU_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_NMTCN)
#define DEBUG_LVL_NMTCN_TRACE(...)                 TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_NMTCN_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_NMTK)
#define DEBUG_LVL_NMTK_TRACE(...)                  TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_NMTK_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_OBD)
#define DEBUG_LVL_OBD_TRACE(...)                   TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_OBD_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_DLL)
#define DEBUG_LVL_DLL_TRACE(...)                   TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_DLL_TRACE(...)
#endif

#if (DEBUG_GLB_LVL & DEBUG_LVL_EDRV)
#define DEBUG_LVL_EDRV_TRACE(...)                  TRACE(__VA_ARGS__)
#else
#define DEBUG_LVL_EDRV_TRACE(...)
#endif

#define DEBUG_TRACE(lvl,...)                       lvl##_TRACE(__VA_ARGS__)

#endif

//------------------------------------------------------------------------------
// The macro DEBUG_DUMP_DATA() can be used with the same debug-levels to dump
// out data bytes. Function DumpData() has to be included.
// NOTE: DUMP_DATA has to be defined in project settings.
#if (!defined (NDEBUG) && defined (DUMP_DATA)) || (DEV_SYSTEM == _DEV_WIN32_)
#ifdef __cplusplus
extern "C"
{
#endif

void DumpData (char* szStr_p, UINT8* pData_p, UINT16 size_p);

#ifdef __cplusplus
}
#endif

#define DEBUG_DUMP_DATA(lvl,str,ptr,siz) \
    if ((DEBUG_GLB_LVL & (lvl))==(lvl)) \
        DumpData (str, (UINT8*)(ptr), (UINT16)(siz));
#else
#define DEBUG_DUMP_DATA(lvl,str,ptr,siz)
#endif


//------------------------------------------------------------------------------
// The macro DEBUG_ASSERT() can be used to print out an error string if the
// parametered expression does not result TRUE.
// NOTE: If DEBUG_KEEP_ASSERT is defined, then DEBUG_ASSERT-line will not be
//       deleted from compiler (in release version too).
#if !defined (NDEBUG) || defined (DEBUG_KEEP_ASSERT)

#if (DEV_SYSTEM == _DEV_WIN32_)
// For WIN32 process will be killed after closing message box.
#define DEBUG_ASSERT(expr,str) \
    if (!(expr ) && ((DEBUG_GLB_LVL & DEBUG_LVL_ASSERT)!=0)) \
    { \
        MessageBox (NULL, "Assertion failed: line " __LINE__ " file " __FILE__ "\n    -> " str "\n"); \
        ExitProcess (-1); \
    }

#define DEBUG_ASSERT1(expr,str,p1) \
    if (!(expr ) && ((DEBUG_GLB_LVL & DEBUG_LVL_ASSERT)!=0)) \
    { \
        MessageBox (NULL, "Assertion failed: line " __LINE__ " file " __FILE__ "\n    -> " str "\n"); \
        ExitProcess (-1); \
    }

#else

// For microcontrollers process will be stopped using endless loop.
#define DEBUG_ASSERT0(expr,str) \
    if (!(expr )) \
    { \
        DEBUG_LVL_ASSERT_TRACE ("Assertion failed: line %d file '%s'\n" \
                                "    -> '%s'\n", __LINE__, __FILE__, str); \
        while (1); \
    }

#define DEBUG_ASSERT1(expr,str,p1) \
    if (!(expr )) \
    { \
    DEBUG_LVL_ASSERT_TRACE ("Assertion failed: line %d file '%s'\n" \
                            "    -> '%s'\n" \
                            "    -> 0x%08lX\n", __LINE__, __FILE__, str, (DWORD) p1); \
    while (1); \
    }

#endif

#else

#define DEBUG_ASSERT0(expr,str)
#define DEBUG_ASSERT1(expr,str,p1)

#endif


//------------------------------------------------------------------------------
// The macro DEBUG_ONLY() implements code, if NDEBUG is not defined.
#if !defined (DEBUG_ONLY)

#if !defined (NDEBUG)
#define DEBUG_ONLY(expr)    expr
#else
#define DEBUG_ONLY(expr)
#endif

#endif

#endif /* _INC_oplk_debug_H_ */
