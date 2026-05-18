#include "instructions.h"

OpDispatch dispatch[OP_COUNT] = {
#define F(op) [op] = op##_handler,
    OPCODE_LIST(F)
#undef F
};

const char* opcodeNames[OP_COUNT] = {
#define F(op) [op] = #op,
    OPCODE_LIST(F)
#undef F
};