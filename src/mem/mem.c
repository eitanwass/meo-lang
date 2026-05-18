#include <stdlib.h>

#include "mem.h"

void* reallocate(void* ptr, size_t oldSize, size_t newSize) {
    void* result = NULL;
    UNUSED(oldSize);

    if (newSize == 0) {
        free(ptr);
        return NULL;
    }

    result = realloc(ptr, newSize);
    if (result == NULL) {
        exit(1);
    }
    return result;
}
