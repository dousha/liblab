#ifndef LIBLAB_STRUTILS_H
#define LIBLAB_STRUTILS_H

#include <stddef.h>

extern size_t strcex(const char*, char*, const char, size_t);
extern size_t strbex(const char*, char*, size_t);
extern void stradd(char*restrict, char);

#endif //LIBLAB_STRUTILS_H
