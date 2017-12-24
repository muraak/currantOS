#ifndef INTERRUPTS_H
	#define INTERRUPTS_H
	
	#include "type.h"
	#include "base.h"

	#define INTERRUPT_REGISTER_ADDRESS (PERIPHERAL_ADDRESS + 0xB200)

	// ARM peripherals interrupts table.
	#define ARM_TIMER_IRQ				(1 << 0)
	#define ARM_MAILBOX_IRQ			(1 << 1)
	#define ARM_DOORBELL_0_IRQ	(1 << 2)
	#define ARM_DOORBELL_1_IRQ	(1 << 3)
	#define GPU_0_HALTED_IRQ		(1 << 4)
	#define GPU_1_HALTED_IRQ		(1 << 5)
	#define ACCESS_ERROR_1_IRQ	(1 << 6)
	#define ACCESS_ERROR_0_IRQ	(1 << 7)

	typedef struct {
		reg32_t IRQ_basic_pending;
		reg32_t IRQ_pending_1;
		reg32_t IRQ_pending_2;
		reg32_t FIQ_control;
		reg32_t Enable_IRQs_1;
		reg32_t Enable_IRQs_2;
		reg32_t Enable_Basic_IRQs;
		reg32_t Disable_IRQs_1;
		reg32_t Disable_IRQs_2;
		reg32_t Disable_Basic_IRQs;
	} interrupt_register_t;

	void EI(void);
	void DI(void);
	interrupt_register_t* GetInterruptRegister(void);

#endif
