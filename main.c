#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "stdio.h"
#include "lcdKutuphane.h" 
#include "adc.h"






char sAdcValue[7];


uint16_t ADC_deger;

uint32_t deger[1]={0};


void DMA_basla()	
{
	//adc için dma1 channel 1
	
	RCC->AHBENR |=1<<0;//DMA hatti aktif.
	
	
	DMA1_Channel1->CNDTR =1;//Transfer edilecek data sayisi.
	
	DMA1_Channel1->CPAR =(uint32_t) &ADC1->DR; //Buradan okunacak.
 	DMA1_Channel1->CMAR =(uint32_t) deger;//Buraya yollayacak.
  DMA1_Channel1->CCR = 0x000025A1;//Yüksek oncelik,MINC,CIRC,MSIZE,PSIZE,EN.
	
	
}




void ADC1_2_IRQHandler(void)
{
	
		
		if (ADC1->SR & (1<<1))
		
    	ADC_deger = ADC1->DR;

		
	
}
	

int main()
	
{
	
	delay_init();
	portAyarlari();
	lcd_basla();
	adc_init();
	DMA_basla();
	
	
	
	while(1)
	{
		
		lcdHucreyeGit(1,1);
		
		
		
		
		//while (!(ADC1->SR & (1<<1)));Interruptsiz ADC Degeri almak için.
		
		
		
		//Interrupt ile ADC Degeri almak için.
		
		/*
		sprintf(sAdcValue, "%d   ", ADC_deger); 
		lcd_yaz("ADC Degeri:");
		lcd_yaz(sAdcValue);*/
		
		
		//DMA ile ADC Degeri almak için.
	
		sprintf(sAdcValue, "%d   ", deger[0]); 
		lcd_yaz("DMA LI ADC :");
		lcd_yaz(sAdcValue);

		
		
		delay_ms(100);
		
		
	}
	
}







