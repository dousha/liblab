#include <string.h>
#include <stdlib.h>
#include <stddef.h>

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
 * @brief A wrapper function of @refitem strcex where delim=' '.
 * @param src Source string
 * @param dest Destination string
 * @param offset Starting position
 * @return Offset after extracting process
 */
size_t strbex(const char* src, char* dest, size_t offset){
	return strcex(src, dest, ' ', offset);
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

void strrcpy(const char* src, char* dest, size_t from, size_t to){
	if(from >= to) return;
	if(to > strlen(src)) to = strlen(src);
	for(size_t i = from; i < to; i++){
		dest[i - from] = src[i];
	}
	dest[to - from] = 0;
}