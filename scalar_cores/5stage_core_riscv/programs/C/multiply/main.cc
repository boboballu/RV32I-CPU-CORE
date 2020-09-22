// See LICENSE for license details.

// *************************************************************************
// multiply filter bencmark
// -------------------------------------------------------------------------
//
// This benchmark tests the software multiply implemenation. The
// input data (and reference data) should be generated using the
// multiply_gendata.pl perl script and dumped to a file named
// dataset1.h

#include "myClib.h"

#include "multiply.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"

//--------------------------------------------------------------------------

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

// Main
int main( int argc, char* argv[] )
{
  int i;
  int results_data[DATA_SIZE];

  for (i = 0; i < DATA_SIZE; i++)
  {
    results_data[i] = multiply( input_data1[i], input_data2[i] );
  }
  // Check the results
  return verify( DATA_SIZE, results_data, verify_data );
}
