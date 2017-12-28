
#ifndef TIMER_H
#define TIMER_H

#include "type.h"

#define TIMER_BASE 0x3f003000

typedef struct {
	REG32 control_status;
	REG32 counter_lo;
	REG32 counter_hi;
	REG32 compare0;
	REG32 compare1;
	REG32 compare2;
	REG32 compare3;
} timer_t;

timer_t* GetTimer_us(void);
void Wait_us( UINT32 us );

#endif
