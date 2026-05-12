#include "declaraciones.h"

Token token;
Token sentencia[10]; //recoleccion de tokens y con proposito de comprobar estructura de la sentencia
int cont_sentencia = 0;
char tipo[100];
char out[1000];
char nombre[100];

void dcl(){
    int cant_punt = 0;
    GetNextToken(&token);
    sentencia[cont_sentencia] = token;
    cont_sentencia++;
    while(token.type == ASTERISK){
        cant_punt++;
        GetNextToken(&token);
        sentencia[cont_sentencia] = token;
        cont_sentencia++;  
    }

    dir_dcl();    

    while(cant_punt-- > 0)
        strcat(out, "apuntador a ");
}

void rutinaErrorLexico()
{
    fprintf(stderr, "PARSER: ---Rutina de omision de errores lexicos--- \n");
    strcpy(nombre,"ERROR LEXICO");
    strcpy(out,"$$$$$$$$$$$$$$$$$$$$");
    strcpy(tipo,"$$$$$$$$$$$$$$$$$$$$");
}
void rutinaErrorSintactico(char error)
{
    fprintf(stderr, "PARSER: ---Rutina de omision de errores lexicos--- \n");
    strcpy(nombre,"ERROR SINTACTICO");

    switch (error)
    {
        case '(':
            strcpy(out,"$$$ No se cerro correctamente un parentesis");
            strcpy(tipo," $$$");
            return;
        case ')':
            strcpy(out,"$$$ No se abrio correctamente un parentesis");
            strcpy(tipo," $$$");
            return;
        case ';':
            strcpy(out,"$$$$ NO SE ENCONTRO UN ; ");
            strcpy(tipo," $$$");
            return;
        default:
            strcpy(out,"$$$$$$$$$$$$$$$$$$$$");
            strcpy(tipo,"$$$$$$$$$$$$$$$$$$$$");
            return;
    }
}

void dir_dcl(){
    if(token.type == LPAR){
        dcl();
        if(token.type != RPAR){
            tipo[0] = '\0';
            out[0] = '\0';
            nombre[0] = '\0';
            rutinaErrorSintactico('(');
            return;
        }
    } else if (token.type == ID) {  
        strcpy(nombre,token.lexeme);
    } else if (token.type == error_lex) {
        // si se encuentra un error lexico, se descarta la declaracion entera
        do{
            GetNextToken(&token);
        }while(token.type!=PUNCT && token.type!=FIN);
        rutinaErrorLexico();
        return;
    } 

    GetNextToken(&token);
    sentencia[cont_sentencia] = token;
    cont_sentencia++;
    while((token.type == PARS || token.type == BRACKETS)){
        if (token.type == PARS){
            strcat(out, "funcion que regresa ");
        }else{
            strcat(out, "arreglo");
            strcat(out, " de ");
            if(strlen(token.lexeme) > 2)
            {
                char *aux = strtok(token.lexeme,"[]");
                strcat(aux, " ");
                strcat(out, aux);
            }
        }  
        GetNextToken(&token);
        sentencia[cont_sentencia] = token;
        cont_sentencia++;
    }
    //caso borde, si utilizo un parentesis de convocacion pero no lo completo
    //ej char vaca(; 
    if(token.type == LPAR){
        rutinaErrorSintactico('(');
        GetNextToken(&token);
        sentencia[cont_sentencia] = token;
        cont_sentencia++;
        return; 
    }
    else if(token.type == RPAR){
        int i = 0; int aux = cont_sentencia;
        while(aux)
        {
            if(sentencia[i].type==LPAR)
                return;
            i++;
            aux--;
        }
        rutinaErrorSintactico(')');
        GetNextToken(&token);
        return; 
    }
}