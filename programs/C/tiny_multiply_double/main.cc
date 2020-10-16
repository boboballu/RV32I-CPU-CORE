#include "myClib.h"
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
// #include <stdio.h>


int main () {
    float x = 38.6712;
    float y = 22.7687;
    float z = x*y;
    //float_to_int_and_fract(z, integer);
    int in, fr;
    in = (int) z;
    float fraction=0;
    fraction = z - in;
    fr = (int) (fraction * 10000);
    _printf("fraction part : %d", fr);
    //_printf("The product of %d and %d is : %d", (int)x, (int)y, (int) (x*y));
    return 0;
}
