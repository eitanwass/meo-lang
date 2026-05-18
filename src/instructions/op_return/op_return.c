#include <stdio.h>
#include "vm.h"
#include "ops.h"


OpResult OP_RETURN_handler(VM* vm, bool* should_exit) {
    UNUSED(should_exit);

    printValue(POP(&vm->stack));
    printf("\n");

    return OP_RESULT_SUCCESS;
}
