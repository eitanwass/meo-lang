#ifndef __MEO_LINES_H__
#define __MEO_LINES_H__

#include "var_arr.h"

#define LINE_RUN_MAX_COUNT (0xFF)
#define LINE_RUN_COUNT(entry) ((entry) & 0xFF)
#define LINE_RUN_LINE(entry) ((entry) >> 8)
#define MAKE_LINE_RUN(line, count) (((size_t)(line) << 8) | (size_t)(count))

VAR_ARR_DEC(size_t, Line)

#endif  // __MEO_LINES_H__
