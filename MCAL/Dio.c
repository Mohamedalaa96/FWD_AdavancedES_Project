/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/
// GPIOIM->interrupt mask;
// GPIOnnnn->Clear interrupt;
//  AFSEL Alternative function selection (DIO or AF)
// PORT control GPIO_CTL -> control the alternative function for the gpio selcted via AFSEL
// GPIODATA, GPIODIR important now, DigitalENable (Pad control), select the current
// GPIOCR Commit control is a register to protect the write on (D7,F0 locked by default)
// Task
// DIO driver
/*

---------------

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
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
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    IO_REG_PTR DioPort = 0;
    uint8 PinNumber = 0;
    // Channel A
    if (ChannelId < 8)
    {
        DioPort = GPIO_PORT_A_BASE;
    }

    // Channel B
    else if (ChannelId < 16)
    {
        DioPort = GPIO_PORT_A_BASE;
        PinNumber = ChannelId - 8;
    }

    // Channel C
    else if (ChannelId < 24)
    {
        DioPort = GPIO_PORT_B_BASE;
        PinNumber = ChannelId - 16;
    }

    // Channel D
    else if (ChannelId < 32)
    {
        DioPort = GPIO_PORT_C_BASE;
        PinNumber = ChannelId - 24;
    }

    // Channel E
    else if (ChannelId < 40)
    {
        DioPort = GPIO_PORT_D_BASE;
        PinNumber = ChannelId - 32;
    }

    // Channel F
    else if (ChannelId < 48)
    {
        DioPort = GPIO_PORT_F_BASE;
        PinNumber = ChannelId - 40;
    }

    return ((Dio_LevelType)GPIO_BIT_ACCESS(DioPort, GPIODATA_OFFSET, PinNumber));
}
Std_ReturnType Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    IO_REG_PTR DioPort = 0;
    uint8 PinNumber = 0;
    // Channel A
    if (ChannelId < 8)
    {
        DioPort = GPIO_PORT_A_BASE;
    }

    // Channel B
    else if (ChannelId < 16)
    {
        DioPort = GPIO_PORT_B_BASE;
        PinNumber = ChannelId - 8;
    }

    // Channel C
    else if (ChannelId < 24)
    {
        DioPort = GPIO_PORT_C_BASE;
        PinNumber = ChannelId - 16;
    }

    // Channel D
    else if (ChannelId < 32)
    {
        DioPort = GPIO_PORT_D_BASE;
        PinNumber = ChannelId - 24;
    }

    // Channel E
    else if (ChannelId < 40)
    {
        DioPort = GPIO_PORT_E_BASE;
        PinNumber = ChannelId - 32;
    }

    // Channel F
    else if (ChannelId < 48)
    {
        DioPort = GPIO_PORT_F_BASE;
        PinNumber = ChannelId - 40;
    }

    else
    {
        return E_WRONG_CONFIG;
    }
    GPIO_BIT_ACCESS(DioPort, GPIODATA_OFFSET, PinNumber) = Level;
    return E_OK;
}
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return ((Dio_PortLevelType) * (PortId + GPIODATA_OFFSET));
}
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    *(PortId + GPIODATA_OFFSET) = Level;
}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
