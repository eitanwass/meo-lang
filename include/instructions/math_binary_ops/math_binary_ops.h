#ifndef __MEO_MATH_BINARY_OPS_H__
#define __MEO_MATH_BINARY_OPS_H__

#include "ops.h"
#include "vm.h"

OpResult OP_ADD_handler(VM* vm, bool* should_exit);
OpResult OP_SUB_handler(VM* vm, bool* should_exit);
OpResult OP_MUL_handler(VM* vm, bool* should_exit);
OpResult OP_DIV_handler(VM* vm, bool* should_exit);
OpResult OP_NEGATE_handler(VM* vm, bool* should_exit);

#endif  // __MEO_MATH_BINARY_OPS_H__
