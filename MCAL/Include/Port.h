/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  -
 *
 *  Description:  Port Driver header file
 *
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "PORT_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Pin Number Type */
/* PORT A Pins */
#define DIO_PIN_A0 ((Port_PinType)000)
#define DIO_PIN_A1 ((Port_PinType)001)
#define DIO_PIN_A2 ((Port_PinType)002)
#define DIO_PIN_A3 ((Port_PinType)003)
#define DIO_PIN_A4 ((Port_PinType)004)
#define DIO_PIN_A5 ((Port_PinType)005)
#define DIO_PIN_A6 ((Port_PinType)006)
#define DIO_PIN_A7 ((Port_PinType)007)

/* PORT B Pins*/
#define DIO_PIN_B0 ((Port_PinType)010)
#define DIO_PIN_B1 ((Port_PinType)011)
#define DIO_PIN_B2 ((Port_PinType)012)
#define DIO_PIN_B3 ((Port_PinType)013)
#define DIO_PIN_B4 ((Port_PinType)014)
#define DIO_PIN_B5 ((Port_PinType)015)
#define DIO_PIN_B6 ((Port_PinType)016)
#define DIO_PIN_B7 ((Port_PinType)017)

/* PORT C Pins */
#define DIO_PIN_C0 ((Port_PinType)020)
#define DIO_PIN_C1 ((Port_PinType)021)
#define DIO_PIN_C2 ((Port_PinType)022)
#define DIO_PIN_C3 ((Port_PinType)023)
#define DIO_PIN_C4 ((Port_PinType)024)
#define DIO_PIN_C5 ((Port_PinType)025)
#define DIO_PIN_C6 ((Port_PinType)026)
#define DIO_PIN_C7 ((Port_PinType)027)

/* PORT D Pins */
#define DIO_PIN_D0 ((Port_PinType)030)
#define DIO_PIN_D1 ((Port_PinType)031)
#define DIO_PIN_D2 ((Port_PinType)032)
#define DIO_PIN_D3 ((Port_PinType)033)
#define DIO_PIN_D4 ((Port_PinType)034)
#define DIO_PIN_D5 ((Port_PinType)035)
#define DIO_PIN_D6 ((Port_PinType)036)
#define DIO_PIN_D7 ((Port_PinType)037)

/* PORT E Pins*/
#define DIO_PIN_E0 ((Port_PinType)040)
#define DIO_PIN_E1 ((Port_PinType)041)
#define DIO_PIN_E2 ((Port_PinType)042)
#define DIO_PIN_E3 ((Port_PinType)043)
#define DIO_PIN_E4 ((Port_PinType)044)
#define DIO_PIN_E5 ((Port_PinType)045)
#define DIO_PIN_E6 ((Port_PinType)046)
#define DIO_PIN_E7 ((Port_PinType)047)

/* PORT F Pins */
#define DIO_PIN_F0 ((Port_PinType)050)
#define DIO_PIN_F1 ((Port_PinType)051)
#define DIO_PIN_F2 ((Port_PinType)052)
#define DIO_PIN_F3 ((Port_PinType)053)
#define DIO_PIN_F4 ((Port_PinType)054)
#define DIO_PIN_F5 ((Port_PinType)055)
#define DIO_PIN_F6 ((Port_PinType)056)
#define DIO_PIN_F7 ((Port_PinType)057)

/* Pin Level Modes*/
#define PORT_PIN_LOW ((Port_PinLevelType)0)
#define PORT_PIN_HIGH ((Port_PinLevelType)1)

/* Pin Direction Modes */
#define PORT_PIN_INPUT ((Port_DirectionType)0)
#define PORT_PIN_OUTPUT ((Port_DirectionType)1)

/* Pin Modes */
#define PORT_PIN_MODE_AF ((Port_PinModeType)0)
#define PORT_PIN_MODE_DIO ((Port_PinModeType)1)

/* Pin Internal Attach */
#define PORT_PIN_PU ((Port_PinInternalAttachType)0)
#define PORT_PIN_PD ((Port_PinInternalAttachType)1)
#define PORT_PIN_OD ((Port_PinInternalAttachType)2)

/* Pin Current Limit*/
#define PORT_PIN_2MA ((Port_PinOutputCurrentType)0)
#define PORT_PIN_4MA ((Port_PinOutputCurrentType)1)
#define PORT_PIN_8MA ((Port_PinOutputCurrentType)2)

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
void Port_Init(const Port_ConfigType *ConfigPtr);
#endif /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
