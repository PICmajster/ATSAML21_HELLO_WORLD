/***************************************************************************
  FileName:        main.c
  Processor:       ATSAML21G18B
  IDE :            SEGGER ver 4.12
  Created by:      http://strefapic.blogspot.com
 ***************************************************************************/
/*-------------------------------------------------------------------------*/
/* Configuration clock and toggle LED                                      */
/*-------------------------------------------------------------------------*/
//      
//    Reqired connections :
//     - LED   - PB11
//
//***************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <saml21.h>
#include "delay.h"

void main(void) {
 /* Initialize the SAM system */
SystemInit();

/*set the OSC16M value to 16MHz*/
OSCCTRL->OSC16MCTRL.bit.FSEL = OSCCTRL_OSC16MCTRL_FSEL_16_Val; 
/*wait until the status bit is 1*/
while(!OSCCTRL->STATUS.bit.OSC16MRDY);

/*Set pin PB11 direction to Output*/
PORT->Group[1].DIRSET.reg = PORT_PB11; 

/* Set SysTick */
SysTick_Config(16000000 * 0.5); //0.5s, 16MHz core clock  

   while (1)
   {
     
   }

}

/* Routime Interrupt */
 __attribute__((interrupt)) void SysTick_Handler(void){
 /*Toggle pin PB11*/
   PORT->Group[1].OUTTGL.reg = PORT_PB11; 
}
