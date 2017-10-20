#ifndef LIBLAB_BITS_H
#define LIBLAB_BITS_H

#include <stdint.h>

typedef
struct bits{
	uint32_t len;
	uint8_t *bits;
}
bits_t;

extern bits_t* bits_new(uint32_t);
extern void bits_delete(bits_t*);
extern uint8_t bits_test(bits_t*, uint32_t);
extern void bits_set(bits_t*, uint32_t);
extern void bits_clear(bits_t*, uint32_t);

#endif //LIBLAB_BITS_H
