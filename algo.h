#ifndef LIBLAB_ALGO_H
#define LIBLAB_ALGO_H

#include <stdint.h>
#include <stddef.h>

#define in_range(n, l, r) (l < n && n < r)
#define OFFSET_FUNC_DECL(type) \
void* type##_offset_func(const void* arr, size_t offset){ \
	return ((void*) (((type##*) arr) + offset)); \
}

/// Offset function should return correct address of
/// target array with a offset specified
/// You can use OFFSET_FUNC_DECL to automatically generate offset function
/// the name of function would be <Type>_offset_func
typedef void* (*offsetFunction)(const void*, size_t);
/// Compare function should return -1, 0, 1 to
/// respectively tell if left is smaller than, equal to, or
/// greater than right.
typedef int8_t (*compareFunction)(const void*, const void*);
typedef void (*swapFunction)(const void*, const void*);
/// Print function should print out (interested) value of
/// passed object pointer
typedef void (*printFunction)(const void*);

// some common offset functions
extern void* int_offset_function(const void*, size_t);

// some common compare functions
extern int8_t int_compare_func(const void *, const void *);
extern int8_t double_compare_func(const void *, const void *);

// some common swap functions
extern void int_swap_func(const void*, const void*);

// some common print functions
extern void int_print_func(const void*);

extern void print_array(const void*, size_t, printFunction);

extern void bubble_sort(const void*, size_t, offsetFunction, compareFunction, swapFunction);
extern void quick_sort(const void*, size_t, offsetFunction, compareFunction, swapFunction);

#endif //LIBLAB_ALGO_H
