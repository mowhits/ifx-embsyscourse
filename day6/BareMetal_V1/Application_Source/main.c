#include <stdint.h>

uint8_t app_heap[512] __attribute__((section (".heap")));
uint8_t app_stack[4096] __attribute__((section (".stack")));

void Delay(uint32_t);
uint32_t var1 = 50u; // initialized global var
uint32_t var2; //un initialized globar var
const uint32_t var3 = 50u; //constant
volatile uint32_t var6; //volatile variable

int main()
{
    uint32_t var4 = 0; //initialized local variable
    uint32_t var5; //uninitialized local variable
    for(;;)
    {

        Delay(60000);
        var5 = var1 + var2 + var3+ var4;
        var6 = var5 + 50u;       
    }

    return 0;
}

void Delay(uint32_t delayNumber)
{
    for(uint32_t i=0; i<delayNumber; i++);
    for(uint32_t i=0; i<delayNumber; i++);
}


