#include <stdio.h>

#include "debug.h"
#include "value.h"


static size_t simpleInstruction(const char* name, size_t offset) {
    printf("%s\n", name);
    return offset + 1;
}

static size_t OP_NOP_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_RETURN_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_CONSTANT_disassemble(Chunk* chunk, const char* name, size_t offset) {
    uint8_t constantIdx = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constantIdx);
    printValue(chunk->constants.values[constantIdx]);
    printf("'\n");
    return offset + 2;
}

static size_t OP_NEGATE_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_ADD_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_SUB_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_MUL_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

static size_t OP_DIV_disassemble(Chunk* chunk, const char* name, size_t offset) {
    UNUSED(chunk);
    return simpleInstruction(name, offset);
}

OpDisassemble disassembleDispatch[OP_COUNT] = {
#define F(op) [op] = op##_disassemble,
    OPCODE_LIST(F)
#undef F
};

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for(size_t offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

size_t disassembleInstruction(Chunk* chunk, size_t offset) {
    size_t line = chunkLineAt(chunk, offset);
    size_t previousLine = offset > 0 ? chunkLineAt(chunk, offset - 1) : SIZE_MAX;
    OpCode instruction = 0;

    printf("%04zu ", offset);

    if (offset > 0 && line == previousLine) {
        printf("   | ");
    } else {
        printf("%4zu ", line);
    }

    instruction = chunk->code[offset];
    if (instruction >= OP_COUNT) {
        printf("Unknown opcode %d\n", instruction);
        return offset + 1;
    }

    return disassembleDispatch[instruction](chunk, getOpcodeName(instruction), offset);
}