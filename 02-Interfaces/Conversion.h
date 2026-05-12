#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>


double Celsius(double fahr);
double Fahrenheit(double cels);

bool AreNear (double, double); //funcion que compara si dos numeros estan suficientemente cerca, de forma proporcional

// FUNCIONES CREDITO EXTRA
void PrintTablas(int lower, int upper, int step);
void PrintTablaCelsius(int lower, int upper, int step);
void PrintTablaFahrenheit(int lower, int upper, int step);
void PrintFilas(double (*func)(double), int lower, int upper, int step);
void Printfila(int input, int output);

#endif
