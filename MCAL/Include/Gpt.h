/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  Gpt
 *
 *  Description:  Gpt Driver header file
 *
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Gpt_Channel_Number_0 ((Gpt_ChannelType)GPT_TIMER0_OFFSET)
#define Gpt_Channel_Number_1 ((Gpt_ChannelType)GPT_TIMER1_OFFSET)
#define Gpt_Channel_Number_2 ((Gpt_ChannelType)GPT_TIMER2_OFFSET)
#define Gpt_Channel_Number_3 ((Gpt_ChannelType)GPT_TIMER3_OFFSET)
#define Gpt_Channel_Number_4 ((Gpt_ChannelType)GPT_TIMER4_OFFSET)
#define Gpt_Channel_Number_5 ((Gpt_ChannelType)GPT_TIMER5_OFFSET)
#define Gpt_Channel_Number_6 ((Gpt_ChannelType)GPT_TIMER6_OFFSET)
#define Gpt_Channel_Number_7 ((Gpt_ChannelType)GPT_TIMER7_OFFSET)
#define Gpt_Channel_Number_8 ((Gpt_ChannelType)GPT_TIMER8_OFFSET)
#define Gpt_Channel_Number_9 ((Gpt_ChannelType)GPT_TIMER9_OFFSET)
#define Gpt_Channel_Number_10 ((Gpt_ChannelType)GPT_TIMER10_OFFSET)
#define Gpt_Channel_Number_11 ((Gpt_ChannelType)GPT_TIMER11_OFFSET)
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

Std_ReturnType Gpt_Init(const Gpt_ConfigType *ConfigPtr);

/**
 * @brief Enable Notification of the specified channel
 *
 * @param Channel to enable notifications
 * @return Std_ReturnType
 */
Std_ReturnType Gpt_EnableNotifications(Gpt_ChannelType Channel);
/**
 * @brief
 *
 * @param Channel
 * @return Std_ReturnType
 */
Std_ReturnType Gpt_DisableNotifications(Gpt_ChannelType Channel);
/**
 * @brief
 *
 * @param Channel  channel to start, reset the old value , synchrounous, re-enterant
 * @param value    desired value to count to
 * @return Std_ReturnType
 */
Std_ReturnType Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType value);
/**
 * @brief Stop the timer , synchrounous, re-enterant (not for the same timer channel)
 * Reentrant -> avoiding read modifiy write operation
 *
 * @param Channel
 * @return Std_ReturnType
 */
Std_ReturnType Gpt_StopTimer(Gpt_ChannelType Channel);

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
/**
 * @brief Get predefinded timer value now
 *
 * @param PredefTimer   option from selction
 * @param TimeValuePtr  value to be returned
 * @return Std_ReturnType if predefined timer not enabled , or any error return NOK, else OK
 */
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32_t *TimeValuePtr);
// uses the prescaller, value , mask the used value only , tickfreq , max count needed
#endif /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
