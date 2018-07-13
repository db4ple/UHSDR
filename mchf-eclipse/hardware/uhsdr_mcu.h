/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		GNU GPLv3                                                      **
************************************************************************************/
#ifndef __MCHF_MCU_H
#define __MCHF_MCU_H


typedef enum {
    CPU_NONE = 0,
    CPU_STM32F4 = 1,
    CPU_STM32F7 = 2,
    CPU_STM32H7 = 3,
} mchf_cpu_t;


#ifdef CORTEX_M7
#ifdef STM32H743xx
	#include "stm32h7xx.h"
	#include "stm32h7xx_hal.h"
#else
	#include "stm32f7xx_hal.h"
#endif

#endif
#ifdef CORTEX_M4
#include "stm32f4xx.h"
#include "stm32f407xx.h"
#endif

inline mchf_cpu_t MchfHW_Cpu()
{
    mchf_cpu_t retval = CPU_NONE;
#if defined(STM32F4)
    retval = CPU_STM32F4;
#elif  defined(STM32F7)
    retval = CPU_STM32F7;
#elif  defined(STM32H7)
    retval = CPU_STM32H7;
#endif
    return retval;
}

#define STM32_GetRevision()     (*(uint16_t *) (UID_BASE + 2))
#define STM32_GetSignature()    ((*(uint16_t *) (DBGMCU_BASE)) & 0x0FFF)
#define STM32_UUID ((uint32_t *)UID_BASE)

#ifndef STM32H7
    #define STM32_GetFlashSize()    (*(uint16_t *) (FLASHSIZE_BASE))
#else
    #define STM32_GetFlashSize()    (FLASH_SIZE/1024)
#endif

#endif
