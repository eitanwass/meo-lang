#include <stdlib.h>

#include "chunk.h"
#include "mem.h"


void initChunk(Chunk* chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;

    initLineArray(&chunk->lines);
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, uint8_t value, size_t line) {
    if (chunk->capacity < chunk->count + 1) {
        size_t oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(
            uint8_t,
            chunk->code,
            oldCapacity,
            chunk->capacity
        );
    }

    chunk->code[chunk->count] = value;

    if (chunk->lines.count > 0) {
        size_t lastRun = chunk->lines.values[chunk->lines.count - 1];
        size_t lastLine = LINE_RUN_LINE(lastRun);
        size_t lastCount = LINE_RUN_COUNT(lastRun);

        if (lastLine == line && lastCount != LINE_RUN_MAX_COUNT) {
            chunk->lines.values[chunk->lines.count - 1] = MAKE_LINE_RUN(line, lastCount + 1);
        } else {
            writeLineArray(&chunk->lines, MAKE_LINE_RUN(line, 1));
        }
    } else {
        writeLineArray(&chunk->lines, MAKE_LINE_RUN(line, 1));
    }

    chunk->count++;
}

size_t chunkLineAt(Chunk* chunk, size_t offset) {
    size_t runOffset = 0;
    for (size_t i = 0; i < chunk->lines.count; i++) {
        size_t run = chunk->lines.values[i];
        size_t runCount = LINE_RUN_COUNT(run);
        if (offset < runOffset + runCount) {
            return LINE_RUN_LINE(run);
        }
        runOffset += runCount;
    }
    return 0;
}

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeLineArray(&chunk->lines);
    freeValueArray(&chunk->constants);
    /* Reset chunk */
    initChunk(chunk);
}

size_t addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    // Return location where constant was inserted at
    return chunk->constants.count - 1;
}

