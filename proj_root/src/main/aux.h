#ifndef AUX_H
#define AUX_H

#include "type.h"

#define AUX_ADDR (PERIPHERAL_ADDRESS + 0x215000)

// AUXIRQ Register 
#define AUX_IRQ_MINI_UART (1 << 0)
#define AUX_IRQ_SPI1      (1 << 1)
#define AUX_IRQ_SPI2      (1 << 2)

// AUXENB Register
#define AUX_ENA_MINI_UART (1 << 0)
#define AUX_ENA_SPI1      (1 << 1)
#define AUX_ENA_SPI2      (1 << 2)

// AUX_MU_LCR_REG Register
#define AUX_MU_LCR_BREAK     (1 << 6)
#define AUX_MU_LCR_DLAB_ACS  (1 << 7)
#define AUX_MULCR_8BIT_MODE  (3 << 0) // eratta!
#define AUX_MULCR_7BIT_MODE  (0 << 0)

// AUX_MU_MCR_REG Register
#define AUX_MU_MCR_RTS (1 << 1)

// AUX_MU_LSR_REG Register
#define AUX_MU_LSR_DATA_READY        (1 << 0)
#define AUX_MU_LSR_DATA_RECV_OVERRUN (1 << 1)
#define AUX_MU_LSR_DATA_TRANS_EMPTY  (1 << 5)
#define AUX_MU_LSR_DATA_TRANS_IDLE   (1 << 6)

// AUX_MU_MSR_REG Register
#define AUX_MU_MSR_CTS (1 << 5)

// AUX_MU_CNTL_REG Register
#define AUX_MU_CNTL_ENABLE_RX       (1 << 0)
#define AUX_MU_CNTL_ENABLE_TX       (1 << 1)
#define AUX_MU_CNTL_ENABLE_RTS_FLOW (1 << 2)
#define AUX_MU_CNTL_ENABLE_CTS_FLOW (1 << 3)
#define AUX_MU_CNTL_RTS_FIFO        (3 << 4)
#define AUX_MU_CNTL_RTS_ASSERT      (1 << 6)
#define AUX_MU_CNTL_CTS_ASSERT      (1 << 7)

// AUX_MU_STAT_REG Register
#define AUX_MU_STAT_SYMBOL_AVAILABLE (1 << 0)
#define AUX_MU_STAT_SPACE_AVAILABLE  (1 << 1)
#define AUX_MU_STAT_RX_IDLE          (1 << 2)
#define AUX_MU_STAT_TX_IDLE          (1 << 3)
#define AUX_MU_STAT_RX_OVERRUN       (1 << 4)
#define AUX_MU_STAT_TX_FIFO_FULL     (1 << 5)
#define AUX_MU_STAT_RTS_STATUS       (1 << 6)
#define AUX_MU_STAT_CTS_LINE         (1 << 7)
#define AUX_MU_STAT_TX_FIFO_EMPTY    (1 << 8)
#define AUX_MU_STAT_TX_DONE          (1 << 9)
#define AUX_MU_STAT_RX_FIFO_LEVEL    (7 << 16)
#define AUX_MU_STAT_TX_FIFO_LEVEL    (7 << 24)

typedef struct {
	REG32 IRQ;
	REG32 ENA;
	REG32 reserved1[((0x40 - 0x04) / 4) - 1];
  REG32 IO;
  REG32 IER;
  REG32 IIR;
  REG32 LCR;
  REG32 MCR;
  REG32 LSR;
  REG32 MSR;
  REG32 SCRATCH;
  REG32 CNTL;
  REG32 STAT;
  REG32 BAUD;
} aux_mini_uart_regs_t;

aux_mini_uart_regs_t* AuxMiniUartRegsGetAddr(void);
void AuxMiniUartInit(UINT32 baud, UINT32 bits);
void AuxMiniUartPutByte(BYTE c);
BYTE AuxMiniUartGetByte();

#endif
