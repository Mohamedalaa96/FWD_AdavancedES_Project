/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Registers.h
 *       Module:  GPIO
 *
 *  Description:  GPIO Registers file
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

#define GPIO_PORT_A_BASE ((uint32)0x40004000)
#define GPIO_PORT_B_BASE ((uint32)0x40005000)
#define GPIO_PORT_C_BASE ((uint32)0x40006000)
#define GPIO_PORT_D_BASE ((uint32)0x40007000)
#define GPIO_PORT_E_BASE ((uint32)0x40024000)
#define GPIO_PORT_F_BASE ((uint32)0x40025000)

/* using bit banding */
#define GPIODATA_OFFSET (0x3FC)   /* 0x00 due to in simulation p. 654 bit masking  RW 0x0000.0000 GPIO Data 662*/
#define GPIODIR_OFFSET (0x400)    /* RW 0x0000.0000 GPIO Direction 663*/
#define GPIOIS_OFFSET (0x404)     /* RW 0x0000.0000 GPIO Interrupt Sense 664*/
#define GPIOIBE_OFFSET (0x408)    /* RW 0x0000.0000 GPIO Interrupt Both Edges 665*/
#define GPIOIEV_OFFSET (0x40C)    /* RW 0x0000.0000 GPIO Interrupt Event 666*/
#define GPIOIM_OFFSET (0x410)     /* RW 0x0000.0000 GPIO Interrupt Mask 667*/
#define GPIORIS_OFFSET (0x414)    /* RO 0x0000.0000 GPIO Raw Interrupt Status 668*/
#define GPIOMIS_OFFSET (0x418)    /* RO 0x0000.0000 GPIO Masked Interrupt Status 669 */
#define GPIOICR_OFFSET (0x41C)    /* W1C 0x0000.0000 GPIO Interrupt Clear 670*/
#define GPIOAFSEL_OFFSET (0x420)  /* RW - GPIO Alternate Function Select 671*/
#define GPIODR2R_OFFSET (0x500)   /* RW 0x0000.00FF GPIO 2-mA Drive Select 673*/
#define GPIODR4R_OFFSET (0x502)   /* RW 0x0000.0000 GPIO 4-mA Drive Select 674*/
#define GPIODR8R_OFFSET (0x508)   /* RW 0x0000.0000 GPIO 8-mA Drive Select 675*/
#define GPIOODR_OFFSET (0x50C)    /* RW 0x0000.0000 GPIO Open Drain Select 676*/
#define GPIOPUR_OFFSET (0x510)    /* RW - GPIO Pull-Up Select 677*/
#define GPIOPDR_OFFSET (0x514)    /* RW 0x0000.0000 GPIO Pull-Down Select 679*/
#define GPIOSLR_OFFSET (0x518)    /* RW 0x0000.0000 GPIO Slew Rate Control Select 681*/
#define GPIODEN_OFFSET (0x51C)    /* RW - GPIO Digital Enable 682*/
#define GPIOLOCK_OFFSET (0x520)   /* RW 0x0000.0001 GPIO Lock 684*/
#define GPIOCR_OFFSET (0x524)     /*- - GPIO Commit 685 */
#define GPIOAMSEL_OFFSET (0x528)  /* RW 0x0000.0000 GPIO Analog Mode Select 687*/
#define GPIOPCTL_OFFSET (0x52C)   /* RW - GPIO Port Control 688*/
#define GPIOADCCTL_OFFSET (0x530) /* RW 0x0000.0000 GPIO ADC Control 690*/
#define GPIODMACTL_OFFSET (0x534) /* RW 0x0000.0000 GPIO DMA Control 691*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GPIO_BIT_ACCESS(BASE, REG_OFFSET, BIT_NUM) (*(IO_REG_PTR)(BIT_BANDING(PERIPHERALS_ALIAS_START, (BASE + REG_OFFSET), BIT_NUM)))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* GPIO_REGISTERS_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Registers.h
 *********************************************************************************************************************/
