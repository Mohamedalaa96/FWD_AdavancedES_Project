/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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
#include "DIO.h"
#include "GPIO_Registers.h"
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
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId)
{
    uint32 DIOPort = 0;
    uint8 PinNumber = 0;
    // Channel A
    if (ChannelId < 8)
    {
        DIOPort = GPIO_PORT_A_BASE;
    }

    // Channel B
    else if (ChannelId < 16)
    {
        DIOPort = GPIO_PORT_A_BASE;
        PinNumber = ChannelId - 8;
    }

    // Channel C
    else if (ChannelId < 24)
    {
        DIOPort = GPIO_PORT_B_BASE;
        PinNumber = ChannelId - 16;
    }

    // Channel D
    else if (ChannelId < 32)
    {
        DIOPort = GPIO_PORT_C_BASE;
        PinNumber = ChannelId - 24;
    }

    // Channel E
    else if (ChannelId < 40)
    {
        DIOPort = GPIO_PORT_D_BASE;
        PinNumber = ChannelId - 32;
    }

    // Channel F
    else if (ChannelId < 48)
    {
        DIOPort = GPIO_PORT_F_BASE;
        PinNumber = ChannelId - 40;
    }

    return ((DIO_LevelType)GPIO_BIT_ACCESS(DIOPort, GPIODATA_OFFSET, PinNumber));
}
Std_ReturnType DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level)
{
    uint32 DIOPort = 0;
    uint8 PinNumber = 0;
    // Channel A
    if (ChannelId < 8)
    {
        DIOPort = GPIO_PORT_A_BASE;
    }

    // Channel B
    else if (ChannelId < 16)
    {
        DIOPort = GPIO_PORT_B_BASE;
        PinNumber = ChannelId - 8;
    }

    // Channel C
    else if (ChannelId < 24)
    {
        DIOPort = GPIO_PORT_C_BASE;
        PinNumber = ChannelId - 16;
    }

    // Channel D
    else if (ChannelId < 32)
    {
        DIOPort = GPIO_PORT_D_BASE;
        PinNumber = ChannelId - 24;
    }

    // Channel E
    else if (ChannelId < 40)
    {
        DIOPort = GPIO_PORT_E_BASE;
        PinNumber = ChannelId - 32;
    }

    // Channel F
    else if (ChannelId < 48)
    {
        DIOPort = GPIO_PORT_F_BASE;
        PinNumber = ChannelId - 40;
    }

    else
    {
        return E_WRONG_CONFIG;
    }
    GPIO_BIT_ACCESS(DIOPort, GPIODATA_OFFSET, PinNumber) = Level;
    return E_OK;
}
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId)
{
    return ((DIO_PortLevelType)(*(IO_REG_PTR)(PortId + GPIODATA_OFFSET)));
}
void DIO_WritePort(DIO_PortType PortId, DIO_PortLevelType Level)
{
    (*(IO_REG_PTR)(PortId + GPIODATA_OFFSET)) = Level;
}
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId)
{
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
