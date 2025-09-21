//Acionar um led sempre que o número de chaves/botões acionados for par. Usar quatro chaves/botões.
#include "stm32g0xx.h"
int main(){

	RCC->IOPENR=0x3f;
	GPIOA->MODER=0x28000000;// chave pa0, pa1; pa2, pa3
	GPIOC->MODER=0x1; // liga led, saida
	int q=0;
	while(1){

	if(GPIOA->IDR & 0x1){
		q++;
	}
	if(GPIOA->IDR & 0x2){
		q++;
	}
	if(GPIOA->IDR & 0x4){
		q++;
	}
	if(GPIOA->IDR & 0x8){
		q++;
	}
	if (q % 2 == 0){
		GPIOC->ODR=0x1;
	}
	else{
		GPIOC->ODR=0x0;
	}
    q=0;
	}
}
