#ifndef DEL_H
#define DEL_H

#include "scanner.h"
#include <string.h>

extern Token token;
extern Token sentencia[10];
extern int cont_sentencia;
extern char out[1000];
extern char nombre[100];
extern char tipo [100];
void dcl();
void dir_dcl();
void rutinaErrorSintactico(char);
#endif