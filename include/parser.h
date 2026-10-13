#ifndef INCLUDE_INCLUDE_PARSER_H_
#define INCLUDE_INCLUDE_PARSER_H_

// R=C0, L=C1 => L>R = left
#define POSTFIX "\xC0\xC1"
#define PREFIX  "\xB1\xB0"
#define MD      "\xA0\xA1"
#define AS      "\x90\x91"
#define SHIFT   "\x80\x81"
#define REL     "\x70\x71"
#define EQ      "\x60\x61"
#define BAND    "\x50\x51"
#define BXOR    "\x40\x41"
#define BOR     "\x30\x31"
#define LAND    "\x20\x21"
#define LOR     "\x10\x11"
#define ASSIGN  "\x01\x00"
static const char* OPERATORS[] = {
    // postfix - must match first
    POSTFIX "++", POSTFIX "--",
    // prefix
    PREFIX "++", PREFIX "--", PREFIX "!", PREFIX "~",
    // multiplicative
    MD "*", MD "/", MD "%",
    // additive
    AS "+", AS "-",
    // shift - check <<= >>= before << >>
    SHIFT "<<", SHIFT ">>",
    // relational
    REL "<=", REL ">=", REL "<", REL ">",
    // equality
    EQ "==", EQ "!=",
    // bitwise
    BAND "&",
    BXOR "^",
    BOR "|",
    // logical
    LAND "&&",
    LOR "||",
    // assignment
    ASSIGN "<<=", ASSIGN ">>=", ASSIGN "+=", ASSIGN "-=",
    ASSIGN "*=", ASSIGN "/=", ASSIGN "%=", ASSIGN "&=",
    ASSIGN "^=", ASSIGN "|=", ASSIGN "~=", ASSIGN "=",
};

#endif  // INCLUDE_INCLUDE_PARSER_H_
