#include "add.h"

#define red 01
#define blue 02
#define green 03
#define PI 3.14159

int gvar1;
int gvar7;
char gvar3;
int gvar2 = green;
const int gvar5 = 20;
int arr[4] = {'a', 'b', 'c', 'd'};
float a = 3.14, b = 2.41, res;

int main(void) {
#if red==02
    gvar1 = 5 + red;
#endif
    gvar2 += red + blue + PI;
    gvar3 = 5 + gvar5;
    res = addf(a, b);
    while(1);
    return 0;
}

