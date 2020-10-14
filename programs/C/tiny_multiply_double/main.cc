#include "myClib.h"
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>

int main () {
    float x = 1.23;
    float y = 2.98;
    // 1.23 * 2.98 = 3.6654 
    // double x[10] = {10.32, 17.67, 119.3216, -32.10, 37265.4467, -45672.85911, 1.21, 0, -1, 23};
    // double y[10] = {86.471, 93.7312, -4.7236, -336.198, -665.334, 123, 4.67, 327.68, 4, 5};
    _printf("float : %08x\n", (float)x*y);
    //_printf("The product of %08x and %08x is : %08x", x, y, x*y);
    return 0;
}