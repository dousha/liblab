#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

/**
 * @brief Extract a substring split by delim
 * @details Extract a part of string until reached either delim, NULL or new line.
 * 			String extracted will be stored in dest with zero ending auto added.
 * @param src Source string
 * @param dest Destination string
 * @param delim Splitting character
 * @param offset Starting position
 * @return Offset after extracting process
 * @warning Buffer overrun may occur if dest is not long enough
 * @author dousha
 */
size_t strcex(const char* src, char* dest, const char delim, size_t offset){
	size_t left = offset, right = 0;
	for(left = offset; left < strlen(src); left++){
		if(src[left] != delim){
			for(right = left; right < strlen(src); right++){
				if(src[right] == delim || src[right] == 0){
					size_t i = 0;
					for(i = 0; i < right - left; i++){
						dest[i] = src[left + i];
					}
					dest[i + 1] = 0;
					return right;
				}
			}
		}
	}
	return 0;
}

/**
 * @brief Extracts substring separated by whitespace.
 * @param src Source string
 * @param dest Destination string
 * @param offset Starting position
 * @return Offset after extracting process
 */
size_t strbex(const char* src, char* dest, size_t offset){
	size_t left = offset, right = 0;
	for(left = offset; left < strlen(src); left++){
		if(!isblank(src[left])){
			for(right = left; right < strlen(src); right++){
				if(isblank(src[right]) || src[right] == 0){
					size_t i = 0;
					for(i = 0; i < right - left; i++){
						dest[i] = src[left + i];
					}
					dest[i + 1] = 0;
					return right;
				}
			}
		}
	}
	return 0;
}

/**
 * @brief Appends a char to a string.
 * @param dest Destination string
 * @param c Character
 * @warning Buffer overrun may occur if dest is not long enough
 * @author dousha
 */
void stradd(char*restrict dest, char c){
	dest[strlen(dest) - 1] = c;
	dest[strlen(dest)] = 0;
}

/**
 * @brief Copy a substring with specified range
 * @param src Source string
 * @param dest Destination string
 * @param from Starting index (included)
 * @param to Ending index (excluded)
 * @warning Buffer overrun my occur if dest is not long enough
 * @author dousha
 */
void strrcpy(const char* src, char* dest, size_t from, size_t to){
	if(from >= to) return;
	if(to > strlen(src)) to = strlen(src);
	for(size_t i = from; i < to; i++){
		dest[i - from] = src[i];
	}
	dest[to - from] = 0;
}

/**
 * @brief Check if a specific char exists in a string
 * @param str Target string
 * @param c Char
 * @return 0 = Not found. 1 otherwise.
 * @author dousha
 */
uint8_t strhas(const char*restrict str, const char c){
	for(size_t i = 0; i < strlen(str); i++){
		if(c == str[i]) return 1;
	}
	return 0;
}