// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#ifndef _MAIN_H
#define _MAIN_H
#include <stdint.h>
#include "emulator.h"

class emulator_child : public emulator{
    public:
    int load_mem (const char* filename);
    int risc_cpu ();
};

#endif