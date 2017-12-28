
#ifndef LED_H
#define LED_H

#include "gpio.h"

#define LED_GPSET       GPSET1
#define LED_GPCLR       GPCLR1
#define LED_GPIO_BIT    15

#define ENABLE_LED() SetGpioPinFunction(GPIO47, GPIO_FS_OUT)
#define LED_ON()     GetGpioRegister()->LED_GPSET = (1 << LED_GPIO_BIT)
#define LED_OFF()    GetGpioRegister()->LED_GPCLR = (1 << LED_GPIO_BIT)

#endif
