/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief Interrupt Control Driver Link-time configurations
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const IntCtrl_InterruptStatusType IntCtrlChannels = {
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_PORT_A
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_PORT_B
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_PORT_C
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_PORT_D
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_PORT_E
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART0
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART1
    INTCTRL_STATE_DISABLED, //.IntCtrl_SSI0
    INTCTRL_STATE_DISABLED, //.IntCtrl_I2C0
    INTCTRL_STATE_DISABLED, //.IntCtrl_PWM0_Fault
    INTCTRL_STATE_DISABLED, //.IntCtrl_PWM0_Generator_0
    INTCTRL_STATE_DISABLED, //.IntCtrl_PWM0_Generator_1
    INTCTRL_STATE_DISABLED, //.IntCtrl_PWM0_Generator_2
    INTCTRL_STATE_DISABLED, //.IntCtrl_QEI0
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC0_Sequence_0
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC0_Sequence_1
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC0_Sequence_2
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC0_Sequence_3
    INTCTRL_STATE_DISABLED, //.IntCtrl_Watchdog_Timers_0_and_1
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_0A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_0B
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_1A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_1B
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_2A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_2B
    INTCTRL_STATE_DISABLED, //.IntCtrl_Analog_Comparator_0
    INTCTRL_STATE_DISABLED, //.IntCtrl_Analog_Comparator_1
    INTCTRL_STATE_DISABLED, //.IntCtrl_System_Control
    INTCTRL_STATE_DISABLED, //.IntCtrl_Flash_Memory_Control_and_EEPROM_Control
    INTCTRL_STATE_DISABLED, //.IntCtrl_GPIO_Port_F
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART2
    INTCTRL_STATE_DISABLED, //.IntCtrl_SSI1
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_3A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_3B
    INTCTRL_STATE_DISABLED, //.IntCtrl_I2C1
    INTCTRL_STATE_DISABLED, //.IntCtrl_QEI1
    INTCTRL_STATE_DISABLED, //.IntCtrl_CAN0
    INTCTRL_STATE_DISABLED, //.IntCtrl_CAN1
    INTCTRL_STATE_DISABLED, //.IntCtrl_Hibernation_Module
    INTCTRL_STATE_DISABLED, //.IntCtrl_USB
    INTCTRL_STATE_DISABLED, //.IntCtrl_PWM_Generator_3
    INTCTRL_STATE_DISABLED, //.IntCtrl_µDMA_Software
    INTCTRL_STATE_DISABLED, //.IntCtrl_µDMA_Error
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC1_Sequence_0
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC1_Sequence_1
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC1_Sequence_2
    INTCTRL_STATE_DISABLED, //.IntCtrl_ADC1_Sequence_3
    INTCTRL_STATE_DISABLED, //.IntCtrl_SSI2
    INTCTRL_STATE_DISABLED, //.IntCtrl_SSI3
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART3
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART4
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART5
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART6
    INTCTRL_STATE_DISABLED, //.IntCtrl_UART7
    INTCTRL_STATE_DISABLED, //.IntCtrl_I2C2
    INTCTRL_STATE_DISABLED, //.IntCtrl_I2C3
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_4A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_4B
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_5A
    INTCTRL_STATE_DISABLED, //.IntCtrl_16_32_Bit_Timer_5B
    INTCTRL_STATE_DISABLED, //.IntCtrl_32_64_Bit_Timer_0A
    INTCTRL_STATE_DISABLED, //.IntCtrl_32_64_Bit_Timer_0B
    INTCTRL_STATE_DISABLED  //.IntCtrl_32_64_Bit_Timer_1A
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
