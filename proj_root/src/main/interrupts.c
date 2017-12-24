
#include "type.h"
#include "interrupts.h"
#include "gpio.h"
#include "arm_timer.h"
#include "serial.h"

void EI(void)
{
	int tmp;
	asm volatile(
			"mrs     %[tmp], cpsr          \n\t"
			"bic     %[tmp], %[tmp], #0x80 \n\t"
			"msr     cpsr_c, %[tmp]        \n\t"
			: [tmp] "=r" (tmp)
	);

	return;
}

void DI(void)
{
	int tmp;
	asm volatile(
			"mrs     %[tmp], cpsr          \n\t"
			"orr     %[tmp], %[tmp], #0x80 \n\t"
			"msr     cpsr_c, %[tmp]        \n\t"
			: [tmp] "=r" (tmp)
	);

	return;
}

interrupt_register_t* GetInterruptRegister(void)
{
	return (interrupt_register_t*)INTERRUPT_REGISTER_ADDRESS;
}

void __attribute__((interrupt("UNDEF"))) undefined_instruction_vector(void)
{	 
	while( 1 ) {
		LED_ON();
	}
}

void __attribute__((interrupt("SWI"))) software_interrupt_vector(void)
{
 
	while( 1 ) {
		LED_ON();
	}
}

void __attribute__((interrupt("ABORT"))) prefetch_abort_vector(void)
{
	while(1) {
		LED_ON();
	}
}

void __attribute__((interrupt("ABORT"))) data_abort_vector(void)
{
	while(1) {
		LED_ON();
	}
}

void __attribute__((interrupt("IRQ"))) interrupt_vector(void)
{
	static int lit = 0;

	GetArmTimer()->IRQClear = 1;

	if(lit)
	{
		LED_OFF();
		lit = 0;
	}
	else
	{
		LED_ON();
		lit = 1;
	}
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void)
{
	while(1) {
		LED_ON();
	}
}


