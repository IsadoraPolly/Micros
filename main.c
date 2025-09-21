//5.Exibir num display o número Hexadecimal correspondente ao número binário presente num conjunto de quatro chaves/botões.

#include "stm32g0xx.h"
int main(){
	int n;
	RCC->IOPENR= 0x3f;
	GPIOA->MODER=0x28000000; // pa0, pa1, pa2, pa3;
	GPIOB->MODER=0x1555;// pb0. pb1, pb2, pb3, pb4, pb5, pb6
	int display[16]= {0x3F, 0x06, 0x5B, 0x3F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

	while(1){
		n = GPIOA-> IDR & 0xF;
		GPIOB-> ODR = display[n];
	}
}




