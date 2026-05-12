#include <stdio.h>

void accion_putchar(int c){ 
    putchar(c);
}

void accion_nula(int c){ // epsilon
    /* No hace nada */ 
}

void accion_espacio(int c){
    putchar(' '); 
}

void accion_doble_putchar(int c){
    putchar('/'); 
    putchar(c); 
}


int main(){
    int c;
    goto OUT;
    // ------------------ ESTADOS -------------------
    //OUT: ESTAS AFUERA DE COMENTARIO MULT O SIMPLE, STRING O CHAR
    OUT:
        c = getchar();
        switch(c) {
            case '/':
                accion_nula(c);
                goto POSIBLE_COMMENT;
            case '\"' :
                accion_putchar(c);
                goto IN_STRING;    
            case '\'':
                accion_putchar(c);
                goto IN_CHAR;
            case EOF :
                break;
            default:
                accion_putchar(c);
                goto OUT;
        }
    //LLEGO UNA BARRA, ME FIJO SI EL SIGUIENTE CARACTER ES OTRA BARRA O UN ASTERISCO
    POSIBLE_COMMENT:
        c = getchar();
        switch(c){
            case '/':
                accion_nula(c);
                goto IN_SIMPLE;
            case '*':
                accion_nula(c);
                goto IN_MULT;
            case EOF :
                break;
            default:
                accion_doble_putchar(c);
                goto OUT;
        }
    //ESTOY DENTRO DE UN COMENTARIO SIMPLE HASTA QUE REGISTRE EL CARACTER NEW LINE
    IN_SIMPLE:
        c = getchar();
        switch(c){
            case '\n':
                accion_putchar(c);
                goto OUT;
            case EOF :
                break; 
            default:
                accion_nula(c);
                goto IN_SIMPLE;
        }
    //ESTOY DENTRO DE UN COMENTARIO MULTIPLE HASTA REGISTRAR * Y /
    IN_MULT :
        c = getchar();
        switch(c){
            case '*':
                accion_nula(c);
                goto POSIBLE_EXITM;
            case EOF :
                break;
            default:
                accion_nula(c);
                goto IN_MULT;
        }
    //SI EL SIGUIENTE CARACTER ES OTRA BARRA, SALI DE MI COMENTARIO MULTIPLE
    POSIBLE_EXITM :
        c = getchar();
        switch(c){
            case '/':
                accion_espacio(c);
                goto OUT;
            case '*':
                accion_nula(c);
                goto POSIBLE_EXITM;
            case EOF :
                break;
            default:
                accion_nula(c);
                goto IN_MULT;
        }
    //DETECTE UNA COMILLA DOBLE ESTOY DENTRO DE UN STRING, VERIFICO TAMBIEN SI VIENE UNA BARRA INVERTIDA PARA VERIFICAR ESCAPES
    IN_STRING:
        c = getchar();
        switch(c){
            case '\\' :
                accion_putchar(c);
                goto ESCAPE_STRING;
            case '\"' :
                accion_putchar(c);
                goto OUT;
            case EOF :
                break;
            default :
                accion_putchar(c);
                goto IN_STRING;
        }
    //DETECTE UNA COMILLA SIMPLE, VERIFICO SI LO QUE HAY ADENTRO ES UN SOLO CARACTER O UN ESCAPE VERIFICANDO SI HAY BARRA INVERTIDA    
    //ESTOY ENTRE LAS DOS COMILLAS SIMPLES, DEBO DETECTAR OTRA COMILLA SIMPLE PARA PODER IRME A OUT
    /*SABEMOS QUE SOLO TENDRIA QUE PODER DETECTAR UN CARACTER Y LISTO, PERO DECIDIMOS
    QUE AL CUMPLIR LA FUNCION DE PREPROCESADOR, NO HACE FALTA QUE DETECTE ERRORES DE SEMANTICA DE TIPOS DE DATOS*/
    IN_CHAR:
        c = getchar();
        switch(c){
            case '\\' :
                accion_putchar(c);
                goto ESCAPE_CHAR;
            case '\'':
                accion_putchar(c);
                goto OUT;
            case EOF :
                break;
            default:
                accion_putchar(c);
                goto IN_CHAR;
        }
    //DETECTE UNA BARRA INVERTIDA DENTRO DE UN CHAR O UN STRING, TENIENDO EN CUENTA
    //DESDE QUE ESTADO LLEGUE A ESTE ESTADO
    ESCAPE_STRING:
        c = getchar();
        switch(c) {
            case 'n':
                accion_putchar(c);
                goto IN_STRING;
            case '\"':
                accion_putchar('\"');
                goto IN_STRING;
            case '\'':
                accion_putchar('\'');
                goto IN_STRING;
            case '\\':
                accion_putchar('\\');
                goto IN_STRING;
            case EOF :
                break;
            default:
                accion_putchar(c);
                goto IN_STRING;
        }
    ESCAPE_CHAR:
        c = getchar();
        switch(c) {
            case 'n':
                accion_putchar('n');
                goto IN_CHAR;
            case '\"':
                accion_putchar('\"');
                goto IN_CHAR;
            case '\'':
                accion_putchar('\'');
                goto IN_CHAR;
            case '\\':
                accion_putchar('\\');
                goto IN_CHAR;
            case EOF :
                break;
                
            default:
                accion_putchar(c);
                goto IN_CHAR;
        }
}
