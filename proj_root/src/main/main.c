/**
 * @file main.c
 * @brief Main module of this project
 */

#include "type.h"
#include "timer.h"
#include "arm_timer.h"
#include "interrupts.h"
#include "led.h"
#include "console.h"

int kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
	ENABLE_LED();

	InterruptInit();
	
	GetArmTimer()->Load = 0x400; // interrupt period
	GetArmTimer()->Control = ARM_TIMER_CTRL_COUNTER_23BIT |
														ARM_TIMER_CTRL_PRESCALE_256 |
														ARM_TIMER_CTRL_EI |
														ARM_TIMER_CTRL_ENABLE_TIMER;

	ConsoleInit();

	EI();

	while(1) {}
}
