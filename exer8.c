#include "stm32g0xx.h"

int main(){
   RCC->IOPENR=0x0000003F; //ligando clock das portas
   GPIOA->MODER=0x28000400;//configurando PA5 com saída
   //PA13 e PA14 como função alternativa
   RCC->APBENR1=0x20;    //ligando clock do Timer 7
   TIM7->ARR=7999;
   TIM7->PSC=999;
   TIM7->CR1 |=0x01;    //habilitando a contagem
   //timer vai contar 1 segundo

   while(1){
       if(TIM7->SR &0x01){    //testa se o tempo passou
           GPIOA->ODR^=0x20;    //inverte o estado do led
           TIM7->SR &=~0x01;    // limpa o flag de estouro do timer
       }
   }
}
