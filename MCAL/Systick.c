/*****************************************************************************************************/
/* Author       : Mohamed Alaa                                                                       */
/* Version      : 19 April 2021                                                                      */
/* Version      : V03                                                                                */
/*****************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

static void (*MSTK_Callback)(void); // Pointer to function
static uint8 MSTK_intervalMode = 0; // variable to indicate its priodic or not

void MSTK_voidInit(void)
{

#if MSYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV_8
    STK->CTRL = 0x00000000;
#elif MSYSTICK_CLOCK_SOURCE == SYSTICK_AHB
    STK->CRTL = 0x00000040;
#else
#error "Wrong Choice Prescaller!"
#endif
}

// Delay and hold the CPU for few cycles.
void MSTK_voidSetBusyWait(uint32 copy_uint32Ticks)
{
#if copy_uint32Ticks > 0x00FFFFFF
#error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
#else
    STK->LOAD = copy_uint32Ticks;
    SET_BIT(STK->CTRL, MSTK_ENABLE_BIT); // Enable Counter
    while (GET_BIT(STK->CTRL, 16) == 0)
    {
        __asm("NOP");
    }                                    // Pooling on the Count flag
    CLR_BIT(STK->CTRL, MSTK_ENABLE_BIT); // Disable Counter
    STK->LOAD = 0;
    STK->VAL = 0;
#endif
}
/* Set single interval , after done call the function provided */
void MSTK_voidSetIntervalSingle(uint32 copy_uint32Ticks, void (*copy_ptr)(void))
{
#if copy_uint32Ticks > 0x00FFFFFF
#error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
#else
    MSTK_intervalMode = MSTK_SINGLE_INTERVAL; // Non Priodic
    STK->LOAD = copy_uint32Ticks;
    SET_BIT(STK->CTRL, MSTK_ENABLE_BIT); // Enable Counter
    MSTK_Callback = copy_ptr;

    SET_BIT(STK->CTRL, MSTK_TICK_INT_BIT);    // Enable Interrupt.

#endif
}
void MSTK_voidSetIntervalPeriodic(uint32 copy_uint32Ticks, void (*copy_ptr)(void))
{
#if copy_uint32Ticks > 0x00FFFFFF
#error "MAX TICKS in MSTK_voidSetBusyWait exceeded max is 0x00FFFFFF "
#else
    MSTK_intervalMode = MSTK_PERIOD_INTERVAL; // Non Priodic
    STK->LOAD = copy_uint32Ticks;
    SET_BIT(STK->CTRL, MSTK_ENABLE_BIT); // Enable Counter
    MSTK_Callback = copy_ptr;
    SET_BIT(STK->CTRL, MSTK_TICK_INT_BIT); // Enable Interrupt.

#endif
}
void MSTK_voidStopInterval(void)
{

    CLR_BIT(STK->CTRL, MSTK_ENABLE_BIT);   // Disable Counter
    CLR_BIT(STK->CTRL, MSTK_TICK_INT_BIT); // Disable Interrupt.
    STK->LOAD = 0;
    STK->VAL = 0;
}
uint32 MSTK_uint32GetElapsedTicks(void)
{
    uint32 LOCAL_uint32ElapsedTicks = 0;
    LOCAL_uint32ElapsedTicks = (STK->LOAD - STK->VAL);
    return LOCAL_uint32ElapsedTicks;
}
uint32 MSTK_uint32GetRemainingTicks(void)
{
    uint32 LOCAL_uint32RemainingTick = 0;
    LOCAL_uint32RemainingTick = STK->VAL;
    return LOCAL_uint32RemainingTick;
}
void SysTick_Handler(void)
{
    uint8 Local_uint8Temp = 0;

    if (MSTK_intervalMode == MSTK_SINGLE_INTERVAL)
    {

        CLR_BIT(STK->CTRL, MSTK_TICK_INT_BIT); // Disable Interrupt.
        CLR_BIT(STK->CTRL, MSTK_ENABLE_BIT);   // Stop Counting.

        STK->LOAD = 0;
        STK->VAL = 0;
    }
    MSTK_Callback();
    /*	Clear	interrupt Flag					*/
    Local_uint8Temp = GET_BIT(STK->CTRL, 16);
}
