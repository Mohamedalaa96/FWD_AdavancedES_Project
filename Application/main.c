
#include "Std_Types.h"
#include "Bit_Math.h"

#include "Port.h"
#include "Dio.h"
#include "SysTick_interface.h"
#include "IntCtrl.h"
uint8 led_status = 0xFF;

uint16 time_on = 1000;
uint16 time_off = 1000;

void TimerHandler(void)
{
    if (led_status == 0x00)
    {
        MSTK_voidSetIntervalPeriodic(time_off * TICK_TO_SEC, TimerHandler);
        led_status = 0xFF;
    }
    else // prev was ON 0xff
    {
        MSTK_voidSetIntervalPeriodic(time_on * TICK_TO_SEC, TimerHandler);
        led_status = 0x00;
    }
}

int main(void)
{

    IntCtrl_Init();

    MSTK_voidInit();
    MSTK_voidSetIntervalPeriodic(time_off * TICK_TO_SEC, TimerHandler);
    led_status = 0xFF; // set status to Off

    while (1)
    {
        LED_BlinkRunner(led_status);
    }
}
