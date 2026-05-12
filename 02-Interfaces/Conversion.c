#include "Conversion.h"

double Celsius(double fahr){
    return (fahr - 32) * 5.0 / 9.0;
}

double Fahrenheit(double cels){
    return (cels * 9.0 / 5.0) + 32.0;
}


// FUNCIONES CREDITO EXTRA

void PrintTablas(int lower, int upper, int step){    
    printf("FAHR A CELS:\n");
    PrintTablaCelsius(lower, upper, step);

    printf("CELS A FAHR:\n");
    PrintTablaFahrenheit(lower, upper, step);
}

void PrintTablaCelsius(int lower, int upper, int step){
    PrintFilas(Celsius, lower, upper, step);
}

void PrintTablaFahrenheit(int lower, int upper, int step){
    PrintFilas(Fahrenheit, lower, upper, step);
}

void PrintFilas(double (*func)(double), int lower, int upper, int step){
    for(double fahrCel = lower; fahrCel <= upper; fahrCel += step)
        Printfila(fahrCel, func(fahrCel));
}

void Printfila(double input, double output){
    printf("%3.0f\t %6.1f\n", input, output);
}
