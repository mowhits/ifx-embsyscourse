#include <stdint.h>
#include "mac.h"
uint8_t app_heap[512] __attribute__((section (".heap")));
uint8_t app_stack[4096] __attribute__((section (".stack")));

#define red 01
#define blue 02
#define green 03
#define PI 3.14159

void Delay(uint32_t);
int gvar1;
int gvar7;
int gvar2 = green;
const int gvar5 = 20;
int arr[4] = {'a', 'b', 'c', 'd'};
float a = 3.14, b = 2.41;

int main(void) {
    char gvar3;
    gvar2 += red + blue + PI;
    gvar3 = 5 + gvar5;
    mac_init();
    for (;;) {
        Delay(60000);
        acc = mac(a, b);
    }
    return 0;
}

void Delay(uint32_t delayNumber)
{
    for(uint32_t i=0; i<delayNumber; i++);
    for(uint32_t i=0; i<delayNumber; i++);
}




