#ifndef UART
#define UART
	#include <stdio.h>
	#include <stdint.h>
	#include <math.h>
	#include "stm32f7xx.h"

	uint32_t get_uartdiv(uint32_t baud, uint32_t f_clk);
	void uart3_rxtx_init();
	void uart3_config_baudrate(USART_TypeDef *USARTx, uint32_t periph_clk, uint32_t baud);
	void uart3_tx(char c);
	int __io_putchar(char c);
	char uart3_rx(void);
#endif
