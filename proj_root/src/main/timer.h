
#ifndef TIMER_H
#define TIMER_H

#include "type.h"

#define TIMER_BASE 0x3f003000

typedef struct {
	reg32_t control_status;
	reg32_t counter_lo;
	reg32_t counter_hi;
	reg32_t compare0;
	reg32_t compare1;
	reg32_t compare2;
	reg32_t compare3;
} timer_t;

timer_t* GetTimer_us(void);
void Wait_us( uint32 us );

#endif
