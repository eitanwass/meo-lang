#include "vm.h"
#include "ops.h"

#define BINARY_OP(stack, op)                \
    do {                                    \
        uint32_t b = POP(stack);            \
        uint32_t a = POP(stack);            \
        PUSH(stack, a op b);                \
    } while(0)

OpResult OP_ADD_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    BINARY_OP(&vm->stack, +);

    return OP_RESULT_SUCCESS;
}

OpResult OP_SUB_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    BINARY_OP(&vm->stack, -);

    return OP_RESULT_SUCCESS;
}

OpResult OP_MUL_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    BINARY_OP(&vm->stack, *);

    return OP_RESULT_SUCCESS;
}

OpResult OP_DIV_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    BINARY_OP(&vm->stack, /);

    return OP_RESULT_SUCCESS;
}

OpResult OP_NEGATE_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    PUSH(&vm->stack, -POP(&vm->stack));

    return OP_RESULT_SUCCESS;
}
