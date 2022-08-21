/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU.h
 *       Module:  MCU
 *
 *  Description:  MCU Driver header file
 *
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{

} MCU_PllStatusType;

typedef enum
{

} MCU_ClockType;

// typedef enum
// {
//     MCU_POWER_ON_RESET,
//     MCU_EXTERNAL_RESET_INPUT_PIN,
//     MCU_BROWN_OUT_DETECTION,
//     MCU_SOFTWARE_INITIATED_RESET,
//     MCU_WDT_RESET,
//     MCU_MOSC_FAILURE
// } MCU_RawResetType;

typedef uint32 MCU_RawResetType;

typedef struct
{

} MCU_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void MCU_Init(const MCU_ConfigType *ConfigPtr);
MCU_RawResetType MCU_GetResetRawValue(void);
void MCU_PerformReset(void);
Std_ReturnType MCU_InitClock(MCU_ClockType ClockSetting);
Std_ReturnType MCU_DistributePllClock(void);
MCU_PllStatusType MCU_GetPllStatus(void);

#endif /* MCU_H */

/**********************************************************************************************************************
 *  END OF FILE: MCU.h
 *********************************************************************************************************************/
