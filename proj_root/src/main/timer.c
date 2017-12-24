/**
 * @file timer.c
 * @brief driver for system timer
 */

#include "type.h"
#include "timer.h"

static timer_t* timer = (timer_t*)TIMER_BASE;

/**
 * @brief Get the system timer's register.
 * @return Reference for the system timer's register.
 */
timer_t* GetTimer(void)
{
    return timer;
}

/**
 * @brief Wait for specifyied time period.
 * @param[in] us wait time(Microseconds)
 */
void Wait_us( uint32 us )
{
    volatile uint32 ts = timer->counter_lo;

    while( ( timer->counter_lo - ts ) < us ){}
}
