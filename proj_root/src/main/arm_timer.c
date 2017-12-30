#include "arm_timer.h"
#include "led.h"

arm_timer_t* GetArmTimer(void)
{
	return (arm_timer_t*)ARM_TIMER_ADDRESS;
}

void ArmTimerInterruptHandler(void)
{
	static BOOL lit = false;

	if(lit) {
		LED_OFF();
		lit = 0;
	}
	else {
		LED_ON();
		lit = 1;
	}

}

