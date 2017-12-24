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

int kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
	uint08 buf[256] = {0};

	GetGpioRegister()->LED_GPFSEL |= LED_GPFBIT;

	GetInterruptRegister()->Enable_Basic_IRQs = ARM_TIMER_IRQ;
	
	GetArmTimer()->Load = 0x400; // interrupt period
	GetArmTimer()->Control = ARM_TIMER_CTRL_COUNTER_23BIT |
														ARM_TIMER_CTRL_PRESCALE_256 |
														ARM_TIMER_CTRL_EI |
														ARM_TIMER_CTRL_ENABLE_TIMER;

	AuxMiniUartInit(115200, 8);

	EI();

	while(1) {
	
		//DI();
		PutString("muraak> ", 8);
	  GetString(buf, 256);
		//EI();
		//Wait_us(1000);
	}
}
