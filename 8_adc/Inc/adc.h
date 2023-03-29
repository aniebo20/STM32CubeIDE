#ifndef		__ADC_H__
#define		__ADC_H__

#include <stdint.h>
uint32_t adc1_read();
void adc_pc0_start_conversion(void);
void adc_pc0_config(void);

#endif
