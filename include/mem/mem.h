#ifndef __MEO_mem_H__
#define __MEO_mem_H__

#include "common.h"

#define INITIAL_CAPACITY (8)

#define GROW_CAPACITY(capacity) \
    ((capacity) < INITIAL_CAPACITY ? INITIAL_CAPACITY : (capacity) * 2)

#define GROW_ARRAY(type, ptr, oldCount, newCount) \
    (type*)reallocate(ptr, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

#define FREE_ARRAY(type, ptr, oldCount) \
    reallocate(ptr, sizeof(type) * (oldCount), 0)

void* reallocate(void* ptr, size_t oldSize, size_t newSize);

#endif  // __MEO_mem_H__
