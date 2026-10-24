#include "cmsis_gcc.h"
#include <stdint.h>

void enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}

void disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}