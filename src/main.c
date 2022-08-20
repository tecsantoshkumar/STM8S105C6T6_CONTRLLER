#include "stm8s105c6t6.h"
#include "stm8s_gpio.h"

volatile void delay(volatile uint32_t t)
{
  while(t--);
}

int main( void )
{
  // data direction PB5 - output
  GPIOB->DDR |= GPIO_PIN_5;
  
  // control register 
  GPIOB->CR1 |= GPIO_PIN_5;
  
  // data output latch register
  GPIOB->ODR |= GPIO_PIN_5;
  
  while(1)            
  {
    delay(20000); 			  // wait approx. 1 second
    GPIOB->ODR ^= GPIO_PIN_5; // turn PB5 LED on/off (toggle state)
  }
}