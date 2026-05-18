#ifndef __MEO_VM_H__
#define __MEO_VM_H__

#include "chunk.h"
#include "value.h"
#include "stack.h"

#define READ_INSTRUCTION(vm) (*vm->ip++)
#define READ_BYTE(vm) (*vm->ip++)
#define READ_CONSTANT(vm) (vm->chunk->constants.values[READ_BYTE(vm)])

#define STACK_MAX (256)

typedef struct {
    Chunk* chunk;
    uint8_t* ip;        // Instruction pointer - points at the current instruction
    Stack stack;
} VM;

typedef enum {
    INTERPRET_INVALID,
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM(VM* vm);
void freeVM(VM* vm);

InterpretResult interpret(VM* vm, Chunk* chunk);

#endif  // __MEO_VM_H__
