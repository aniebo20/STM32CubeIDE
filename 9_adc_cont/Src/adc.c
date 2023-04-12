#include "stm32f7xx.h"
#include "adc.h"


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

/*			Configure Temperature Sensor
 * 1. Set TVSREFE in ADC_CCR to wake temp sensor (set at same time as ADON so done in adc_pc0_config)
 * 2. Set VSense
 * 3. Select sample time
 */

/* Reading the temperature
To use the sensor:
3. Select ADC1_IN18 input channel.
4. Select a sampling time greater than the minimum sampling time specified in the datasheet.
5. Set the TSVREFE bit in the ADC_CCR register to wake up the temperature sensor from power down mode
6. Start the ADC conversion by setting the SWSTART bit (or by external trigger)
7. Read the resulting VSENSE data in the ADC data register
8. Calculate the temperature using the following formula:
Temperature (in °C) = {(VSENSE – V25) / Avg_Slope} + 25
Where:
– V25 = VSENSE value for 25° C
– Avg_Slope = average slope of the temperature vs. VSENSE curve (given in mV/°C or μV/°C)
Refer to the datasheet electrical characteristics section for the actual values of V25 and Avg_Slope.
Note: The sensor has a startup time after waking from power down mode before it can output VSENSE at the correct level. The ADC also has a startup time after power-on, so to minimize the delay, the ADON and TSVREFE bits should be set at the same time.
The temperature sensor output voltage changes linearly with temperature. The offset of this linear function depends on each chip due to process variation (up to 45 °C from one chip to another).
The internal temperature sensor is more suited for applications that detect temperature variations instead of absolute temperatures. If accurate temperature reading is required, an external temperature sensor should be used.	*/

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

	/*		Configure ADC module		*/
	//4.
	RCC->APB2ENR |= (1U << 8);
	//1.
	ADC1->SQR3 = ((1U << 4) | (1U << 0)); //10001
	//2.
	ADC1->SQR1 = 0U;
	//5.
	ADC1->CR2 |= (1U);
	ADC1->CCR |=
	//3.
	ADC1->CR2 |= (1U << 30);
	ADC1->CR2 &= ~(1U << 1);
}

void temp_sense_init()
{
	/*		Configure Temperature Sensor		*/
	//1.


}

void adc_pc0_start_conversion(void)
{
	/*		Start Conversion			*/
	ADC1->CR2 |= (1U << 30);
}

uint32_t adc1_read_temp_sense()
{
	while (!(ADC1->SR & (1U << 1))) {}

	 ADC1->DR;
}

