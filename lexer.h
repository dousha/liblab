#ifndef LIBLAB_LEXER_H
#define LIBLAB_LEXER_H

// this is actually a strange stuff

#include <stdint.h>
#include <stddef.h>

#define TOKEN_LEN 256 // bytes

typedef
enum lexerStatus{
	LEX_EMPTY = 0,
	LEX_NUMBER,
	LEX_IDENTIFIER,
	LEX_OPERATOR,
	LEX_NUMBER_IMMEDIATE,
	LEX_STRING_IMMEDIATE,
	LEX_ERROR
}
lexerStatus;

typedef
struct lexer{
	lexerStatus status;
	char* now;
	char* next;
	const char* glob;
	size_t lastPos;
}
lexer_t;

extern lexer_t* lexer_start(const char*);
extern uint8_t lexer_next(lexer_t*);
extern void lexer_stop(lexer_t*);

#endif //LIBLAB_LEXER_H
