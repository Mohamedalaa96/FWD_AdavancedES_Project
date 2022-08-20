/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Registers.h
 *       Module:  Gpt
 *
 *  Description:  Gpt Driver Registers file
 *
 *********************************************************************************************************************/
#ifndef GPT_REGISTERS_H
#define GPT_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_TIMER_BASE_ADDRESS 0x40030000

#define GPT_TIMER0_OFFSET 0x00000000
#define GPT_TIMER1_OFFSET 0x00001000
#define GPT_TIMER2_OFFSET 0x00002000
#define GPT_TIMER3_OFFSET 0x00003000
#define GPT_TIMER4_OFFSET 0x00004000
#define GPT_TIMER5_OFFSET 0x00005000
#define GPT_TIMER6_OFFSET 0x00006000
#define GPT_TIMER7_OFFSET 0x00007000
#define GPT_TIMER8_OFFSET 0x0001C000
#define GPT_TIMER9_OFFSET 0x0001D000
#define GPT_TIMER10_OFFSET 0x0001E000
#define GPT_TIMER11_OFFSET 0x0001F000

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct
{
    uint32 GPTMCFG;      // RW 0x0000.0000 GPTM Configuration 727
    uint32 GPTMTAMR;     // RW 0x0000.0000 GPTM Timer A Mode 729
    uint32 GPTMTBMR;     // RW 0x0000.0000 GPTM Timer B Mode 733
    uint32 GPTMCTL;      // RW 0x0000.0000 GPTM Control 737
    uint32 GPTMSYNC;     // RW 0x0000.0000 GPTM Synchronize 741
    uint32 _RESERVED;    // reserved
    uint32 GPTMIMR;      // RW 0x0000.0000 GPTM Interrupt Mask 745
    uint32 GPTMRIS;      // RO 0x0000.0000 GPTM Raw Interrupt Status 748
    uint32 GPTMMIS;      // RO 0x0000.0000 GPTM Masked Interrupt Status 751
    uint32 GPTMICR;      // W1C 0x0000.0000 GPTM Interrupt Clear 754
    uint32 GPTMTAILR;    // RW 0xFFFF.FFFF GPTM Timer A Interval Load 756
    uint32 GPTMTBILR;    // RW - GPTM Timer B Interval Load 757
    uint32 GPTMTAMATCHR; // RW 0xFFFF.FFFF GPTM Timer A Match 758
    uint32 GPTMTBMATCHR; // RW - GPTM Timer B Match 759
    uint32 GPTMTAPR;     // RW 0x0000.0000 GPTM Timer A Prescale 760
    uint32 GPTMTBPR;     // RW 0x0000.0000 GPTM Timer B Prescale 761
    uint32 GPTMTAPMR;    // RW 0x0000.0000 GPTM TimerA Prescale Match 762
    uint32 GPTMTBPMR;    // RW 0x0000.0000 GPTM TimerB Prescale Match 763
    uint32 GPTMTAR;      // RO 0xFFFF.FFFF GPTM Timer A 764
    uint32 GPTMTBR;      // RO - GPTM Timer B 765
    uint32 GPTMTAV;      // RW 0xFFFF.FFFF GPTM Timer A Value 766
    uint32 GPTMTBV;      // RW - GPTM Timer B Value 767
    uint32 GPTMRTCPD;    // RO 0x0000.7FFF GPTM RTC Predivide 768
    uint32 GPTMTAPS;     // RO 0x0000.0000 GPTM Timer A Prescale Snapshot 769
    uint32 GPTMTBPS;     // RO 0x0000.0000 GPTM Timer B Prescale Snapshot 770
    uint32 GPTMTAPV;     // RO 0x0000.0000 GPTM Timer A Prescale Value 771
    uint32 GPTMTBPV;     // RO 0x0000.0000 GPTM Timer B Prescale Value 772
    uint32 GPTMPP;       // RO 0x0000.0000 GPTM Peripheral Properties
} Gpt_RegisterType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* GPT_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Registers.h
 *********************************************************************************************************************/
