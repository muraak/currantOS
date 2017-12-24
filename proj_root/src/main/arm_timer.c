#include "arm_timer.h"

arm_timer_t* GetArmTimer(void)
{
	return (arm_timer_t*)ARM_TIMER_ADDRESS;
}
