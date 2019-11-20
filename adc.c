
#include "stm32f10x.h" 
#include "delay.h"
#include "adc.h"

void adc_init()
{
	RCC->APB2ENR |=0x00000201;//AFIO ve ADC1 Enable.
	
	
	//ADC1->CR1 |=1<<5;//Interrupt ayarlari.
	//NVIC->ISER[0] =1<<18;//Interrupt ayarlari.
	
	
	ADC1->SMPR2 |=0x00000028;//Bit 3 ve Bit 5 set.
	ADC1->SQR1 = 0x00000000; // only one conversion
	ADC1 ->SQR3 =0x01; // PA1 ADC1
	ADC1->CR2 |=1<<8;//DMA Enable.

	ADC1->CR2 |=0x03;//Cont ve ADCON
	delay_ms(1);
	ADC1->CR2 |=1<<0;//ADC ON.
	delay_ms(1);
	ADC1->CR2  |=1<<2;
	delay_ms(2);
	
	
	
	
}




	
	
	
	 
	
	
