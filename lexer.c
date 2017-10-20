//
// Created by dousha on 17-10-16.
//

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lexer.h"
#include "strutils.h"

static void _lexer_roll_forward(lexer_t* lexer){
	// this function is called to roll forward
	while(isblank(lexer->glob[lexer->lastPos])) ++lexer->lastPos;
}

static void _lexer_shift_in(lexer_t* lexer){
	strncpy(lexer->now, lexer->next, TOKEN_LEN);
	memset(lexer->next, 0, TOKEN_LEN);
}

lexer_t* lexer_start(const char* text){
	lexer_t* lexer = malloc(sizeof(lexer_t));
	if(lexer == NULL) return NULL;

	lexer->status = LEX_EMPTY;
	lexer->glob = text;
	lexer->lastPos = 0;
	lexer->now = malloc(sizeof(char) * TOKEN_LEN);
	lexer->next = malloc(sizeof(char) * TOKEN_LEN);
	if(lexer->now == NULL || lexer->next == NULL){
		return NULL;
	}
	return lexer;
}

uint8_t lexer_next(lexer_t* lexer){
	/**
	 * Lexer splits token according to these rules:
	 * 1. Whitespaces separates a token
	 * 2. If a digit is read in blank state, assumes a number, read until a non-number char is read
	 * 3. New line separates a token
	 * 4. Brackets forms a token on itself
	 * 5. Non-letters, such as punctuations, are treated as operators, and forms the longest possible token
	 */
	if(lexer->status == LEX_ERROR) return 255;

	size_t i = lexer->lastPos;
	char c = 0;
	while((c = lexer->glob[i]) != 0){
		if(isblank(c)){
			if(lexer->status != LEX_EMPTY){

			}
		}else if(isdigit(c)){

		}else if(isalpha(c)){
			if(lexer->status == LEX_IDENTIFIER){
				stradd(lexer->next, c);
			}
		}else{

		}
		++i;
	}
}

void lexer_stop(lexer_t* lexer){

}