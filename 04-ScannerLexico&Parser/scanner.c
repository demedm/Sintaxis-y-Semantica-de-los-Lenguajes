#include "scanner.h"
#include <string.h>
#include <ctype.h>

static FILE* currentSource = NULL;

FILE* SetSource(FILE* newSource)
{
    FILE* previousSource = currentSource;
    currentSource = newSource;
    return previousSource;
}
FILE* GetSource()
{
    return currentSource;
}


int id_token = 0;

TokenType checkKeyword(char* lexeme) {
    if(strcmp(lexeme, "int") == 0) return KW_INT;
    if(strcmp(lexeme, "char") == 0) return KW_CHAR;
    return ID;
}

bool GetNextToken(Token *t) {
    FILE *input = GetSource();
    int c;
    while(c = fgetc(input)){
        if (isalpha(c) || c == '_') {
            int i = 0;
            t->lexeme[i++] = c;
            while ( (c = fgetc(input)) != EOF && (isalpha(c) || c == '_' || isdigit(c)) ) {
                t->lexeme[i++] = c;
            }
            //si no saliste del while sobre un caracter valido (los que te llevan a Out), en el medio hubo un caracter invalido
            if (c != EOF && c != ' ' && c != ';' && c != '*' && c != '(' && c != ')' && c != '[' && c!='\n'){
                t->lexeme[i++] = c;
                //se lee el resto de la cadena y se le asigna el tipo error_lex
                while((c = fgetc(input)) != EOF && c != ' ' && c != ';' && c != '*' && c != '(' && c != ')' && c != '['){
                    t->lexeme[i++] = c;
                }
                t->lexeme[i] = '\0';
                t->type = error_lex;
                ungetc(c, input);
                return true;
            }
            t->lexeme[i] = '\0';

            t->type = checkKeyword(t->lexeme);
            t->valor.identificador = id_token++;
            ungetc(c, input);
            return true;
        }

    if (isdigit(c)) {
        int i = 0;
        t->lexeme[i++] = c;
        while ( (c = fgetc(input)) != EOF && isdigit(c)) {
            t->lexeme[i++] = c;
        }
        if (c != EOF && c != ' ' && c != ';' && c != '*' && c != '(' && c != ')' && c != '['){
            t->lexeme[i++] = c;         //detecta si viene un caracter diferente a un numero antes de leer un espacio, op
            while((c = fgetc(input)) != EOF && c != ' ' && c != ';' && c != '*' && c != '(' && c != ')' && c != '['){
                t->lexeme[i++] = c;          //se lee el lexema invalido completo y posteriormente se lo califica como error
            }
            t->lexeme[i] = '\0';
            t->type = error_lex;
            ungetc(c, input);
            return true;
        }
        t->lexeme[i] = '\0';
        t->type = LIT_NUM;
        t->valor.valorLiteral = strtoull(t->lexeme, NULL, 10);
        ungetc(c, input);
        return true;
    }
    int i = 0;
    switch(c) {
        case '*':
            t->type = ASTERISK;
            strcpy(t->lexeme, "*");
            return true;
        case '(':
            if((c = fgetc(input)) == ')'){
                t->type = PARS;
                strcpy(t->lexeme, "()");
            }else{
                t->type = LPAR;
                strcpy(t->lexeme, "(");
                ungetc(c, input);
            }
            return true;
        case ')':
            t->type = RPAR;
            strcpy(t->lexeme, ")");
            return true;
        case '[':
            t->type = BRACKETS;
            t->lexeme[i++] = '[';
            while((c = fgetc(input)) != ']'){
                t->lexeme[i++] = c;
            }
            t->lexeme[i++] = ']';
            t->lexeme[i] = '\0';
            return true;
        case ';':
            t->type = PUNCT;
            strcpy(t->lexeme, ";");
            return true;
        case EOF:
            t->type = FIN;
            t->lexeme[0] = '\0';
            return true;
        case '\n':
            t->type = NL;
            t->lexeme[0] = '\n';
            return true;
    }

    if (!isspace(c)) {
        t->type = error_lex;
        t->lexeme[i++] = c;
        while ( (c = fgetc(input)) != EOF && !isspace(c) && c != ';' && c != '*' && c != '(' && c != ')' && c != '[') {
            t->lexeme[i++] = c;
        }
        t->lexeme[i] = '\0';
        ungetc(c, input);
        return true;
    }
   }
   return false;
}

void procesar(FILE *output, Token token){
    char lex [180];

    switch (token.type){
        case ID:
            sprintf(lex, "ID, %s, %d\n", token.lexeme, token.valor);
            fputs(lex, output);
            //++id_token;
            break;
        case LIT_NUM:
            sprintf(lex, "LIT_NUM, %zu\n", token.valor.valorLiteral);
            (lex, output);
            break;
        case error_lex:
            sprintf(lex, "ERROR LEXICO, Secuencia invalida : %s\n", token.lexeme);
            fputs(lex, output);
            break;
        case KW_CHAR:
            sprintf(lex, "KEYWORD, %s, %d\n", token.lexeme, token.valor);
            fputs(lex, output);
            break;
        case KW_INT:
            sprintf(lex, "KEYWORD, %s, %d\n", token.lexeme, token.valor);
            fputs(lex, output);
            break;
        case NL:
            break; //saltea las nuevas lineas
        default:
            sprintf(lex, "%s\n", token.lexeme);
            fputs(lex, output);
            break;
    }
}
