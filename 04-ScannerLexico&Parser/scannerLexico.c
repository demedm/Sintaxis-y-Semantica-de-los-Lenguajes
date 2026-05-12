#include "scanner.h"

int main() { //scanner lexico: convierte expresiones en tokens que almacena en output.txt
    FILE *input;
    input = fopen("test.c", "r");
    if (!input) {
        printf("No se pudo abrir el archivo de Entrada");
        fclose(input);
        return EXIT_FAILURE;
    }
    SetSource(input);
    FILE *output;
    output = fopen("output.txt", "w");
    if (!output) {
        printf("No se pudo abrir el archivo de Salida");
        fclose(output);
        return EXIT_FAILURE;
    }

    Token t;
    while(GetNextToken(&t) && t.type!=FIN) 
        procesar(output, t);

    char lex[10];
    sprintf(lex, "EOF\n");
    fputs(lex, output);
    
    fclose(input);
    fclose(output);
}