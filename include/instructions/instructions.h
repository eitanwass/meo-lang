#ifndef __MEO_INSTRUCTIONS_H__
#define __MEO_INSTRUCTIONS_H__

#include "common.h"
#include "chunk.h"
#include "ops.h"
#include "vm.h"

typedef OpResult (*OpDispatch)(VM* vm, bool* should_exit);

extern OpDispatch dispatch[OP_COUNT];
extern const char* opcodeNames[OP_COUNT];

#define F(x) extern OpResult x##_handler(VM* vm, bool* should_exit);
OPCODE_LIST(F)
#undef F

static inline OpResult executeInstruction(VM* vm, bool* should_exit) {
    uint8_t instruction = READ_INSTRUCTION(vm);

    if (instruction >= OP_COUNT) {
        return OP_RESULT_FAIL;
    }

    return dispatch[instruction](vm, should_exit);
}

static inline const char* getOpcodeName(OpCode op) {
    return (op < OP_COUNT) ? opcodeNames[op] : "UNKNOWN";
}

#endif  // __MEO_INSTRUCTIONS_H__
