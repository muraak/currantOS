
#include "type.h"
#include "interrupts.h"
#include "arm_timer.h"
#include "led.h"

#include "aux.h"

void InterruptInit(void)
{
	// Enable arm timer interrupt.
	GetInterruptRegister()->Enable_Basic_IRQs = ARM_TIMER_IRQ;
	// Enable aux mini UART interrupt.
	GetInterruptRegister()->Enable_IRQs_1 = (1 << 29);
}

void EI(void)
{
	REG32 tmp;
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
	REG32 tmp;
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
	

	if((GetInterruptRegister()->IRQ_basic_pending
				& (REG32)ARM_TIMER_IRQ) == (REG32)ARM_TIMER_IRQ) {

		GetArmTimer()->IRQClear = 1;
		ArmTimerInterruptHandler();
	}


	if((GetInterruptRegister()->IRQ_pending_1 & (1 << 29)) == (1 << 29)) {

		AuxMiniUartInterruptHandler();
	}
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void)
{
	while(1) {
		LED_ON();
	}
}


