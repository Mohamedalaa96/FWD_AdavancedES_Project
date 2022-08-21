/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Registers.h
 *       Module:  MCU
 *
 *  Description:  MCU Driver Registers file
 *
 *********************************************************************************************************************/
#ifndef GPIO_REGISTERS_H
#define GPIO_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PERIPHERALS_ALIAS_START 0x42000000

#define GPIO_PORT_A_BASE ((IO_REG_PTR)0x40004000)
#define GPIO_PORT_B_BASE ((IO_REG_PTR)0x40005000)
#define GPIO_PORT_C_BASE ((IO_REG_PTR)0x40006000)
#define GPIO_PORT_D_BASE ((IO_REG_PTR)0x40007000)
#define GPIO_PORT_E_BASE ((IO_REG_PTR)0x40024000)
#define GPIO_PORT_F_BASE ((IO_REG_PTR)0x40025000)

// using bit banding
#define GPIO_BIT_ACCESS(BASE, REG_OFFSET, BIT_NUM) (*(IO_REG_PTR)BIT_BANDING(PERIPHERALS_ALIAS_START, (BASE + REG_OFFSET), BIT_NUM))

#define GPIODATA_OFFSET ((IO_REG_PTR)0x3FC)   // 0x00 due to in simulation p. 654 bit masking // RW 0x0000.0000 GPIO Data 662
#define GPIODIR_OFFSET ((IO_REG_PTR)0x400)    // RW 0x0000.0000 GPIO Direction 663
#define GPIOIS_OFFSET ((IO_REG_PTR)0x404)     // RW 0x0000.0000 GPIO Interrupt Sense 664
#define GPIOIBE_OFFSET ((IO_REG_PTR)0x408)    // RW 0x0000.0000 GPIO Interrupt Both Edges 665
#define GPIOIEV_OFFSET ((IO_REG_PTR)0x40C)    // RW 0x0000.0000 GPIO Interrupt Event 666
#define GPIOIM_OFFSET ((IO_REG_PTR)0x410)     // RW 0x0000.0000 GPIO Interrupt Mask 667
#define GPIORIS_OFFSET ((IO_REG_PTR)0x414)    // RO 0x0000.0000 GPIO Raw Interrupt Status 668
#define GPIOMIS_OFFSET ((IO_REG_PTR)0x418)    // RO 0x0000.0000 GPIO Masked Interrupt Status 669
#define GPIOICR_OFFSET ((IO_REG_PTR)0x41C)    // W1C 0x0000.0000 GPIO Interrupt Clear 670
#define GPIOAFSEL_OFFSET ((IO_REG_PTR)0x420)  // RW - GPIO Alternate Function Select 671
#define GPIODR2R_OFFSET ((IO_REG_PTR)0x500)   // RW 0x0000.00FF GPIO 2-mA Drive Select 673
#define GPIODR4R_OFFSET ((IO_REG_PTR)0x502)   // RW 0x0000.0000 GPIO 4-mA Drive Select 674
#define GPIODR8R_OFFSET ((IO_REG_PTR)0x508)   // RW 0x0000.0000 GPIO 8-mA Drive Select 675
#define GPIOODR_OFFSET ((IO_REG_PTR)0x50C)    // RW 0x0000.0000 GPIO Open Drain Select 676
#define GPIOPUR_OFFSET ((IO_REG_PTR)0x510)    // RW - GPIO Pull-Up Select 677
#define GPIOPDR_OFFSET ((IO_REG_PTR)0x514)    // RW 0x0000.0000 GPIO Pull-Down Select 679
#define GPIOSLR_OFFSET ((IO_REG_PTR)0x518)    // RW 0x0000.0000 GPIO Slew Rate Control Select 681
#define GPIODEN_OFFSET ((IO_REG_PTR)0x51C)    // RW - GPIO Digital Enable 682
#define GPIOLOCK_OFFSET ((IO_REG_PTR)0x520)   // RW 0x0000.0001 GPIO Lock 684
#define GPIOCR_OFFSET ((IO_REG_PTR)0x524)     //- - GPIO Commit 685
#define GPIOAMSEL_OFFSET ((IO_REG_PTR)0x528)  // RW 0x0000.0000 GPIO Analog Mode Select 687
#define GPIOPCTL_OFFSET ((IO_REG_PTR)0x52C)   // RW - GPIO Port Control 688
#define GPIOADCCTL_OFFSET ((IO_REG_PTR)0x530) // RW 0x0000.0000 GPIO ADC Control 690
#define GPIODMACTL_OFFSET ((IO_REG_PTR)0x534) // RW 0x0000.0000 GPIO DMA Control 691

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

#endif /* GPT_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Registers.h
 *********************************************************************************************************************/
