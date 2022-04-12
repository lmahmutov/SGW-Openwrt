/***************************************************************************//**
 * @file
 * @brief CPU - POSIX Emulation Port
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

/****************************************************************************************************//**
 * @note     (1) This port targets the following:
 *                   Core      : POSIX
 *                   Mode      :
 *                   Toolchain : GNU C Compiler
 *
 * @note     (2) This port is an emulation support port.
 *******************************************************************************************************/

/********************************************************************************************************
 ********************************************************************************************************
 *                                                   MODULE
 ********************************************************************************************************
 *******************************************************************************************************/

#ifndef  _CPU_PORT_H_
#define  _CPU_PORT_H_

/********************************************************************************************************
 ********************************************************************************************************
 *                                               INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <stddef.h>
#include  <stdint.h>
#include  <pthread.h>

#include  <cpu/include/cpu_def.h>

#include  <common/include/rtos_path.h>
#include  <cpu_cfg.h>                                           // See Note #3.

#ifdef __cplusplus
extern  "C" {
#endif

/********************************************************************************************************
 *                                       CONFIGURE STANDARD DATA TYPES
 *
 * Note(s) : (1) Configure standard data types according to CPU-/compiler-specifications.
 *
 *           (2) (a) (1) 'CPU_FNCT_VOID' data type defined to replace the commonly-used function pointer
 *                       data type of a pointer to a function which returns void & has no arguments.
 *
 *                   (2) Example function pointer usage :
 *
 *                           CPU_FNCT_VOID  FnctName;
 *
 *                           FnctName();
 *
 *               (b) (1) 'CPU_FNCT_PTR'  data type defined to replace the commonly-used function pointer
 *                       data type of a pointer to a function which returns void & has a single void
 *                       pointer argument.
 *
 *                   (2) Example function pointer usage :
 *
 *                           CPU_FNCT_PTR   FnctName;
 *                           void          *p_obj
 *
 *                           FnctName(p_obj);
 *******************************************************************************************************/

typedef void CPU_VOID;
typedef char CPU_CHAR;                                          // 8-bit character
typedef uint8_t CPU_BOOLEAN;                                    // 8-bit boolean or logical
typedef uint8_t CPU_INT08U;                                     // 8-bit unsigned integer
typedef int8_t CPU_INT08S;                                      // 8-bit   signed integer
typedef uint16_t CPU_INT16U;                                    // 16-bit unsigned integer
typedef int16_t CPU_INT16S;                                     // 16-bit   signed integer
typedef uint32_t CPU_INT32U;                                    // 32-bit unsigned integer
typedef int32_t CPU_INT32S;                                     // 32-bit   signed integer
typedef uint64_t CPU_INT64U;                                    // 64-bit unsigned integer
typedef int64_t CPU_INT64S;                                     // 64-bit   signed integer

typedef float CPU_FP32;                                         // 32-bit floating point
typedef double CPU_FP64;                                        // 64-bit floating point

typedef volatile CPU_INT08U CPU_REG08;                          // 8-bit register
typedef volatile CPU_INT16U CPU_REG16;                          // 16-bit register
typedef volatile CPU_INT32U CPU_REG32;                          // 32-bit register
typedef volatile CPU_INT64U CPU_REG64;                          // 64-bit register

typedef void (*CPU_FNCT_VOID)(void);                            // See Note #2a.
typedef void (*CPU_FNCT_PTR )(void *p_obj);                     // See Note #2b.

typedef struct CPU_Interrupt CPU_INTERRUPT;

struct CPU_Interrupt {
  void        (*ISR_Fnct)(void);
  CPU_INT08U  Prio;                                             // Higher the number, Higher the Priority.
  CPU_BOOLEAN En;
  CPU_CHAR    *NamePtr;
  CPU_BOOLEAN TraceEn;
};

typedef struct CPU_Tmr_Interrupt CPU_TMR_INTERRUPT;

struct CPU_Tmr_Interrupt {
  CPU_INTERRUPT Interrupt;
  CPU_BOOLEAN   OneShot;
  CPU_INT32U    PeriodSec;
  CPU_INT32U    PeriodMuSec;
};

/********************************************************************************************************
 *                                           CPU WORD CONFIGURATION
 *
 * Note(s) : (1) Configure CPU_CFG_ADDR_SIZE, CPU_CFG_DATA_SIZE, & CPU_CFG_DATA_SIZE_MAX with CPU's &/or
 *               compiler's word sizes :
 *
 *                   CPU_WORD_SIZE_08     8-bit word size
 *                   CPU_WORD_SIZE_16    16-bit word size
 *                   CPU_WORD_SIZE_32    32-bit word size
 *                   CPU_WORD_SIZE_64    64-bit word size
 *
 *           (2) Configure CPU_CFG_ENDIAN_TYPE with CPU's data-word-memory order :
 *
 *               (a) CPU_ENDIAN_TYPE_BIG     Big-   endian word order (CPU words' most  significant
 *                                                                       octet @ lowest memory address)
 *               (b) CPU_ENDIAN_TYPE_LITTLE  Little-endian word order (CPU words' least significant
 *                                                                       octet @ lowest memory address)
 *******************************************************************************************************/

//                                                                 Define  CPU         word sizes (see Note #1) :
#ifdef _LP64
#define  CPU_CFG_ADDR_SIZE              CPU_WORD_SIZE_64        // Defines CPU address word size  (in octets).
#define  CPU_CFG_DATA_SIZE              CPU_WORD_SIZE_64        // Defines CPU data    word size  (in octets).
#else
#define  CPU_CFG_ADDR_SIZE              CPU_WORD_SIZE_32        // Defines CPU address word size  (in octets).
#define  CPU_CFG_DATA_SIZE              CPU_WORD_SIZE_32        // Defines CPU data    word size  (in octets).
#endif

#define  CPU_CFG_DATA_SIZE_MAX          CPU_WORD_SIZE_64        // Defines CPU maximum word size  (in octets).

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define  CPU_CFG_ENDIAN_TYPE            CPU_ENDIAN_TYPE_LITTLE  // Defines CPU data    word-memory order (see Note #2).
#else
#define  CPU_CFG_ENDIAN_TYPE            CPU_ENDIAN_TYPE_BIG     // Defines CPU data    word-memory order (see Note #2).
#endif

/********************************************************************************************************
 *                                   CONFIGURE CPU ADDRESS & DATA TYPES
 *******************************************************************************************************/

//                                                                 CPU address type based on address bus size.
#if     (CPU_CFG_ADDR_SIZE == CPU_WORD_SIZE_64)
typedef CPU_INT64U CPU_ADDR;
#elif     (CPU_CFG_ADDR_SIZE == CPU_WORD_SIZE_32)
typedef CPU_INT32U CPU_ADDR;
#elif   (CPU_CFG_ADDR_SIZE == CPU_WORD_SIZE_16)
typedef CPU_INT16U CPU_ADDR;
#else
typedef CPU_INT08U CPU_ADDR;
#endif

//                                                                 CPU data    type based on data    bus size.
#if     (CPU_CFG_DATA_SIZE == CPU_WORD_SIZE_64)
typedef CPU_INT64U CPU_DATA;
#elif     (CPU_CFG_DATA_SIZE == CPU_WORD_SIZE_32)
typedef CPU_INT32U CPU_DATA;
#elif   (CPU_CFG_DATA_SIZE == CPU_WORD_SIZE_16)
typedef CPU_INT16U CPU_DATA;
#else
typedef CPU_INT08U CPU_DATA;
#endif

typedef CPU_DATA CPU_ALIGN;                                     // Defines CPU data-word-alignment size.
typedef size_t CPU_SIZE_T;                                      // Defines CPU standard 'size_t'   size.

/********************************************************************************************************
 *                                           CPU STACK CONFIGURATION
 *
 * Note(s) : (1) Configure CPU_CFG_STK_GROWTH in 'cpu_port.h' with CPU's stack growth order :
 *
 *               (a) CPU_STK_GROWTH_LO_TO_HI     CPU stack pointer increments to the next higher  stack
 *                                                   memory address after data is pushed onto the stack
 *               (b) CPU_STK_GROWTH_HI_TO_LO     CPU stack pointer decrements to the next lower   stack
 *                                                   memory address after data is pushed onto the stack
 *
 *           (2) Configure CPU_CFG_STK_ALIGN_BYTES with the highest minimum alignement required for
 *               cpu stacks.
 *******************************************************************************************************/

#define  CPU_CFG_STK_GROWTH       CPU_STK_GROWTH_HI_TO_LO       // Defines CPU stack growth order (see Note #1).

#define  CPU_CFG_STK_ALIGN_BYTES  (sizeof(CPU_ALIGN))           // Defines CPU stack alignment in bytes. (see Note #2).

typedef CPU_INT32U CPU_STK;                                     // Defines CPU stack data type.
typedef CPU_ADDR CPU_STK_SIZE;                                  // Defines CPU stack size data type.


/********************************************************************************************************
 *                                       MEMORY BARRIERS CONFIGURATION
 *
 * Note(s) : (1) (a) Configure memory barriers if required by the architecture.
 *
 *                   CPU_MB      Full memory barrier.
 *                   CPU_RMB     Read (Loads) memory barrier.
 *                   CPU_WMB     Write (Stores) memory barrier.
 *******************************************************************************************************/

#define  CPU_MB()
#define  CPU_RMB()
#define  CPU_WMB()

/********************************************************************************************************
 *                                           FUNCTION PROTOTYPES
 *******************************************************************************************************/

void CPU_IntDis(void);
void CPU_IntEn(void);

void CPU_ISR_End(void);

void CPU_TmrInterruptCreate(CPU_TMR_INTERRUPT *p_tmr_interrupt);

void CPU_InterruptTrigger(CPU_INTERRUPT *p_interrupt);

/********************************************************************************************************
 *                                           CONFIGURATION ERRORS
 *******************************************************************************************************/

#ifndef  CPU_CFG_ADDR_SIZE
#error  "CPU_CFG_ADDR_SIZE              not #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"

#elif  ((CPU_CFG_ADDR_SIZE != CPU_WORD_SIZE_08) \
  && (CPU_CFG_ADDR_SIZE != CPU_WORD_SIZE_16)    \
  && (CPU_CFG_ADDR_SIZE != CPU_WORD_SIZE_32)    \
  && (CPU_CFG_ADDR_SIZE != CPU_WORD_SIZE_64))
#error  "CPU_CFG_ADDR_SIZE        illegally #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"
#endif

#ifndef  CPU_CFG_DATA_SIZE
#error  "CPU_CFG_DATA_SIZE              not #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"

#elif  ((CPU_CFG_DATA_SIZE != CPU_WORD_SIZE_08) \
  && (CPU_CFG_DATA_SIZE != CPU_WORD_SIZE_16)    \
  && (CPU_CFG_DATA_SIZE != CPU_WORD_SIZE_32)    \
  && (CPU_CFG_DATA_SIZE != CPU_WORD_SIZE_64))
#error  "CPU_CFG_DATA_SIZE        illegally #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"
#endif

#ifndef  CPU_CFG_DATA_SIZE_MAX
#error  "CPU_CFG_DATA_SIZE_MAX          not #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"

#elif  ((CPU_CFG_DATA_SIZE_MAX != CPU_WORD_SIZE_08) \
  && (CPU_CFG_DATA_SIZE_MAX != CPU_WORD_SIZE_16)    \
  && (CPU_CFG_DATA_SIZE_MAX != CPU_WORD_SIZE_32)    \
  && (CPU_CFG_DATA_SIZE_MAX != CPU_WORD_SIZE_64))
#error  "CPU_CFG_DATA_SIZE_MAX    illegally #define'd in 'cpu_port.h'               "
#error  "                         [MUST be  CPU_WORD_SIZE_08   8-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_16  16-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_32  32-bit alignment]"
#error  "                         [     ||  CPU_WORD_SIZE_64  64-bit alignment]"
#endif

#if     (CPU_CFG_DATA_SIZE_MAX < CPU_CFG_DATA_SIZE)
#error  "CPU_CFG_DATA_SIZE_MAX    illegally #define'd in 'cpu_port.h' "
#error  "                         [MUST be  >= CPU_CFG_DATA_SIZE]"
#endif

#ifndef  CPU_CFG_ENDIAN_TYPE
#error  "CPU_CFG_ENDIAN_TYPE            not #define'd in 'cpu_port.h'   "
#error  "                         [MUST be  CPU_ENDIAN_TYPE_BIG   ]"
#error  "                         [     ||  CPU_ENDIAN_TYPE_LITTLE]"

#elif  ((CPU_CFG_ENDIAN_TYPE != CPU_ENDIAN_TYPE_BIG) \
  && (CPU_CFG_ENDIAN_TYPE != CPU_ENDIAN_TYPE_LITTLE))
#error  "CPU_CFG_ENDIAN_TYPE      illegally #define'd in 'cpu_port.h'   "
#error  "                         [MUST be  CPU_ENDIAN_TYPE_BIG   ]"
#error  "                         [     ||  CPU_ENDIAN_TYPE_LITTLE]"
#endif

#ifndef  CPU_CFG_STK_GROWTH
#error  "CPU_CFG_STK_GROWTH             not #define'd in 'cpu_port.h'    "
#error  "                         [MUST be  CPU_STK_GROWTH_LO_TO_HI]"
#error  "                         [     ||  CPU_STK_GROWTH_HI_TO_LO]"

#elif  ((CPU_CFG_STK_GROWTH != CPU_STK_GROWTH_LO_TO_HI) \
  && (CPU_CFG_STK_GROWTH != CPU_STK_GROWTH_HI_TO_LO))
#error  "CPU_CFG_STK_GROWTH       illegally #define'd in 'cpu_port.h'    "
#error  "                         [MUST be  CPU_STK_GROWTH_LO_TO_HI]"
#error  "                         [     ||  CPU_STK_GROWTH_HI_TO_LO]"
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                               MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif // End of CPU module include.
