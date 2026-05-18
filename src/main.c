#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "vm.h"
#include "debug.h"
#include "instructions.h"

int main(int argc, const char* argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    VM vm = {0};
    Chunk chunk = {0};

    initVM(&vm);
    initChunk(&chunk);

    size_t constantIdx = addConstant(&chunk, 1);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constantIdx, 1);

    constantIdx = addConstant(&chunk, 10);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constantIdx, 2);

    writeChunk(&chunk, OP_ADD, 2);

    constantIdx = addConstant(&chunk, 2);
    writeChunk(&chunk, OP_CONSTANT, 2);
    writeChunk(&chunk, constantIdx, 2);

    writeChunk(&chunk, OP_DIV, 2);

    writeChunk(&chunk, OP_NEGATE, 2);

    writeChunk(&chunk, OP_RETURN, 2);

    interpret(&vm, &chunk);

    freeVM(&vm);
    freeChunk(&chunk);

    return 0;
}
