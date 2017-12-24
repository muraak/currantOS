#include "aux.h"
#include "gpio.h"

#define SYS_FREQ_HZ 250000000

static aux_mini_uart_regs_t * aux_mini_uart_regs = (aux_mini_uart_regs_t *)AUX_ADDR;

aux_mini_uart_regs_t* AuxMiniUartRegsGetAddr(void)
{
	return aux_mini_uart_regs;
}

void AuxMiniUartInit(uint32 baud, uint32 bits)
{
	volatile uint32 cnt;

	/* Set AUX as mini UART. */
	aux_mini_uart_regs->ENA = (reg32_t)AUX_ENA_MINI_UART;

	/* Disable interrupts for now. */
  //aux_mini_uart_regs->IRQ &= ~AUX_IRQ_MINI_UART;

	/* Disable flow control,enable transmitter and receiver. */
  aux_mini_uart_regs->CNTL = 0;

	/* Decide between seven or eight-bit mode. */
	if(bits == 8) {
		aux_mini_uart_regs->LCR = (reg32_t)AUX_MULCR_8BIT_MODE;
	}
	else {
		aux_mini_uart_regs->LCR = (reg32_t)AUX_MULCR_7BIT_MODE;
	}

	/* Clear the RTS signal. */
	aux_mini_uart_regs->MCR = 0;

	/* Disable all interrupts from MU and clear the fifos */
	aux_mini_uart_regs->IER = 0;
	aux_mini_uart_regs->IIR = 0xC6; //0x06?

	/* Calculate and set the baudrate. */
	aux_mini_uart_regs->BAUD = (SYS_FREQ_HZ / (8 * baud)) - 1;

	/* Set GPIO14 and GPIO15 as UART1 TXD/RXD(function 5). */
	SetGpioPinFunction(GPIO14, GPIO_FS_5);
	SetGpioPinFunction(GPIO15, GPIO_FS_5);

	/* Write to GPPUD to set the required control signal. */
	GetGpioRegister()->GPPUD = 0;	
	
	/* Wait 150 cycles to provides the required set-up time for the control signal */
	for(cnt = 0; cnt < 150; cnt++){}
	
	/* Write to GPPUDCLK0/1 to clock the control signal into the GPIO pads */ 
	/* you wish to modify(NOTE only the pads which receive a clock will be */
	/* modified, all others will retain their previous state).             */
	GetGpioRegister()->GPPUDCLK0 = (1 << 14);
	
	/* Wait 150 cycles. */
	for(cnt = 0; cnt < 150; cnt++){}
	
	/* Write to GPPUD to remove the control signal. */
	GetGpioRegister()->GPPUD = 0;
	
	/* Write to GPPUDCLK0/1 to remove the clock. */
	GetGpioRegister()->GPPUDCLK0 = 0;

	/* Disable flow control,enable transmitter and receiver. */
  aux_mini_uart_regs->CNTL = AUX_MU_CNTL_ENABLE_TX | AUX_MU_CNTL_ENABLE_RX;

	return;

}

void AuxMiniUartPutByte(int08 c)
{
	/* Wait until ready. */
	while((aux_mini_uart_regs->LSR & AUX_MU_LSR_DATA_TRANS_EMPTY) == 0){}

	aux_mini_uart_regs->IO = c;
}

int08 AuxMiniUartGetByte(void)
{
	/* Wait until ready. */
	while((aux_mini_uart_regs->LSR & AUX_MU_LSR_DATA_READY) == 0){}

	return (uint08)aux_mini_uart_regs->IO;
}
