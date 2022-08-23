/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const IntCtrl_InterruptStatusType IntCtrlChannels;
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
 * \Syntax          : IntCtrl_Init(void)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Description
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void IntCtrl_Init(void)
{
    // APINT  // clear the bits of PRIGROUP
    (*(IO_REG_PTR)(0xE000E000 + 0xD0C)) &= (~(0x7 << 8));

#if (INTCTRL_GROUPING_TYPE == INTCTRL_8_GRROUP_1_SUB)
    (*(IO_REG_PTR)(0xE000E000 + 0xD0C)) |= (0x4 << 8);
#elif (INTCTRL_GROUPING_TYPE == INTCTRL_4_GRROUP_2_SUB)
    (*(IO_REG_PTR)(0xE000E000 + 0xD0C)) |= (0x5 << 8);
#elif (INTCTRL_GROUPING_TYPE == INTCTRL_2_GRROUP_4_SUB)
    (*(IO_REG_PTR)(0xE000E000 + 0xD0C)) |= (0x6 << 8);
#elif (INTCTRL_GROUPING_TYPE == INTCTRL_1_GRROUP_8_SUB)
    (*(IO_REG_PTR)(0xE000E000 + 0xD0C)) |= (0x7 << 8);
#else
#error "Wrong Configurations in IntCtr Grouping "
#endif
    // Enable interrupts from user configurations
    uint8 length_of_struct = sizeof(IntCtrl_InterruptStatusType);
    uint8 *ptr_to_struct = &IntCtrlChannels;
    volatile uint32 ptr_enable_register = 0;
    volatile uint8 bit_number = 0;
    for (uint8 counter = 0; counter < length_of_struct; counter++)
    {
        if (ptr_to_struct[counter] != 0) // skip reserved bits
        {
            if (counter < 31)
            {
                ptr_enable_register = 0x100;
                bit_number = counter;
            }
            else if (counter < 63)
            {
                ptr_enable_register = 0x104;
                bit_number = counter - 31;
            }
            else if (counter < 95)
            {
                ptr_enable_register = 0x108;
                bit_number = counter - 63;
            }
            else if (counter < 127)
            {
                ptr_enable_register = 0x10C;
                bit_number = counter - 95;
            }
            else if (counter < 138)
            {
                ptr_enable_register = 0x110;
                bit_number = counter - 127;
            }

            if (ptr_to_struct[counter] == INTCTRL_STATE_ENABLED)
            {
                (*(IO_REG_PTR)(0xE000E000 + ptr_enable_register)) |= 1 << bit_number;
            }
            else
            {
                (*(IO_REG_PTR)(0xE000E000 + ptr_enable_register)) &= ~(1 << bit_number);
            }
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
