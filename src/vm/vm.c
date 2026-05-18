#include "common.h"
#ifdef DEBUG_TRACE_EXECUTION
#include "debug.h"
#endif  // DEBUG_TRACE_EXECUTION
#include "vm.h"
#include "instructions.h"


static InterpretResult run(VM* vm) {
    bool shouldStop = false;

    while (!shouldStop && vm->ip - vm->chunk->code != vm->chunk->count) {
#ifdef DEBUG_TRACE_EXECUTION
        printf("\t\t");
        for (uint32_t* val = vm->stack.data; val < vm->stack.sp; val++) {
            printf("[");
            printValue(*val);
            printf("]");
        }
        printf("\t\t");
        disassembleInstruction(
            vm->chunk,
            vm->ip - vm->chunk->code
        );
#endif  // DEBUG_TRACE_EXECUTION
        OpResult result = executeInstruction(vm, &shouldStop);
        if (result != OP_RESULT_SUCCESS) {
            return INTERPRET_RUNTIME_ERROR;
        }
    }

    return INTERPRET_OK;
}

void initVM(VM* vm) {
    resetStack(&vm->stack);
}

void freeVM(VM* vm) {
    UNUSED(vm);
}

InterpretResult interpret(VM* vm, Chunk* chunk) {
    vm->chunk = chunk;
    vm->ip = chunk->code;
    return run(vm);
}