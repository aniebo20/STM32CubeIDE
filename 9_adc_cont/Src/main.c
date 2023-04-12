#include <stdio.h>
#include <stdint.h>
#include "stm32f7xx.h"
#include "adc.h"
#include "uart.h"

/*			READ INTERNAL TEMPERATURE ANALOG SIGNAL THROUGH ADC
 * Temp Sensor pin is VBAT, ADC1_IN18 */

/* Set ADON bit in the ADC_CR2
 * SWSTART or the JSWSTART bit is set*/
uint32_t adc_val = 0;
int main()
{
	uart3_rxtx_init();
	adc_pc0_config();

	while(1)
	{
		adc_pc0_start_conversion();
		adc_val = adc1_read();
		printf("Sensor Value : %d \n\r", adc_val);
	}
}





