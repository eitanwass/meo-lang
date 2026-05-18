#ifndef __MEO_STACK_H__
#define __MEO_STACK_H__

#include "common.h"

#define STACK_MAX (256)

typedef struct {
    uint32_t data[STACK_MAX];
    // The stack pointer - top of the stack (after the last item)
    uint32_t* sp;
} Stack;

static inline void resetStack(Stack* stack) {
    stack->sp = stack->data;
}

#define PUSH(stack, val) do {   \
    *(stack)->sp = val;           \
    (stack)->sp++;                \
} while(0)

#define POP(stack) ({           \
    (stack)->sp--;                \
    *(stack)->sp;                 \
})

#endif  // __MEO_STACK_H__
