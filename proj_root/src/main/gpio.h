/* The base address of the GPIO peripheral (ARM Physical Address) */
#ifndef GPIO_H
#define GPIO_H

#include "type.h"
#include "base.h"

#define GPIO_ADDRESS    (PERIPHERAL_ADDRESS + 0x200000UL)

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
	REG32	GPFSEL0;
	REG32	GPFSEL1;
	REG32	GPFSEL2;
	REG32	GPFSEL3;
	REG32	GPFSEL4;
	REG32	GPFSEL5;
	REG32	Reserved0;
	REG32	GPSET0;
	REG32	GPSET1;
	REG32	Reserved1;
	REG32	GPCLR0;
	REG32	GPCLR1;
	REG32	Reserved2;
	REG32	GPLEV0;
	REG32	GPLEV1;
	REG32	Reserved3;
	REG32	GPEDS0;
	REG32	GPEDS1;
	REG32	Reserved4;
	REG32	GPREN0;
	REG32	GPREN1;
	REG32	Reserved5;
	REG32	GPFEN0;
	REG32	GPFEN1;
	REG32	Reserved6;
	REG32	GPHEN0;
	REG32	GPHEN1;
	REG32	Reserved7;
	REG32	GPLEN0;
	REG32	GPLEN1;
	REG32	Reserved8;
	REG32	GPAREN0;
	REG32	GPAREN1;
	REG32	Reserved9;
	REG32	GPAFEN0;
	REG32	GPAFEN1;
	REG32	Reserved10;
	REG32	GPPUD;
	REG32	GPPUDCLK0;
	REG32	GPPUDCLK1;
	REG32	Reserved11;
} gpio_regs_t;

gpio_regs_t* GetGpioRegister(void);
void SetGpioPinFunction(gpio_pin_t gpio, gpio_func_sel_t func);

#endif
