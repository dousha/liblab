#include <stdlib.h>

#include "bits.h

/**
 * @brief Create a bit container
 * @param len Length in bit
 * @return Pointer to the container
 * @warning Must use `bits_delete' to free the container after use!
 * @author dousha
 */
bits_t* bits_new(uint32_t len){
	bits_t* res = malloc(sizeof(bits_t));
	res->bits = malloc(sizeof(uint8_t) * ((len + 4) / 8));
	return res;
}

/**
 * @brief Free a bit container
 * @param b Pointer to the container
 * @author dousha
 */
void bits_delete(bits_t* b){
	free(b->bits);
	free(b);
}

/**
 * @brief Test if a bit is set
 * @param b Pointer to the bits container
 * @param n Specific bit
 * @return 0 = False.
 * 			Else = True.
 */
uint8_t bits_test(bits_t* b, uint32_t n){
	return (uint8_t) (b->bits[n / 8] & (1 << (n % 8)));
}

/**
 * @brief Set a bit
 * @param b Pointer to the bits container
 * @param n Specific bit
 */
void bits_set(bits_t* b, uint32_t n){
	b->bits[n / 8] |= (1 << (n % 8));
}

/**
 * @brief Clear a bit
 * @param b Pointer to the bits container
 * @param n Specific bit
 */
void bits_clear(bits_t* b, uint32_t n){
	b->bits[n / 8] ^= (1 << (n % 8));
}
