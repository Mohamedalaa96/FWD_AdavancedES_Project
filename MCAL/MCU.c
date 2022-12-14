/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MCU.c
 *        \brief Static Code implementation of MCU Driver
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "MCU_Registers.h"
#include "MCU.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : Std_ReturnType Gpt_Init(const Gpt_ConfigType *ConfigPtr)
 * \Description     : Initialize the timer and its hardware parameters from ConfigPtr, and start predefined timers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : *ConfigPtr   pointer to configuration struct of the type Gpt_ConfigType
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void MCU_Init(const MCU_ConfigType *ConfigPtr)
{
    MCU_BIT_ACCESS;
}

MCU_RawResetType MCU_GetResetRawValue(void)
{
    return (*(MCU_BASE_ADDRESS + RESC_OFFSET));
}
void MCU_PerformReset(void)
{
}
Std_ReturnType MCU_InitClock(MCU_ClockType ClockSetting)
{
    (*(MCU_BASE_ADDRESS + RCC_OFFSET)) = 0x15 << 6; // 16Mhz
}
Std_ReturnType MCU_DistributePllClock(void)
{
}
MCU_PllStatusType MCU_GetPllStatus(void)
{
}

/**********************************************************************************************************************
 *  END OF FILE: MCU.c
 *********************************************************************************************************************/
