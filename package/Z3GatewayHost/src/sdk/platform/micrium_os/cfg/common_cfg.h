/***************************************************************************//**
 * @file
 * @brief Common Configuration - Configuration Template File
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>>

/*********************************************************************************************************
 *********************************************************************************************************
 *                                               MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef  _COMMON_CFG_H_
#define  _COMMON_CFG_H_

/*********************************************************************************************************
 *********************************************************************************************************
 *                                     MEMORY LIBRARY CONFIGURATION
 ********************************************************************************************************
 *******************************************************************************************************/

// <q LIB_MEM_CFG_STD_C_LIB_EN> Replace common lib memory functions with standard C lib functions
// <i> Cause the following functions replacement: Mem_Set() -> memset(), Mem_Copy() -> memcpy(),
// <i> Mem_Move() -> memmove(), Mem_Clr() -> memset() and Mem_Cmp() -> memcmp() functions.
// <i> Default: 0
#define  LIB_MEM_CFG_STD_C_LIB_EN                           0

// <q LIB_MEM_CFG_MEM_COPY_OPTIMIZE_ASM_EN> Assembly-optimized memory copy function
// <i> An assembly-optimized version of Mem_Copy() may be provided for your architecture.
// <i> Make sure to select the appropriate component before enabling this.
// <i> This cannot be enabled when LIB_MEM_CFG_STD_C_LIB_EN is enabled.
// <i> Default: 0
#define  LIB_MEM_CFG_MEM_COPY_OPTIMIZE_ASM_EN               0

// <q LIB_MEM_CFG_DBG_INFO_EN> Memory allocation usage tracking
// <i> Associates a name with each segment or dynamic pool allocated.
// <i> A table of the different allocations can be displayed. For debugging purposes.
// <i> Default: 0
#define  LIB_MEM_CFG_DBG_INFO_EN                            0

// <o LIB_MEM_CFG_HEAP_SIZE> Size of heap memory (in octets).
// <i> Size, in octets, of the general-purpose heap memory used as default memory segment.
// <i> Default: 9216
#define  LIB_MEM_CFG_HEAP_SIZE                              9216

// <o LIB_MEM_CFG_HEAP_PADDING_ALIGN> Padding alignment for hardware allocations on heap (in octets)
// <i> Padding alignment that will be added at the end of each memory allocation on heap when "HW" functions are used.
// <i> Only useful when data cache is used. Should be set to the size of a cache line.
// <i> 1 means no alignment.
// <i> Default: 1
#define  LIB_MEM_CFG_HEAP_PADDING_ALIGN                     1

// <q LIB_MEM_CFG_HEAP_BASE_ADDR_EN> Custom heap location
// <i> If enabled, the location must be specified by defining LIB_MEM_CFG_HEAP_BASE_ADDR to the desired address
// <i> either in "common_cfg.h" or from the compiler defines list.
// <i> Default: 0
#define  LIB_MEM_CFG_HEAP_BASE_ADDR_EN                      0

/********************************************************************************************************
 ********************************************************************************************************
 *                                     STRING LIBRARY CONFIGURATION
 ********************************************************************************************************
 *******************************************************************************************************/

// <q LIB_STR_CFG_FP_EN> Support conversion to string of floating point numbers
// <i> Default: 0
#define  LIB_STR_CFG_FP_EN                                  0

// <o LIB_STR_CFG_FP_MAX_NBR_DIG_SIG> Maximum number of significant digits to display in string conversion of floating point number functions <1-9>
// <i> Default: 7
#define  LIB_STR_CFG_FP_MAX_NBR_DIG_SIG                     7

/*********************************************************************************************************
 *********************************************************************************************************
 *                                         CLOCK CONFIGURATION
 *********************************************************************************************************
 ********************************************************************************************************/

// <q CLK_CFG_STR_CONV_EN> Support conversion to string of current time/date
// <i> Enables Clk_DateTimeToStr() function.
// <i> Default: 1
#define  CLK_CFG_STR_CONV_EN                                1

// <q CLK_CFG_NTP_EN> Support NTP time format
// <i> Enables following functions: Clk_GetTS_NTP(), Clk_SetTS_NTP(), Clk_TS_ToTS_NTP(),
// <i> Clk_TS_NTP_ToTS(), Clk_TS_NTP_ToDateTime(), Clk_DateTimeToTS_NTP(), Clk_NTP_DateTimeMake(), Clk_IsNTP_DateTimeValid().
// <i> Default: 1
#define  CLK_CFG_NTP_EN                                     1

// <q CLK_CFG_UNIX_EN> Support Unix time format
// <i> Enables following functions: Clk_GetTS_Unix(), Clk_SetTS_Unix(), Clk_TS_ToTS_Unix(),
// <i> Clk_TS_UnixToTS(), Clk_TS_UnixToDateTime(), Clk_DateTimeToTS_Unix(), Clk_UnixDateTimeMake(), Clk_IsUnixDateTimeValid().
// <i> Default: 1
#define  CLK_CFG_UNIX_EN                                    1

// <q CLK_CFG_EXT_EN> External (hardware) clock syncing
// <i> When enabled, clock is synced via a hardware timer. When disabled, clock is synced in software (using the kernel).
// <i> A clock driver must be implemented before enabling external syncing.
// <i> Default: 0
#define  CLK_CFG_EXT_EN                                     0

// <q CLK_CFG_SIGNAL_EN> Signaling of the internally-maintained software clock via application
// <i> Enables function Clk_SignalClk() for syncing via application.
// <i> Default: 0
#define  CLK_CFG_SIGNAL_EN                                  0

// <o CLK_CFG_SIGNAL_FREQ_HZ> Number of times the application will signal the clock every second
// <i> Required only if CLK_CFG_EXT_EN is disabled.
// <i> Default: 1000
#define  CLK_CFG_SIGNAL_FREQ_HZ                             1000u

/********************************************************************************************************
 ********************************************************************************************************
 *                                             MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif // End of common_cfg.h module include.

// <<< end of configuration section >>>
