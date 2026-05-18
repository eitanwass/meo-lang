#ifndef __MEO_VAR_ARR_H__
#define __MEO_VAR_ARR_H__

#include "common.h"
#include "mem.h"


#define VAR_ARR_DEC(typ, name)                              \
typedef struct {                                            \
    size_t capacity;                                        \
    size_t count;                                           \
    typ* values;                                            \
} name##Array;                                              \
                                                            \
void init##name##Array(name##Array* array);                 \
void write##name##Array(name##Array* array, typ value);     \
void free##name##Array(name##Array* array);


#define VAR_ARR_IMPL(typ, name)                             \
void init##name##Array(name##Array* array) {                \
    array->values = NULL;                                   \
    array->capacity = 0;                                    \
    array->count = 0;                                       \
}                                                           \
                                                            \
void write##name##Array(name##Array* array, typ value) {    \
    if (array->capacity < array->count + 1) {               \
        size_t oldCapacity = array->capacity;               \
        array->capacity = GROW_CAPACITY(oldCapacity);       \
        array->values = GROW_ARRAY(typ,                     \
            array->values,                                  \
            oldCapacity,                                    \
            array->capacity                                 \
        );                                                  \
    }                                                       \
    array->values[array->count] = value;                    \
    array->count++;                                         \
}                                                           \
                                                            \
void free##name##Array(name##Array* array) {                \
    FREE_ARRAY(typ, array->values, array->capacity);        \
    /* Reset array */                                       \
    init##name##Array(array);                               \
}


#endif  // __MEO_VAR_ARR_H__
