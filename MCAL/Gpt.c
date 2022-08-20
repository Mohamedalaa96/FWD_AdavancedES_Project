/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief Static Code implementation of Gpt timer Driver
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt.h"
#include "Gpt_Registers.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
// Pointer to Call back functions of Notifications
void (*Gpt_Notification_Channel[12])(void) = {NULL_PTR};
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
 * \Syntax          : Std_ReturnType Gpt_Init(const Gpt_ConfigType *ConfigPtr)
 * \Description     : Initialize the timer and its hardware parameters from ConfigPtr, and start predefined timers
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : *ConfigPtr   pointer to configuration struct of the type Gpt_ConfigType
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
Std_ReturnType Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + ConfigPtr->GptChannelId));

    timer_register_ptr->GPTMIMR = 0; // Disable Interrupt for this channel

    // set the call back function to the notifications
    Gpt_Notification_Channel[ConfigPtr->GptChannelId] = ConfigPtr->GptNotification;

    // TODO: change this to bit banding access?

    // Normal Mode - not concatenated
    timer_register_ptr->GPTMCFG = 0x4;
    // Up counting Mode
    timer_register_ptr->GPTMTAMR = 1 << 4;

    // Single Shot mode or Continuous
    if (ConfigPtr->GptChannelMode == GPT_CH_MODE_CONTINUOUS)
    {
        timer_register_ptr->GPTMTAMR = 0x2; // Continuous //bit 0,1
    }
    else
    {
        timer_register_ptr->GPTMTAMR = 0x1; // one shoot //bit 0,1
    }

    // 16 bit mode is the only supported
    //  pre scaler (16 bit mode, use 0:7 only) in extension mode
    uint8 prescalerValue = ((ConfigPtr->GptChannelTickValueMax & ~((uint32)0xFF00FFFF)) >> 16);
    timer_register_ptr->GPTMTAPR = prescalerValue; // take the bits > 16 bit max value

    // TODO: How to set Frequancy?
    // ConfigPtr->GptChannelTickFrequency
    return E_OK;
}

/******************************************************************************
 * \Syntax          : Std_ReturnType Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType value)
 * \Description     : Start the Timer already configured by Gpt_Init with certain time
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel   ChannelID to start
 * \Parameters (in) : Gpt_ValueType value   Desired no. of ticks
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
Std_ReturnType Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType value)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));

    timer_register_ptr->GPTMTAILR = (uint16)value;

    timer_register_ptr->GPTMCTL = 1; // TAEN bit 0 , enable timer
    return E_OK;
}

/******************************************************************************
 * \Syntax          : Std_ReturnType Gpt_StopTimer(Gpt_ChannelType Channel)
 * \Description     : Stop the Timer already configured by Gpt_Init and Started
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel   ChannelID to stop
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
Std_ReturnType Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));
    timer_register_ptr->GPTMCTL = 0; // TAEN bit 0 , enable timer
    return E_OK;
}

/******************************************************************************
 * \Syntax          : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
 * \Description     : Get the Time elapsed from the starting
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel Channel ID
 * \Parameters (out): None
 * \Return value:   : Gpt_ValueType   0 : 2^32 - 1
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));
    return ((Gpt_ValueType)timer_register_ptr->GPTMTAV);
}

/******************************************************************************
 * \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
 * \Description     : Get the Time remaining before the notification
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel Channel ID
 * \Parameters (out): None
 * \Return value:   : Gpt_ValueType   0 : 2^32 - 1
 *******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));
    return ((Gpt_ValueType)timer_register_ptr->GPTMTAV);
}

/******************************************************************************
 * \Syntax          : Std_ReturnType Gpt_EnableNotifications(Gpt_ChannelType Channel)
 * \Description     : Enable Timer channel n when timeout (Expired)
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
Std_ReturnType Gpt_EnableNotifications(Gpt_ChannelType Channel)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));
    timer_register_ptr->GPTMIMR = 1; // TAEN bit 0 , enable interrupt timeout
}

/******************************************************************************
 * \Syntax          : Std_ReturnType Gpt_DisableNotifications(Gpt_ChannelType Channel)
 * \Description     : Disable Timer channel n when timeout (Expired)
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Gpt_ChannelType Channel
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
Std_ReturnType Gpt_DisableNotifications(Gpt_ChannelType Channel)
{
    Gpt_RegisterType *timer_register_ptr = ((Gpt_RegisterType *)(GPT_TIMER_BASE_ADDRESS + Channel));
    timer_register_ptr->GPTMIMR = 0; // TAEN bit 0 , enable interrupt timeout
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER0(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER0(void)
{
    if (Gpt_Notification_Channel[0] != NULL_PTR)
        Gpt_Notification_Channel[0]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER1(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER1(void)
{
    if (Gpt_Notification_Channel[1] != NULL_PTR)
        Gpt_Notification_Channel[1]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER2(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER2(void)
{
    if (Gpt_Notification_Channel[2] != NULL_PTR)
        Gpt_Notification_Channel[2]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER3(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER3(void)
{
    if (Gpt_Notification_Channel[3] != NULL_PTR)
        Gpt_Notification_Channel[3]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER4(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER4(void)
{
    if (Gpt_Notification_Channel[4] != NULL_PTR)
        Gpt_Notification_Channel[4]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER5(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER5(void)
{
    if (Gpt_Notification_Channel[5] != NULL_PTR)
        Gpt_Notification_Channel[5]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER6(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER6(void)
{
    if (Gpt_Notification_Channel[6] != NULL_PTR)
        Gpt_Notification_Channel[6]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER7(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER7(void)
{
    if (Gpt_Notification_Channel[7] != NULL_PTR)
        Gpt_Notification_Channel[7]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER8(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER8(void)
{
    if (Gpt_Notification_Channel[8] != NULL_PTR)
        Gpt_Notification_Channel[8]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER9(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER9(void)
{
    if (Gpt_Notification_Channel[9] != NULL_PTR)
        Gpt_Notification_Channel[9]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER10(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER10(void)
{
    if (Gpt_Notification_Channel[10] != NULL_PTR)
        Gpt_Notification_Channel[10]();
}

/******************************************************************************
 * \Syntax          : void IRQ_TIMER11(void)
 * \Description     : Interrupt Handler for TIMER0 timeout
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void IRQ_TIMER11(void)
{
    if (Gpt_Notification_Channel[11] != NULL_PTR)
        Gpt_Notification_Channel[11]();
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
