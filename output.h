#ifndef LIBLAB_OUTPUT_H
#define LIBLAB_OUTPUT_H

#include <stddef.h>

extern size_t output_console_width();
extern size_t output_console_height();
extern void output_align_right(char*);
extern void output_align_justified(char*, size_t);

#endif //LIBLAB_OUTPUT_H
