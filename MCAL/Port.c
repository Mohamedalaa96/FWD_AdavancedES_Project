/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Port_Types.h"
#include "GPIO_Registers.h"
#include "Port.h"

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
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Description
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    uint32 DioPort = 0;
    uint8 PinNumber = 0;
    /* Channel A */
    if (ConfigPtr->PortPinNumber < 8)
    {
        DioPort = GPIO_PORT_A_BASE;
    }

    /* Channel B */
    else if (ConfigPtr->PortPinNumber < 16)
    {
        DioPort = GPIO_PORT_B_BASE;
        PinNumber = ConfigPtr->PortPinNumber - 8;
    }

    /* Channel C */
    else if (ConfigPtr->PortPinNumber < 24)
    {
        DioPort = GPIO_PORT_C_BASE;
        PinNumber = ConfigPtr->PortPinNumber - 16;
    }

    /*  Channel D */
    else if (ConfigPtr->PortPinNumber < 32)
    {
        DioPort = GPIO_PORT_D_BASE;
        PinNumber = ConfigPtr->PortPinNumber - 24;
    }

    // Channel E
    else if (ConfigPtr->PortPinNumber < 40)
    {
        DioPort = GPIO_PORT_E_BASE;
        PinNumber = ConfigPtr->PortPinNumber - 32;
    }

    // Channel F
    else if (ConfigPtr->PortPinNumber < 48)
    {
        DioPort = GPIO_PORT_F_BASE;
        PinNumber = ConfigPtr->PortPinNumber - 40;
    }

    GPIO_BIT_ACCESS(DioPort, GPIODIR_OFFSET, PinNumber) = ConfigPtr->PortPinDirection;
    //     ConfigPtr->PortPinInternalAttach
    //     ConfigPtr->
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
