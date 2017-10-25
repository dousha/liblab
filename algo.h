#ifndef LIBLAB_ALGO_H
#define LIBLAB_ALGO_H

#include <stdint.h>
#include <stddef.h>

#define in_range(n, l, r) (l < n && n < r)
#define OFFSET_FUNC_IMPL(type) \
void* type##_offset_func(const void* arr, size_t offset){ \
	return ((void*) (((type##*) arr) + offset)); \
}
#define OFFSET_FUNC_DECL(type) \
extern void* type##_offset_function(const void*, size_t)
#define COMPARE_FUNC_DECL(type) \
extern int8_t type##_compare_func(const void*, const void*)
#define SWAP_FUNC_DECL(type) \
extern void type##_swap_func(const void*, const void*)
#define SORT_ALGO_DECL(name) \
extern void name(const void*, size_t, offsetFunction, compareFunction, swapFunction)

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

OFFSET_FUNC_DECL(int);
OFFSET_FUNC_DECL(double);

COMPARE_FUNC_DECL(int);
COMPARE_FUNC_DECL(double);

SWAP_FUNC_DECL(int);
SWAP_FUNC_DECL(double);

// some common print functions
extern void int_print_func(const void*);

extern void print_array(const void*, size_t, printFunction);

SORT_ALGO_DECL(bubble_sort);
SORT_ALGO_DECL(quick_sort);
SORT_ALGO_DECL(fold_sort);

#endif //LIBLAB_ALGO_H
