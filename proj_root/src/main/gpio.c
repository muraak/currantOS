#include "type.h"
#include "base.h"
#include "gpio.h"

gpio_regs_t * gpioRegs = (gpio_regs_t *)GPIO_ADDRESS;

gpio_regs_t* GetGpioRegister(void)
{
    return (gpio_regs_t*)GPIO_ADDRESS;
}

void SetGpioPinFunction(gpio_pin_t gpio, gpio_func_sel_t func)
{
	/* Get target register's copy */
  REG32* fsel_reg = &(((REG32 *)gpioRegs)[ gpio / 10 ]);
  REG32 copy = *fsel_reg;

	/* Make the value. */
  copy &= ~( FS_MASK << ( ( gpio % 10 ) * 3 ) );
  copy |= (func << ( ( gpio % 10 ) * 3 ) );
  
	/* Set the value to target register. */
	*fsel_reg = copy;

	return;
}


