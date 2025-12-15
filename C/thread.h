#ifndef __THREAD_H
#define __THREAD_H

#include "core.h"
#include "lib.h"

typedef struct __P_THREAD {
    vPtr                (*__function__)(void** __arguments__);
    void**              __arguments__;
    int                 __flags__;

} __P_THREAD_T;

void CreateThread(
    __P_THREAD_T* Thread
);

#endif