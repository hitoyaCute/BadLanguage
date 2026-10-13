#ifndef INCLUDE_INCLUDE_TOKENIZER_H_
#define INCLUDE_INCLUDE_TOKENIZER_H_
#include <stdint.h>


typedef enum TOKEN_TYPE:uint32_t {
	TOKEN_EOF = 0,
	// keywords
	TOKEN_IDENTIFIER,  // names_ types_t symbols
	TOKEN_BUILT_IN,    // typeof MEMBER_COUNT len sizeof
	// data
	TOKEN_NUMERAL_LIT, // 'C' 1 48 0.3 0x11 0b1001 23.f 8LL 9L 2u 9i
	TOKEN_STRING_LIT,  // "literals"
	TOKEN_COMMENT_LIT, // // line comment/s and /*miltiline*/
	// syntax
	TOKEN_COLLON,      // :
	TOKEN_SEMICOLON,   // ;
	TOKEN_DCOLLON,     // ::
	TOKEN_DOT,         // .
	TOKEN_COMMA,       // ,
	TOKEN_OPEN_CMP,    // <
	TOKEN_CLOSE_CMP,   // >
	TOKEN_OPEN_BRACK,  // [
	TOKEN_CLOSE_BRACK, // ]
	TOKEN_OPEN_PROP,   // [[
	TOKEN_CLOSE_PROP,  // ]]
	TOKEN_OPEN_CURL,   // {
	TOKEN_CLOSE_CURL,  // }
	TOKEN_OPEN_PAREN,  // (
	TOKEN_CLOSE_PAREN, // )
	TOKEN_OPERATOR,    // + - * / % && || ^ = ! += -= *= /= %= !=
} TOKEN_TYPE;

typedef struct Token_impl {
	const uint32_t address; // where is it on the file
	const TOKEN_TYPE type;
} token_t;
typedef struct tokenizer {
	const char* src; // null terminated view
	uint32_t current;
	uint32_t next; // for tokenizer_peek without processing
	
	token_t* token_pool;
	uint32_t count;
	uint32_t capacity;
} tokenizer;
tokenizer tokenizer_start(const char* src);
// consume the current token and compute the next token
token_t tokenizer_consume(tokenizer* tk);
// just check what's the next token
token_t tokenizer_peek(const tokenizer* tk);


#endif  // INCLUDE_INCLUDE_TOKENIZER_H_
