#ifndef __MEO_OPS_H__
#define __MEO_OPS_H__

#define OPCODE_LIST(F)  \
    F(OP_NOP)           \
    F(OP_RETURN)        \
    F(OP_CONSTANT)      \
    F(OP_ADD)           \
    F(OP_SUB)      \
    F(OP_MUL)      \
    F(OP_DIV)        \
    F(OP_NEGATE)

typedef enum {
#define F(op) op,
    OPCODE_LIST(F)
#undef F
    OP_COUNT,
} OpCode;

typedef enum {
    OP_RESULT_INVALID,
    OP_RESULT_SUCCESS,
    OP_RESULT_FAIL,
} OpResult;

#endif  // __MEO_OPS_H__
