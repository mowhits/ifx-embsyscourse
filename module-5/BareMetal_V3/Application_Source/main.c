#include <stdio.h>
#include <stdint.h>
#include "./../Special_Libraries/cmsis_gcc.h"

uint8_t app_heap[512] __attribute__((section (".heap")));
uint8_t app_stack[4096] __attribute__((section (".stack")));

/* Flag used to toggle LED based on button input */
uint8_t invertFLAG = 0;

void Delay(uint32_t delayNumber);

int main()
{
    /* Enable Interrupts at CPU level */
    enable_irq();

    *((uint32_t *)0x40040800) = (1 << 0); // Set default output value of P8.0 to 1 (GPIO_PRT8_DR)
    *((uint32_t *)0x40040808) = (6 << 0); // Set drive mode of P8.0 to Digital OP Push Pull (GPIO_PRT8_PC)

    *((uint32_t *)0x40040000) = (1 << 6); // Set default output value of P0.6 to 1 (GPIO_PRT0_DR)
    *((uint32_t *)0x40040008) = (6 << 18); // Set output value of P0.6 to to Digital OP Push Pull (GPIO_PRT0_PC)
   
    *((uint32_t *)0x40040408) = (2 << 0); // Set output value of P4.0 to to Digital Input resistive pull up (GPIO_PRT4_PC)
    *((uint32_t *)0x40040400) = (1 << 0); // Set default output value of P4.0 to 1 (GPIO_PRT4_DR)
    *((uint32_t *)0x4004040C) = (2 << 0); // Enable falling edge interrupt detection for P4.0 (GPIO_PRT4_INTR_CFG)

    /* Set priority level of the P4.0 user button (CM0P_IPRx) */
    *((uint32_t *)0xE000E404) = (3 << 6);

    /* Clearing and enabling the GPIO interrupt in NVIC for IRQ4 */
    *((uint32_t *)0xE000E280) = 0xFFFFFFFF; // (CM0P_ICPR) 
    *((uint32_t *)0xE000E100) = (1 << 4);   // (CM0P_ISER) 

	/* Trying to write into invalid address */
    // *((uint32_t *)0x60000000) = 0xDEADBEEF;

    for(;;)
    {
        /* In an infinite loop toggle the LED 8.0, perform blinkey operation */
        *((uint32_t *)0x40040800) = (0 << 0); // Set output value of P8.0 to 0 (GPIO_PRT8_DR)
        Delay(60000);

        *((uint32_t *)0x40040800) = (1 << 0); // Set output value of P8.0 to 1 (GPIO_PRT8_DR)
        Delay(60000);
    }

    return 0;
}

/* Simple software based delay function */
void Delay(uint32_t delayNumber)
{
    for(uint32_t i=0; i<delayNumber; i++);
    for(uint32_t i=0; i<delayNumber; i++);
}

/* Interrupt handler for the button */
void ioss_interrupt_gpio_IRQHandler(void)
{
     uint32_t readVal;
    
     /* Clear the interrupt status at the GPIO peripheral to enable the next interrupt */
    *((uint32_t *)0x40040410) = (1 << 0); // Clear Interrupt for P4.0 (GPIO_PRT4_INTR)
    
	readVal = *((uint32_t *)0x40040404); // Read the P4.0 Input register and store into readVal (GPIO_PRT4_PS)
	if(((readVal >> 0) & 1) == 0u)
	{
		if(invertFLAG == 1u)
		{
			*((uint32_t *)0x40040000) = (1 << 6); // Set output value of P0.6 to 1 (GPIO_PRT0_DR)
			invertFLAG = 0u;
		}
		else if(invertFLAG == 0u)
		{         
			*((uint32_t *)0x40040000) = (0 << 6); // Set output value of P0.6 to 0 (GPIO_PRT0_DR)
			invertFLAG = 1u;          
		}
	} 
}


