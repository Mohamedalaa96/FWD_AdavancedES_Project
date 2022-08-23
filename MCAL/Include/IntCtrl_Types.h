/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INTCTRL_MAX_NUM_OF_CHANNELS 78
#define INTCTRL_STATE_DISABLED 10
#define INTCTRL_STATE_ENABLED 20
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 IntCtrl_InterruptStatusType;
typedef struct
{
    // IntCtrl_RESET = -15;
    // IntCtrl_NMI;
    // IntCtrl_HardFault;
    // IntCtrl_MemMngFault;
    // IntCtrl_BusFault;
    // IntCtrl_UsageFault;
    // IntCtrl_SVCall;
    // IntCtrl_PendSV;
    // IntCtrl_SysTick;
    // // processor exceptions
    const uint8 IntCtrl_GPIO_PORT_A;
    const uint8 IntCtrl_GPIO_PORT_B;
    const uint8 IntCtrl_GPIO_PORT_C;
    const uint8 IntCtrl_GPIO_PORT_D;
    const uint8 IntCtrl_GPIO_PORT_E;
    const uint8 IntCtrl_UART0;
    const uint8 IntCtrl_UART1;
    const uint8 IntCtrl_SSI0;
    const uint8 IntCtrl_I2C0;
    const uint8 IntCtrl_PWM0_Fault;
    const uint8 IntCtrl_PWM0_Generator_0;
    const uint8 IntCtrl_PWM0_Generator_1;
    const uint8 IntCtrl_PWM0_Generator_2;
    const uint8 IntCtrl_QEI0;
    const uint8 IntCtrl_ADC0_Sequence_0;
    const uint8 IntCtrl_ADC0_Sequence_1;
    const uint8 IntCtrl_ADC0_Sequence_2;
    const uint8 IntCtrl_ADC0_Sequence_3;
    const uint8 IntCtrl_Watchdog_Timers_0_and_1;
    const uint8 IntCtrl_16_32_Bit_Timer_0A;
    const uint8 IntCtrl_16_32_Bit_Timer_0B;
    const uint8 IntCtrl_16_32_Bit_Timer_1A;
    const uint8 IntCtrl_16_32_Bit_Timer_1B;
    const uint8 IntCtrl_16_32_Bit_Timer_2A;
    const uint8 IntCtrl_16_32_Bit_Timer_2B;
    const uint8 IntCtrl_Analog_Comparator_0;
    const uint8 IntCtrl_Analog_Comparator_1;
    const uint8;
    const uint8 IntCtrl_System_Control;
    const uint8 IntCtrl_Flash_Memory_Control_and_EEPROM_Control;
    const uint8 IntCtrl_GPIO_Port_F;
    const uint8;
    const uint8;
    const uint8 IntCtrl_UART2;
    const uint8 IntCtrl_SSI1;
    const uint8 IntCtrl_16_32_Bit_Timer_3A;
    const uint8 IntCtrl_16_32_Bit_Timer_3B;
    const uint8 IntCtrl_I2C1;
    const uint8 IntCtrl_QEI1;
    const uint8 IntCtrl_CAN0;
    const uint8 IntCtrl_CAN1;
    const uint8;
    const uint8;
    const uint8 IntCtrl_Hibernation_Module;
    const uint8 IntCtrl_USB;
    const uint8 IntCtrl_PWM_Generator_3;
    const uint8 IntCtrl_µDMA_Software;
    const uint8 IntCtrl_µDMA_Error;
    const uint8 IntCtrl_ADC1_Sequence_0;
    const uint8 IntCtrl_ADC1_Sequence_1;
    const uint8 IntCtrl_ADC1_Sequence_2;
    const uint8 IntCtrl_ADC1_Sequence_3;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8 IntCtrl_SSI2;
    const uint8 IntCtrl_SSI3;
    const uint8 IntCtrl_UART3;
    const uint8 IntCtrl_UART4;
    const uint8 IntCtrl_UART5;
    const uint8 IntCtrl_UART6;
    const uint8 IntCtrl_UART7;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8 IntCtrl_I2C2;
    const uint8 IntCtrl_I2C3;
    const uint8 IntCtrl_16_32_Bit_Timer_4A;
    const uint8 IntCtrl_16_32_Bit_Timer_4B;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8;
    const uint8 IntCtrl_16_32_Bit_Timer_5A;
    const uint8 IntCtrl_16_32_Bit_Timer_5B;
    const uint8 IntCtrl_32_64_Bit_Timer_0A;
    const uint8 IntCtrl_32_64_Bit_Timer_0B;
    const uint8 IntCtrl_32_64_Bit_Timer_1A;
} IntCtrl_InterruptChannelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
