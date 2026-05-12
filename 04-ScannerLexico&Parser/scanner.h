#ifndef SCANNER_H
#define SCANNER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    EQUAL,
    ASTERISK,
    KW_INT,
    KW_CHAR,
    PARS,
    LPAR,
    RPAR,
    BRACKETS,
    ID,        
    LIT_NUM,               
    PUNCT,
    NL,
    FIN, //ESTO NO ES PARTE DE LA ESPECIFICACION, SOLO REPRESENTA EOF
    error_lex
} TokenType;
typedef union {
    int identificador;
    unsigned long long int valorLiteral;
} TokenValue;
typedef struct {
    TokenType type;
    char lexeme[128];  // lexema
    TokenValue valor;    // valor asociado
} Token;

// Prototipos
bool GetNextToken(Token *);
void procesar(FILE *output, Token token);
FILE* SetSource(FILE*);
FILE* GetSource();

#endif
