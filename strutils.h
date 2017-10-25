#ifndef LIBLAB_STRUTILS_H
#define LIBLAB_STRUTILS_H

#include <stddef.h>

extern size_t strcex(const char*, char*, char, size_t);
extern size_t strbex(const char*, char*, size_t);
extern void stradd(char*restrict, char);
void strrcpy(const char* src, char*, size_t, size_t);
extern uint8_t strhas(const char*restrict, char);

#endif //LIBLAB_STRUTILS_H
