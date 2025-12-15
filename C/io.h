////////////////////////////////////////////////////////////////
//                                                            //
// input/output library                                       //
//                                                            //
////////////////////////////////////////////////////////////////

#ifndef __IO_H
#define __IO_H

#include "core.h"

void ReadFile(
    const char* __path__
);

void WriteFile(
    const char* __path__,
    void* __buffer__
);

vPtr OpenFile(
    const char* path

);


#endif