/**
 * @file main.c
 * @brief Main module of this project
 */

#include "type.h"
#include "base.h"
#include "gpio.h"
#include "timer.h"
#include "arm_timer.h"
#include "interrupts.h"
#include "aux.h"
#include "serial.h"
#include "led.h"

int kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
	UCHAR buf[256] = {0};

	ENABLE_LED();

	GetInterruptRegister()->Enable_Basic_IRQs = ARM_TIMER_IRQ;
	
	GetArmTimer()->Load = 0x400; // interrupt period
	GetArmTimer()->Control = ARM_TIMER_CTRL_COUNTER_23BIT |
														ARM_TIMER_CTRL_PRESCALE_256 |
														ARM_TIMER_CTRL_EI |
														ARM_TIMER_CTRL_ENABLE_TIMER;

	SerialInit();

	EI();

	while(1) {
	
		PutString("currantOS> ", sizeof("currantOS> "));
	  GetString(buf, 256);
	}
}
