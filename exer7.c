// 7.   Implemente um comando liga-desliga  através de um único botão.
#include "stm32g0xx.h"

int main(){
	RCC->IOPENR= 0x3f;
	RCC->APBENR1=0x20;// liga clock timer 7
	GPIOA->MODER=0x28000000;// BOTAO PA0 IDR
	GPIOB->MODER=0x1; // LED PB0 ODR

	TIM7->ARR=3199; // 2 s
	TIM7->PSC=999;
	TIM7->CR1=0x01;
	int botao=0;

while(1){
	if((GPIOA->IDR & 0x1) && botao==0){

		GPIOB->ODR^=0x1;
		botao=1;
		TIM7->SR=0;
		TIM7->CNT=0;
	}
	if(TIM7->SR & 0x01){
		if((GPIOA->ODR & 0x01)==0){
				botao=0;
	    	}
		}
	}
}
