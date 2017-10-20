#ifndef LIBLAB_MATRIX_H
#define LIBLAB_MATRIX_H

#include <stddef.h>
#include "number.h"

typedef
struct matrix{
	size_t width;
	size_t height;
	number_t* content;
}
matrix_t;

extern matrix_t* matrix_new(size_t, size_t);
extern void matrix_swap_row(matrix_t*, size_t, size_t);
extern void matrix_swap_col(matrix_t*, size_t, size_t);
extern number_t matrix_det(matrix_t*);

#endif //LIBLAB_MATRIX_H
