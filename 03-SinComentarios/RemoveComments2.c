// remove_comments.c
#include <stdio.h>



// -------------------- ENUMS ----------------------
typedef enum {
    OUT,
    POSIBLE_COMMENT,
    IN_SIMPLE,
    IN_MULT,
    POSIBLE_EXITM,
    IN_CHAR,
    IN_STRING,
    ESCAPE_STRING,
    ESCAPE_CHAR
} Estado;

typedef enum {
    B, As, S, C, O, N, E, Nl
} Entrada;

#define NUM_ESTADOS ESCAPE_CHAR + 1
#define NUM_ENTRADAS Nl + 1

// ------------------ CLASIFICADOR -------------------
Entrada clasificar(int c) {
    switch (c) {
        case '/': return B;
        case '*': return As;
        case '"': return S;
        case '\'': return C;
        case 'n': return N;
        case '\n': return Nl;
        case '\\' : return E;
        default: return O;
    }
}

// ------------------ FUNCIONES DE ACCION -------------------
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

// ------------------ MATRICES --------------------
Estado transicion[NUM_ESTADOS][NUM_ENTRADAS] = {{POSIBLE_COMMENT, OUT, IN_STRING, IN_CHAR, OUT, OUT, OUT, OUT},
                                                {IN_SIMPLE, IN_MULT, OUT, OUT, OUT, OUT, OUT, OUT},
                                                {IN_SIMPLE, IN_SIMPLE, IN_SIMPLE,IN_SIMPLE,IN_SIMPLE,IN_SIMPLE,IN_SIMPLE, OUT},
                                                {IN_MULT, POSIBLE_EXITM, IN_MULT, IN_MULT, IN_MULT, IN_MULT, IN_MULT, IN_MULT},
                                                {OUT, POSIBLE_EXITM, IN_MULT, IN_MULT, IN_MULT, IN_MULT, IN_MULT, IN_MULT},
                                                {IN_CHAR,IN_CHAR,IN_CHAR,OUT,IN_CHAR,IN_CHAR,ESCAPE_CHAR,IN_CHAR},
                                                {IN_STRING, IN_STRING, OUT, IN_STRING, IN_STRING, IN_STRING, ESCAPE_STRING, IN_STRING},
                                                {IN_STRING, IN_STRING, IN_STRING, IN_STRING, IN_STRING, IN_STRING, IN_STRING, IN_STRING},
                                                {IN_CHAR,IN_CHAR,IN_CHAR,IN_CHAR,IN_CHAR,IN_CHAR,IN_CHAR,IN_CHAR}};

void (*accion[NUM_ESTADOS][NUM_ENTRADAS])(int)={{accion_nula, accion_putchar, accion_putchar, accion_putchar,accion_putchar, accion_putchar, accion_putchar, accion_putchar},
                                                {accion_nula,accion_nula, accion_doble_putchar, accion_doble_putchar, accion_doble_putchar,accion_doble_putchar,accion_doble_putchar,accion_doble_putchar},
                                                {accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula, accion_putchar},
                                                {accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula},
                                                {accion_espacio, accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula,accion_nula},
                                                {accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar},
                                                {accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar},
                                                {accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar},
                                                {accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar,accion_putchar}} ;


// ------------------ MAIN -------------------
int main() {
    //inicializar_tablas();
    int c;
    for(Estado estado = OUT; (c = getchar()) != EOF;){
        Entrada e = clasificar(c);
        accion[estado][e](c);
        estado = transicion[estado][e];
    }
}
