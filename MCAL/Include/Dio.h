/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  -
 *
 *  Description:  DIO Driver header file
 *
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Types.h"
#include "GPIO_Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

// Pin Level Modes
#define DIO_PIN_LOW ((Dio_LevelType)0)
#define DIO_PIN_HIGH ((Dio_LevelType)1)6

// PORT Level (Range)
#define DIO_PIN_LOW ((Dio_PortLevelType)0x00)

#define DIO_PIN_HIGH ((Dio_PortLevelType)0xFF)

// PORTs Selection
#define DIO_PORT_A ((Dio_PortType)GPIO_PORT_A_BASE)
#define DIO_PORT_B ((Dio_PortType)GPIO_PORT_B_BASE)
#define DIO_PORT_C ((Dio_PortType)GPIO_PORT_C_BASE)
#define DIO_PORT_D ((Dio_PortType)GPIO_PORT_D_BASE)
#define DIO_PORT_E ((Dio_PortType)GPIO_PORT_E_BASE)
#define DIO_PORT_F ((Dio_PortType)GPIO_PORT_F_BASE)

// Pin Number Type

// PORT A Pins
#define DIO_PIN_A0 ((Dio_ChannelType)000)
#define DIO_PIN_A1 ((Dio_ChannelType)001)
#define DIO_PIN_A2 ((Dio_ChannelType)002)
#define DIO_PIN_A3 ((Dio_ChannelType)003)
#define DIO_PIN_A4 ((Dio_ChannelType)004)
#define DIO_PIN_A5 ((Dio_ChannelType)005)
#define DIO_PIN_A3 ((Dio_ChannelType)006)
#define DIO_PIN_A4 ((Dio_ChannelType)007)

// PORT B Pins
#define DIO_PIN_B0 ((Dio_ChannelType)010)
#define DIO_PIN_B1 ((Dio_ChannelType)011)
#define DIO_PIN_B2 ((Dio_ChannelType)012)
#define DIO_PIN_B3 ((Dio_ChannelType)013)
#define DIO_PIN_B4 ((Dio_ChannelType)014)
#define DIO_PIN_B5 ((Dio_ChannelType)015)
#define DIO_PIN_B3 ((Dio_ChannelType)016)
#define DIO_PIN_B4 ((Dio_ChannelType)017)

// PORT C Pins
#define DIO_PIN_C0 ((Dio_ChannelType)020)
#define DIO_PIN_C1 ((Dio_ChannelType)021)
#define DIO_PIN_C2 ((Dio_ChannelType)022)
#define DIO_PIN_C3 ((Dio_ChannelType)023)
#define DIO_PIN_C4 ((Dio_ChannelType)024)
#define DIO_PIN_C5 ((Dio_ChannelType)025)
#define DIO_PIN_C3 ((Dio_ChannelType)026)
#define DIO_PIN_C4 ((Dio_ChannelType)027)

// PORT D Pins
#define DIO_PIN_D0 ((Dio_ChannelType)030)
#define DIO_PIN_D1 ((Dio_ChannelType)031)
#define DIO_PIN_D2 ((Dio_ChannelType)032)
#define DIO_PIN_D3 ((Dio_ChannelType)033)
#define DIO_PIN_D4 ((Dio_ChannelType)034)
#define DIO_PIN_D5 ((Dio_ChannelType)035)
#define DIO_PIN_D3 ((Dio_ChannelType)036)
#define DIO_PIN_D4 ((Dio_ChannelType)037)

// PORT E Pins
#define DIO_PIN_E0 ((Dio_ChannelType)040)
#define DIO_PIN_E1 ((Dio_ChannelType)041)
#define DIO_PIN_E2 ((Dio_ChannelType)042)
#define DIO_PIN_E3 ((Dio_ChannelType)043)
#define DIO_PIN_E4 ((Dio_ChannelType)044)
#define DIO_PIN_E5 ((Dio_ChannelType)045)
#define DIO_PIN_E3 ((Dio_ChannelType)046)
#define DIO_PIN_E4 ((Dio_ChannelType)047)

// PORT F Pins
#define DIO_PIN_F0 ((Dio_ChannelType)050)
#define DIO_PIN_F1 ((Dio_ChannelType)051)
#define DIO_PIN_F2 ((Dio_ChannelType)052)
#define DIO_PIN_F3 ((Dio_ChannelType)053)
#define DIO_PIN_F4 ((Dio_ChannelType)054)
#define DIO_PIN_F5 ((Dio_ChannelType)055)
#define DIO_PIN_F3 ((Dio_ChannelType)056)
#define DIO_PIN_F4 ((Dio_ChannelType)057)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Std_ReturnType DIO_SetPinDataDirection(DIO_PortType portName, DIO_PinNumType pinNumber, DIO_DataDirType pinDirection);
Std_ReturnType DIO_SetPinDataDirection(DIO_PortType dioPortName);
#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
