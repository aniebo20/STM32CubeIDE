#include "stm32f7xx.h"
#include "adc.h"

/*			 Configure the ADC GPIO Pin
 * 1. Set Pin mode PC0 to ADC1_IN10
 * 2. Enable GPIO C Clock access*/

/*			Configure ADC module
 * 1. Set conversion channels in ADC_SQRx
 * 2. Set conversion length in ADC_SQR1
 * 3. Set conversion mode by setting the SWSTART bit in the ADC_CR2 and CONT to 0
 * 4. Enable APB2 Clock Access to ADC1
 * 5. Turn on ADC by setting ADON bit in the ADC_CR2 register*/

/*			Start Conversion
 * 1. Set SWSTART bit in ADC_CR2
 */
/*			Read from ADC
 * 1. Wait for EOC flag
 * 2. Read from ADC_DR*/

//Set TSVREFE control bit
//Set VSense
//Select ADC1_IN18 input channel.
//Select a sampling time
//Set the TSVREFE bit in the ADC_CCR register to wake up the temperature sensor
//Start the ADC conversion by setting the SWSTART
//Read from VSense
//Temperature (in °C) = {(VSENSE – V25) / Avg_Slope} + 25


void adc_pc0_config(void)
{
	/* 		Configure ADC GPIO Pin 		*/
	//2.
	RCC->AHB1ENR |= (1U << 2);
	//1.
	GPIOC->MODER |= ((1U << 1) | (1U << 0));



	/*		Configure ADC module		*/
	//4.
	RCC->APB2ENR |= (1U << 8);
	//1.
	ADC1->SQR3 = ((1U << 3) | (1U << 1));
	//2.
	ADC1->SQR1 = 0U;
	//5.
	ADC1->CR2 |= (1U);
	//3.
	ADC1->CR2 |= (1U << 30);
	ADC1->CR2 &= ~(1U << 1);
}

void adc_pc0_start_conversion(void)
{
	/*		Start Conversion			*/
	ADC1->CR2 |= (1U << 30);
}

uint32_t adc1_read()
{
	while (!(ADC1->SR & (1U << 1))) {}

	return ADC1->DR;
}

