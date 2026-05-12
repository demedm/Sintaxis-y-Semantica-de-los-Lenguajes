#include "Conversion.h"


bool AreNear(double a, double b) {
    double absTol = 1e-9, relTol = 1e-6;
    return fabs(a - b) <= fmax(absTol, relTol * fmax(fabs(a), fabs(b)));
}

int main(){
    
    double CelsiusT[5] = {0.0, 100.0, 37.0, 20.0, -10.0};
    double FahrenheitT[5] = {32.0, 212.0, 98.6, 68.0, 14.0};

    for(int i=0; i<5; i++){
        assert(AreNear(Fahrenheit(CelsiusT[i]),FahrenheitT[i]));
        assert(AreNear(Celsius(FahrenheitT[i]),CelsiusT[i]));
    }
}

//se testea con particiones de ambos conjuntos si los valores de las imagenes, son casi iguales a los esperados
