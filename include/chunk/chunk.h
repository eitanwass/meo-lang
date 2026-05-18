#ifndef __MEO_CHUNK_H__
#define __MEO_CHUNK_H__

#include "common.h"
#include "value.h"
#include "lines/lines.h"


typedef struct {
    size_t capacity;
    size_t count;
    uint8_t* code;

    LineArray lines;

    ValueArray constants;
} Chunk;

void initChunk(Chunk* array);
void writeChunk(Chunk* array, uint8_t value, size_t line);
void freeChunk(Chunk* array);
size_t chunkLineAt(Chunk* chunk, size_t offset);

size_t addConstant(Chunk* chunk, Value value);

#endif  // __MEO_CHUNK_H__
