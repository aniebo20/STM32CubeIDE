//USB IS USART3 = PB10 or PD8

//CONFIGURE PIN
/*1. Enable Clock access to Port D (AHB1 Bus)
 *2. Configure D8 AND D9 as Alternate function ***
 *3. Set Alternate function as TX AF7 AND RX AF7*/


//SETUP UART
/*1. Enable APB1 BUS USART3 clock access
 *2. Set baud rate USART_BRR (SET OVER8 = 0 to oversample by 16)
 *3. Set Stop bits USART_CR2
 *4. Set word length USART_CR1 M[1:0] to 00 for 8 bit word
 *5. Enable Transmitter TE in USART_CR1 AND Receiver RE in USART_CR1  ***
 *6. Enable UE bit in USART_CR1 */

//WRITING
/*1. Check if TXE has been set (if transfer register is empty)
 *2. Write into USART Transmit USART_TDR*/

//READING
/*1. Check if RXNE is set
 *2. Read from RDR*/

#include "uart.h"

#define BAUD		115200
#define F_CLK		16000000


int __io_putchar(char c)
{
	uart3_tx(c);
	return c;
}

void uart3_rxtx_init()
{
	//CONFIGURE PIN
	//1.
	RCC->AHB1ENR |= (1U << 1) | (1U << 3);
	//2.
	GPIOD->MODER |= ((1U << 17) | (1U << 19));
	GPIOD->MODER &= ~((1U << 16) | (1U << 18));
	//3.
	GPIOD->AFR[1] |= ((7U) | (7U << 4));
	GPIOD->AFR[1] &= ~((1U << 3) | (1U << 7));

	//SETUP UART
	//1.
	RCC->APB1ENR |= (1U << 18);
	//2.
	uart3_config_baudrate(USART3, F_CLK, BAUD);
	//3.
	USART3->CR2 |= (1U << 13);
	USART3->CR2 &= ~(1U << 12);
	//4.
	USART3->CR1 &= ~((1U << 28) | (1U << 12));
	//5.
	USART3->CR1 |= ((1U << 3) | (1U << 2));
	//6.
	USART3->CR1 |= 1U;
}

uint32_t get_uartdiv(uint32_t baud, uint32_t f_clk)
{
	//BECAUSE OVERSAMPLING BY 16
	return f_clk/baud;
}

void uart3_config_baudrate(USART_TypeDef *USARTx, uint32_t periph_clk, uint32_t baud)
{
	USARTx->BRR = get_uartdiv(baud, periph_clk);
}

void uart3_tx(char c)
{
	while(!(USART3->ISR & (1U << 7)));
	USART3->TDR = (c & 0xFF);
}

char uart3_rx(void)
{
	//1.
	while(!(USART3->ISR & (1U << 5)));
	//2.
	return USART3->RDR;
}

