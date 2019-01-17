#include <stdio.h>
#include <stdlib.h>
#include <saml21.h>
#include "delay.h"


void main(void) {
 /* Initialize the SAM system */
SystemInit();
/* Set SysTick */
SysTick_Config(4000000 * 0.5); //0.5s, 4MHz core clock

/*Set pin PB11 direction to Output*/
PORT->Group[1].DIRSET.reg |= PORT_PB11; 
   
   while (1)
   {
     
   }

}

/* Routime Interrupt */
 __attribute__((interrupt)) void SysTick_Handler(void){
 /*Toggle pin PB11*/
   PORT->Group[1].OUTTGL.reg |= PORT_PB11; 
}