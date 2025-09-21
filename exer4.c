//4.  Duas chaves, chave 0 e chave 1.uma saída (led), sempre que os dois conjuntos apresentem a mesma combinação.
#include "stm32g0xx.h"
int main(){
	RCC->IOPENR=0x3f;
	GPIOA->MODER=0x28000000;// entrada chaves pa0, pa1
	GPIOC->MODER=0x1;// saida led / a0=a1=b0=b1  a0=b0 a1=b1
	int a, b, c,d;
	while(1) {
	a = GPIOA->IDR&0x1;
	b = (GPIOA->IDR&0x2)>>1;
	c = (GPIOA->IDR&0x4)>>2;
	d = (GPIOA->IDR&0x8)>>3;

	// desloca o numero de vezes q for necessario para o
	                        // codigo olhar so o primeiro conjunto de bits e nao a combinacao de dois ou + deles
		if(a == c && b == d){         // compara se as duas chaves tem a msm combinacao
			GPIOC->ODR = 0x1;
		}
		else{
			GPIOC->ODR = 0x0; // se for diferente desliga
		}
	}
}
