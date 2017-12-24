/* The base address of the GPIO peripheral (ARM Physical Address) */
#ifndef GPIO_H
#define GPIO_H

#include "type.h"
#include "base.h"

#define GPIO_ADDRESS    (PERIPHERAL_ADDRESS + 0x200000UL)

#define LED_GPFSEL      GPFSEL4
#define LED_GPFBIT      21
#define LED_GPSET       GPSET1
#define LED_GPCLR       GPCLR1
#define LED_GPIO_BIT    15
#define LED_ON()        GetGpioRegister()->LED_GPSET = (1 << LED_GPIO_BIT)
#define LED_OFF()       GetGpioRegister()->LED_GPCLR = (1 << LED_GPIO_BIT)

#define FS_MASK     (7)

typedef enum {
  GPIO0 = 0,
  GPIO1,
  GPIO2,
  GPIO3,
  GPIO4,
  GPIO5,
  GPIO6,
  GPIO7,
  GPIO8,
  GPIO9,
  GPIO10 = 10,
  GPIO11,
  GPIO12,
  GPIO13,
  GPIO14,
  GPIO15,
  GPIO16,
  GPIO17,
  GPIO18,
  GPIO19,
  GPIO20 = 20,
  GPIO21,
  GPIO22,
  GPIO23,
  GPIO24,
  GPIO25,
  GPIO26,
  GPIO27,
  GPIO28,
  GPIO29,
  GPIO30 = 30,
  GPIO31,
  GPIO32,
  GPIO33,
  GPIO34,
  GPIO35,
  GPIO36,
  GPIO37,
  GPIO38,
  GPIO39,
  GPIO40 = 40,
  GPIO41,
  GPIO42,
  GPIO43,
  GPIO44,
  GPIO45,
  GPIO46,
  GPIO47,
  GPIO48,
  GPIO49,
  GPIO50 = 50,
  GPIO51,
  GPIO52,
  GPIO53,
} gpio_pin_t;

typedef enum {
  GPIO_FS_IN = 0,
  GPIO_FS_OUT,
  GPIO_FS_5,
  GPIO_FS_4,
  GPIO_FS_0,
  GPIO_FS_1,
  GPIO_FS_2,
  GPIO_FS_3,
} gpio_func_sel_t;

// GPIO Registers
// See: https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf(pp.90)
typedef struct {
	reg32_t	GPFSEL0;
	reg32_t	GPFSEL1;
	reg32_t	GPFSEL2;
	reg32_t	GPFSEL3;
	reg32_t	GPFSEL4;
	reg32_t	GPFSEL5;
	reg32_t	Reserved0;
	reg32_t	GPSET0;
	reg32_t	GPSET1;
	reg32_t	Reserved1;
	reg32_t	GPCLR0;
	reg32_t	GPCLR1;
	reg32_t	Reserved2;
	reg32_t	GPLEV0;
	reg32_t	GPLEV1;
	reg32_t	Reserved3;
	reg32_t	GPEDS0;
	reg32_t	GPEDS1;
	reg32_t	Reserved4;
	reg32_t	GPREN0;
	reg32_t	GPREN1;
	reg32_t	Reserved5;
	reg32_t	GPFEN0;
	reg32_t	GPFEN1;
	reg32_t	Reserved6;
	reg32_t	GPHEN0;
	reg32_t	GPHEN1;
	reg32_t	Reserved7;
	reg32_t	GPLEN0;
	reg32_t	GPLEN1;
	reg32_t	Reserved8;
	reg32_t	GPAREN0;
	reg32_t	GPAREN1;
	reg32_t	Reserved9;
	reg32_t	GPAFEN0;
	reg32_t	GPAFEN1;
	reg32_t	Reserved10;
	reg32_t	GPPUD;
	reg32_t	GPPUDCLK0;
	reg32_t	GPPUDCLK1;
	reg32_t	Reserved11;
} gpio_regs_t;

gpio_regs_t* GetGpioRegister(void);
void SetGpioPinFunction(gpio_pin_t gpio, gpio_func_sel_t func);

#endif
