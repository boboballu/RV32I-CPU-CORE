// See LICENSE for license details.

//**************************************************************************
// Median filter bencmark
//--------------------------------------------------------------------------
//
// This benchmark performs a 1D three element median filter. The
// input data (and reference data) should be generated using the
// median_gendata.pl perl script and dumped to a file named
// dataset1.h.

#include "myClib.h"

#include "median.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

//verify
int verify (int size, int* result_data, int* verify_data) {
  int ret = 1;
  char number[10];
  for (int i=0; i < size; i++) {
    ret = ret & (result_data[i] == verify_data[i]);
    if (result_data[i] != verify_data[i]) {
      itoa(result_data[i], 10, 0, 0, number, 0);
      write_string("Fails at ");
      write_string(number); write_char('\n');
      break;
    }
  }
  if (ret == 1)
    write_string("PASSED!");
  return ret;
}

//--------------------------------------------------------------------------
// Main
int main( int argc, char* argv[] )
{
  int results_data[DATA_SIZE];

  median( DATA_SIZE, input_data, results_data );

  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
