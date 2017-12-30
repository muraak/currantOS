#ifndef ARM_TIMER_H
#define ARM_TIMER_H

#include "type.h"
#include "base.h"

#define ARM_TIMER_ADDRESS (PERIPHERAL_ADDRESS + 0xB400)

// Timer control register:
// See: https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf(pp.197)
#define ARM_TIMER_CTRL_COUNTER_16BIT (0 << 1)
#define ARM_TIMER_CTRL_COUNTER_23BIT (1 << 1)

#define ARM_TIMER_CTRL_PRESCALE_1		(0 << 2)
#define ARM_TIMER_CTRL_PRESCALE_16	(1 << 2)
#define ARM_TIMER_CTRL_PRESCALE_256	(2 << 2)

#define ARM_TIMER_CTRL_EI (1 << 5)
#define ARM_TIMER_CTRL_DI (0 << 5)

#define ARM_TIMER_CTRL_ENABLE_TIMER		(1 << 7)
#define ARM_TIMER_CTRL_DISABLE_TIMER	(0 << 7)

// Timer Registers:
// See: https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf(pp.196)
typedef struct {
	REG32 Load;
	REG32 Value;
	REG32 Control;
	REG32 IRQClear;
	REG32 RAWIRQ;
	REG32 MaskedIRQ;
	REG32 Reload;
	REG32 PreDivider;
	REG32 FreeRunningCounter;
} arm_timer_t;

extern arm_timer_t* GetArmTimer(void);
void ArmTimerInterruptHandler(void);

#endif
