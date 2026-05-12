#include "declaraciones.h"

int main(){ // parser
    FILE *input;
    //input = fopen("test_heavy.c", "r");
    input = fopen("test.c", "r");
    if (!input) {
        printf("No se pudo abrir el archivo de Entrada");
        fclose(input);
        return EXIT_FAILURE;
    }
    SetSource(input);
    FILE *output;
    output = fopen("outputParser.txt", "w");
    if (!output) {
        printf("No se pudo abrir el archivo de Salida");
        fclose(output);
        return EXIT_FAILURE;
    }
    char temp[200];

    while(GetNextToken(&token) && token.type!=FIN) {
        if (token.type == KW_CHAR || token.type == KW_INT) {
            //se filtra para solo tener los inicializaciones
            tipo[0] = '\0';
            temp[0] = '\0';
            out[0] = '\0';
            nombre[0] = '\0';

            cont_sentencia = 0;
            sentencia[cont_sentencia] = token;
            cont_sentencia++;

            strcpy(tipo, token.lexeme);
            dcl();

            if(token.type==PUNCT)
            {
                sprintf(temp, "%s : %s%s\n", nombre, out, tipo);
                fputs(temp, output);  
            }else{
                rutinaErrorSintactico(';');
                sprintf(temp, "%s : %s%s\n", nombre, out, tipo);
                fputs(temp, output);
            }
            
        }
    }

    fclose(input);
    fclose(output);
    return EXIT_SUCCESS;
}
