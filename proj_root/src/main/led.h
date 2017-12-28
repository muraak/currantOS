
#ifndef LED_H
#define LED_H

#include "gpio.h"

#define ENABLE_LED() GetGpioRegister()->LED_GPFSEL |= (1 << LED_GPFBIT)
#define LED_ON()     GetGpioRegister()->LED_GPSET = (1 << LED_GPIO_BIT)
#define LED_OFF()    GetGpioRegister()->LED_GPCLR = (1 << LED_GPIO_BIT)

#endif
