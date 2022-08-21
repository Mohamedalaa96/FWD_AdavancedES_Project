/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MCU_Registers.h
 *       Module:  MCU
 *
 *  Description:  MCU Driver Registers file
 *
 *********************************************************************************************************************/
#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PERIPHERALS_ALIAS_START 0x42000000
#define MCU_BASE_OFFSET 0x000FE000

#define MCU_BIT_ACCESS(REG, BIT_NUM) (*(uint32 *)BIT_BANDING(PERIPHERALS_ALIAS_START, (MCU_BASE_OFFSET + REG), BIT_NUM))

#define MCU_BASE_ADDRESS ((IO_REG_PTR)0x400FE000)

#define DID0_OFFSET 0x000       // RO - Device Identification 0 238
#define DID1_OFFSET 0x004       // RO_OFFSET 0x10A1.606E Device Identification 1 240
#define PBORCTL_OFFSET 0x030    // RW 0x0000.7FFF Brown-Out Reset Control 243
#define RIS_OFFSET 0x050        // RO 0x0000.0000 Raw Interrupt Status 244
#define IMC_OFFSET 0x054        // RW 0x0000.0000 Interrupt Mask Control 247
#define MISC_OFFSET 0x058       // RW1C 0x0000.0000 Masked Interrupt Status and Clear 249
#define MISC_OFFSET 0x058       // RW1C 0x0000.0000 Masked Interrupt Status and Clear 249
#define RESC_OFFSET 0x05C       // RW - Reset Cause 252
#define RCC_OFFSET 0x060        // RW 0x078E.3AD1 Run-Mode Clock Configuration 254
#define GPIOHBCTL_OFFSET 0x06C  // RW 0x0000.7E00 GPIO High-Performance Bus Control 258
#define RCC2_OFFSET 0x070       // RW 0x07C0.6810 Run-Mode Clock Configuration 2 260
#define MOSCCTL_OFFSET 0x07C    // RW 0x0000.0000 Main Oscillator Control 263
#define DSLPCLKCFG_OFFSET 0x144 // RW 0x0780.0000 Deep Sleep Clock Configuration 264
#define SYSPROP_OFFSET 0x14C    // RO 0x0000.1D31 System Properties 266
#define PIOSCCAL_OFFSET 0x150   // RW 0x0000.0000 Precision Internal Oscillator Calibration 268
#define PIOSCSTAT_OFFSET 0x154  // RO 0x0000.0040 Precision Internal Oscillator Statistics 270
#define PLLFREQ0_OFFSET 0x160   // RO 0x0000.0032 PLL Frequency 0 271
#define PLLFREQ1_OFFSET 0x164   // RO 0x0000.0001 PLL Frequency 1 272
#define PLLSTAT_OFFSET 0x168    // RO 0x0000.0000 PLL Status 273
#define SLPPWRCFG_OFFSET 0x188  // RW 0x0000.0000 Sleep Power Configuration 274
#define DSLPPWRCFG_OFFSET 0x18C // RW 0x0000.0000 Deep-Sleep Power Configuration 276
#define LDOSPCTL_OFFSET 0x1B4   // RW 0x0000.0018 LDO Sleep Power Control 278
#define LDOSPCAL_OFFSET 0x1B8   // RO 0x0000.1818 LDO Sleep Power Calibration 280
#define LDODPCTL_OFFSET 0x1BC   // RW 0x0000.0012 LDO Deep-Sleep Power Control 281
#define LDODPCAL_OFFSET 0x1C0   // RO 0x0000.1212 LDO Deep-Sleep Power Calibration 283
#define SDPMST_OFFSET 0x1CC     // RO 0x0000.0000 Sleep / Deep-Sleep Power Mode Status 284
#define PPWD_OFFSET 0x300       // RO 0x0000.0003 Watchdog Timer Peripheral Present 287
#define PPTIMER_OFFSET 0x304    // RO 0x0000.003F 16/32-Bit General-Purpose Timer Peripheral Present 288
#define PPGPIO_OFFSET 0x308     // RO 0x0000.003F General-Purpose Input/Output Peripheral Present 290
#define PPDMA_OFFSET 0x30C      // RO_OFFSET 0x0000.0001 Micro Direct Memory Access Peripheral Present 2

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
