#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "input.h"

uint8_t is_number(const char* str, size_t from, size_t to){
	// matches:
	// [+-]?\.?([0-9]+)(\.?[0-9]+)?([eE][+-]?[0-9]+)?
	if(strlen(str) == 0) return 0;
	size_t i = 0;
	uint8_t hasE = 0, hasSign = 0, hasPrefix = 0, hasDecimal = 0;
	if(to > strlen(str)) to = strlen(str);
	if(str[from] == '+' || str[from] == '-') hasPrefix = 1;
	else if(str[from] == '.') hasDecimal = 1;
	else if(!isdigit(str[from])) return 0;
	for(i = 1; i < to; i++){
		if(str[i] == '.'){
			if(hasDecimal) return 0;
			else hasDecimal = 1;
		}else if(str[i] == 'e' || str[i] == 'E'){
			if(hasE) return 0;
			else hasE = 1;
		}else if(str[i] == '+' || str[i] == '-'){
			if(hasE && (str[i - 1] == 'e' || str[i - 1] == 'E')) hasSign = 1;
			else return 0;
		}else if(!isdigit(str[i])) return 0;
	}
	return 1;
}

static int _next_int(const char* input, size_t* offset){

}

/**
 * @brief The ultimate scanf function.
 * @param fmt Format string
 * @param input User input
 * @param ... Pointer to each element
 * @return 0 = Failed. Other value = succeed
 * @warning Buffer overrun may occur on string operation
 */
uint8_t input_parse(const char *fmt, const char *input, ...){
	/**
	 * this function is a little bit tough.
	 * % - Denotes a format section
	 * 		u - unsigned ...
	 * 		d - int
	 * 		l - long
	 * 		f - float
	 * 		n - double
	 * 		c - char
	 * 		s - whitespace separated string
	 * 		S - string
	 * 		% - literal '%'
	 * _ - Denotes a typesetting section
	 * 		w - whitespace (space and tab)
	 * 		n - newline
	 * - - Denotes string length
	 * 		n- - at least n chars
	 * 		-m - at most m chars
	 * 		n-m - in this range (m included)
	 * () - Denotes a matching group (for %c and %s)
	 * 		%c(abc) = matches 'a', 'b' or 'c'.
	 * 		%s(abc|def) = matches "abc" or "def".
	 * 		if input doesn't match, counted as an error
	 * [] - Denotes a range (for %d, %l, %f, %n, and %c)
	 * 		%d[0,1] = matches '0' or '1'
	 * 		%f[0.12,1.12] = matches any float in between (boundaries included)
	 * 		%n[0.1,0.3|0.5,0.9] = matches any double in 0.1 to 0.3 and 0.5 to 0.9
	 * 		%d[!0, 5] = matches 1, 2, 3, 4, 5
	 * ? - Marks the last token is optional
	 * # - Marks the last token is silent (no need to write to variables)
	 *
	 * Any other character results an malformed expression and is counted as error
	 * if string length is not satisfied, validation process will stop and
	 * an error will be reported.
	 * the trailing newline is ignored (since fgets will keep the newline character)
	 * e.g.
	 * %d-4_w?%lf matches these inputs:
	 * 1234 0.5
	 * 123       0.5
	 * 1 1 (the latter 1 will be casted to double)
	 * 12340.5 (= 1234 0.5)
	 */
	va_list va;
	va_start(va, input);
	size_t formatOffset = 0, inputOffset = 0;
	while(fmt[formatOffset] != 0){
		switch(fmt[formatOffset]){
			case '%':
				switch(fmt[formatOffset + 1]){

					default:
						break;
				}
				break;
			case '_':
				break;
			default:
				break;
		}
	}
}