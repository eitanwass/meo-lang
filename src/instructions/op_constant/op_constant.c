#include "value.h"
#include "vm.h"
#include "ops.h"

OpResult OP_CONSTANT_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);
    Value constant = READ_CONSTANT(vm);
    PUSH(&vm->stack, constant);
    return OP_RESULT_SUCCESS;
}