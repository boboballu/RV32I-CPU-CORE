#ifndef _EMULATOR_CHILD_H_
#define _EMULATOR_CHILD_H_

#include <stdint.h>
#include "emulator.h"

class emulator_child : public emulator{
    public:
    emulator_child(bool emuOutput, uint32_t consoleAddr, uint32_t haltAddr);
    int load_mem (const char* filename);
    int risc_cpu ();
};

#endif