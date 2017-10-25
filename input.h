#ifndef LIBLAB_INPUT_H
#define LIBLAB_INPUT_H

#include <stdint.h>

const char* INTEGER_PARTS = "1234567890-";
const char* HEX_PARTS = "1234567890abcdefABCDEFxX";
const char* FLOAT_PARTS = "1234567890.eE-+";

extern uint8_t is_number(const char*, size_t, size_t);
extern uint8_t input_parse(const char *, const char *, ...);
extern void input(const char*, const char*, ...);

#endif //LIBLAB_INPUT_H
