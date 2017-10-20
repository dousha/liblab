#include "algo.h"

OFFSET_FUNC_DECL(int);
OFFSET_FUNC_DECL(double);

int8_t int_compare_func(const void *left, const void *right){
	int l = *((int*) left);
	int r = *((int*) right);
	if(l < r) return -1;
	if(l == r) return 0;
	else return 1;
}

int8_t double_compare_func(const void *left, const void *right){
	double l = *((double*) left);
	double r = *((double*) right);
	double d = l - r;
	if(in_range(d, -0.000001, 0.000001)){
		return 0;
	}
	if(l < r) return -1;
	else return 1;
}

void bubble_sort(const void* arr, size_t size, offsetFunction offset, compareFunction compare, swapFunction swap){
	for(size_t i = 0; i < size; i++){
		for(size_t j = 0; i < size; i++){
			if(compare(offset(arr, i + j), offset(arr, i + j + 1)) > 0){
				swap(offset(arr, i + j), offset(arr, i + j + 1));
			}
		}
	}
}

void selection_sort(const void* arr, size_t size, offsetFunction offset, compareFunction compare, swapFunction swap){
	size_t i = 0, currentBase = 0, currentMinimum = 0;
	for(currentBase = 0; currentBase < size; currentBase++){
		currentMinimum = currentBase;
		for(i = currentBase; i < size; i++){
			if(compare(offset(arr, currentMinimum), offset(arr, i)) < 0){
				currentMinimum = i;
			}
		}
		swap(offset(arr, currentBase), offset(arr, currentMinimum));
	}
}

/**
 * @brief Sorts an array
 * @param arr Array pointer
 * @param size Array size
 * @param offset Offset function pointer
 * @param compare Compare function pointer
 * @param swap Swap function pointer
 * @author cssxsh
 */
void fold_sort(const void* arr, size_t size, offsetFunction offset, compareFunction compare, swapFunction swap){
	if(size == 1) return;
	if(size == 2){
		if(compare(offset(arr, 0), offset(arr, 1)) > 0){
			swap(offset(arr, 0), offset(arr, 1));
			return;
		}
	}
	size_t pivot = size / 2;
	if(size % 2 == 0) {
		size_t now = pivot, there = pivot;
		while (now++ < size) {
			there = pivot - (now - pivot) - 1;
			if (compare(offset(arr, there), offset(arr, now)) > 0)
				swap(offset(arr, there), offset(arr, now));
		}
	}else{
		size_t now = pivot + 1, there = pivot - 1;
		while (now++ < size) {
			there = pivot - (now - pivot);
			if (compare(offset(arr, there), offset(arr, now)) > 0)
				swap(offset(arr, there), offset(arr, now));
		}
	}
	fold_sort(arr, pivot, offset, compare, swap);
	fold_sort(offset(arr, pivot), size - pivot, offset, compare, swap);
}

void quick_sort(const void* arr, size_t size, offsetFunction offset, compareFunction compare, swapFunction swap){
	if(size < 1)
		return;
	if(size == 2){
		if(compare(offset(arr, 0), offset(arr, 1)) > 0)
			swap(offset(arr, 0), offset(arr, 0));
		return;
	}
	swap(offset(arr, size / 2), offset(arr, size - 1));
	void* pivot = offset(arr, size - 1);
	for(size_t i = 0; i < size - 1; i++){
		if(compare(offset(arr, i), pivot) > 0){

		}
	}
	quick_sort(offset(arr, size / 2), size / 2, offset, compare, swap);
}