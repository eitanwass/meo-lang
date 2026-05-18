#include "vm.h"
#include "ops.h"

OpResult OP_NOP_handler(VM* vm, bool* should_exit) {
    UNUSED(vm);
    UNUSED(should_exit);
    return OP_RESULT_SUCCESS;
}
