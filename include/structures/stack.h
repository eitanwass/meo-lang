#ifndef __MEO_STACK_H__
#define __MEO_STACK_H__

#include "common.h"
#include "mem.h"

#define INITIAL_STACK_MAX (256)

typedef struct {
    size_t size;
    uint32_t* data;

    // The stack pointer - top of the stack (after the last item)
    uint32_t* sp;
} Stack;

static inline void resetStack(Stack* stack) {
    stack->size = INITIAL_STACK_MAX;
    stack->data = GROW_ARRAY(uint32_t, stack->data, 0, stack->size);
    stack->sp = stack->data;
}

#define PUSH(stack, val) do {                                   \
    if ((stack)->sp >= (stack)->data + (stack)->size) {         \
        size_t oldCapacity = (stack)->size;                     \
        size_t offset = (stack)->sp - (stack)->data;            \
        (stack)->size = GROW_CAPACITY(oldCapacity);             \
        (stack)->data = GROW_ARRAY(                             \
            uint32_t,                                           \
            (stack)->data,                                      \
            oldCapacity,                                        \
            (stack)->size                                       \
        );                                                      \
        (stack)->sp = (stack)->data + offset;                   \
    }                                                           \
    *(stack)->sp = val;                                         \
    (stack)->sp++;                                              \
} while(0)

#define POP(stack) ({   \
    (stack)->sp--;      \
    *(stack)->sp;       \
})

#endif  // __MEO_STACK_H__
