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
#include "Bit_Math.h"
#include "DIO_Types.h"
#include "GPIO_Registers.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

// Pin Level Modes
#define DIO_PIN_LOW ((DIO_LevelType)0)
#define DIO_PIN_HIGH ((DIO_LevelType)1)

// PORT Level (Range)
#define DIO_PORT_LOW ((DIO_PortLevelType)0x00)

#define DIO_PORT_HIGH ((DIO_PortLevelType)0xFF)

// Pin Number Type

// PORT A Pins
#define DIO_PIN_A0 ((DIO_ChannelType)000)
#define DIO_PIN_A1 ((DIO_ChannelType)001)
#define DIO_PIN_A2 ((DIO_ChannelType)002)
#define DIO_PIN_A3 ((DIO_ChannelType)003)
#define DIO_PIN_A4 ((DIO_ChannelType)004)
#define DIO_PIN_A5 ((DIO_ChannelType)005)
#define DIO_PIN_A6 ((DIO_ChannelType)006)
#define DIO_PIN_A7 ((DIO_ChannelType)007)

// PORT B Pins
#define DIO_PIN_B0 ((DIO_ChannelType)010)
#define DIO_PIN_B1 ((DIO_ChannelType)011)
#define DIO_PIN_B2 ((DIO_ChannelType)012)
#define DIO_PIN_B3 ((DIO_ChannelType)013)
#define DIO_PIN_B4 ((DIO_ChannelType)014)
#define DIO_PIN_B5 ((DIO_ChannelType)015)
#define DIO_PIN_B6 ((DIO_ChannelType)016)
#define DIO_PIN_B7 ((DIO_ChannelType)017)

// PORT C Pins
#define DIO_PIN_C0 ((DIO_ChannelType)020)
#define DIO_PIN_C1 ((DIO_ChannelType)021)
#define DIO_PIN_C2 ((DIO_ChannelType)022)
#define DIO_PIN_C3 ((DIO_ChannelType)023)
#define DIO_PIN_C4 ((DIO_ChannelType)024)
#define DIO_PIN_C5 ((DIO_ChannelType)025)
#define DIO_PIN_C6 ((DIO_ChannelType)026)
#define DIO_PIN_C7 ((DIO_ChannelType)027)

// PORT D Pins
#define DIO_PIN_D0 ((DIO_ChannelType)030)
#define DIO_PIN_D1 ((DIO_ChannelType)031)
#define DIO_PIN_D2 ((DIO_ChannelType)032)
#define DIO_PIN_D3 ((DIO_ChannelType)033)
#define DIO_PIN_D4 ((DIO_ChannelType)034)
#define DIO_PIN_D5 ((DIO_ChannelType)035)
#define DIO_PIN_D6 ((DIO_ChannelType)036)
#define DIO_PIN_D7 ((DIO_ChannelType)037)

// PORT E Pins
#define DIO_PIN_E0 ((DIO_ChannelType)040)
#define DIO_PIN_E1 ((DIO_ChannelType)041)
#define DIO_PIN_E2 ((DIO_ChannelType)042)
#define DIO_PIN_E3 ((DIO_ChannelType)043)
#define DIO_PIN_E4 ((DIO_ChannelType)044)
#define DIO_PIN_E5 ((DIO_ChannelType)045)
#define DIO_PIN_E6 ((DIO_ChannelType)046)
#define DIO_PIN_E7 ((DIO_ChannelType)047)

// PORT F Pins
#define DIO_PIN_F0 ((DIO_ChannelType)050)
#define DIO_PIN_F1 ((DIO_ChannelType)051)
#define DIO_PIN_F2 ((DIO_ChannelType)052)
#define DIO_PIN_F3 ((DIO_ChannelType)053)
#define DIO_PIN_F4 ((DIO_ChannelType)054)
#define DIO_PIN_F5 ((DIO_ChannelType)055)
#define DIO_PIN_F6 ((DIO_ChannelType)056)
#define DIO_PIN_F7 ((DIO_ChannelType)057)

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
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId);
Std_ReturnType DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level);
DIO_PortLevelType DIO_ReadPort(DIO_PortType PortId);
void DIO_WritePort(DIO_PortType PortId, DIO_PortLevelType Level);
DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId);

#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
