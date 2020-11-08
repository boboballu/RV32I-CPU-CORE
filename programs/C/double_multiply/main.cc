#include "myClib.h"
#include <ctype.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
#include "dataset.h"

float float_multiply(float a, float b) {
    return a*b;
}

int verify (int size, float* result_data, float* verify_data) {
    float diff;
    for (int i=0; i<size; ++i) {
        diff = result_data[i] - verify_data[i];
        if ((diff > 1) or (diff < -1)) {
            _printf("fails at %d\n", i);
            return 1;        
        }
    }
    return 0;
}

int main () {
    int in, fr;
    // float result_data[DATA_SIZE];
    // for (int i=0; i<DATA_SIZE; ++i) {
    //     result_data[i] = float_multiply(input_data1[i], input_data2[i]);
    //     // ftoi(result_data[i], in, fl);
    //     // _printf("CPU: %d.%d\n", in, fl);
    // }
    // if (!verify (DATA_SIZE, result_data, verify_data)) {
    //     write_string("PASSED!");
    // }

    double x = 3789.44526; 
    double y = 221.099344;

    double z = x*y;
    ftoi ((float) z, in, fr);
    _printf("CPU: %d.%d\n", in, fr);
    _printf("float: %f\n", z);
    return 0;
}
