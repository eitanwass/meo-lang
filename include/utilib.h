#ifndef __MEO_UTILIB_H__
#define __MEO_UTILIB_H__

#define UNUSED(x) (void)x

#define MAX(a, b)   \
typeof(a) _a = a;   \
typeof(b) _b = b;   \
_a > _b ? _a : _b

#endif  // __MEO_UTILIB_H__
