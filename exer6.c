//6.   Exibir num display de sete segmentos as letras que compõe o seu nome.

#include "stm32g0xx.h"
int main(){
	int n;
	RCC->IOPENR= 0x3f;
	GPIOA->MODER=0x28000000; // pa0, pa1, pa2, pa3;
	GPIOB->MODER=0x1555;// pb0. pb1, pb2, pb3, pb4, pb5, pb6
	int display[16]= {0x06, 0x6D, 0x77, 0x5E, 0x5C, 0x50, 0x77, 0x73, 0x5C, 0x38, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00};

	while(1){
		n = GPIOA-> IDR & 0xF;
		GPIOB-> ODR = display[n];
	}
}
