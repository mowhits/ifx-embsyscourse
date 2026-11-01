#include "cmsis_gcc.h"
#include <stdint.h>

uint8_t initdata2[25] __attribute__((section (".my_initdata_section"))) = 
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

void enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}

void disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}