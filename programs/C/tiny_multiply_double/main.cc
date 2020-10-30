#include "myClib.h"
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
// #include <stdio.h>

int my_ftoi (float f, int &in, int &fr) { 
    in = (int) f;
    float fraction=0;
    fraction = f - in;
    fraction = (fraction > 0) ? fraction : -fraction;
    fr = (int) (fraction * 100000000);
    in = (int) (f - fraction);
    return 0;
}

int main () {
    float x = -38.6712;
    float y = 22.7687;
    float z = x*y;

    int in, fr;
    // in = (int) z;
    // float fraction=0;
    // fraction = z - in;
    // fr = (int) (fraction * 10000);
    // in = (int) (z - fraction);
    ftoi (z, in, fr);
    _printf("product of x and y is %d.%d\n", in, fr);
    // my_ftoi (z, in, fr);
    //  _printf("product of x and y is %d.%d\n", in, fr);
    //_printf("product of x and y is %f\n", (double) z);
    //_printf("The product of %d and %d is : %d", (int)x, (int)y, (int) (x*y));
    return 0;
}
