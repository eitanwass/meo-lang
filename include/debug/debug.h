#ifndef __MEO_DEBUG_H__
#define __MEO_DEBUG_H__

#include <stdio.h>
#include "chunk.h"
#include "ops.h"
#include "instructions.h"

typedef size_t (*OpDisassemble)(Chunk* chunk, const char* name, size_t offset);

void disassembleChunk(Chunk* chunk, const char* name);
size_t disassembleInstruction(Chunk* chunk, size_t offset);

#endif  // __MEO_DEBUG_H__
