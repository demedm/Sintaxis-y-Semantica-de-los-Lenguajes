# Grupo 03 - K2002
# TP2 - Interfaces & Makefile — Temperaturas
## Autores de la resolucion:
- **Usuario:** FedeIann  
  **Legajo:** 213.797-5  
  **Nombre Completo:** Federico Iannino

- **Usuario:** AgustinaDuran  
  **Legajo:** 222.281-4  
  **Nombre Completo:** Agustina Duran

- **Usuario:** DanteMedici  
  **Legajo:** 213.878-5  
  **Nombre Completo:** Dante Medici

- **Usuario:** lovngkndl1  
  **Legajo:** 209.531-2  
  **Nombre Completo:** Ezequiel Carrizo Rizzuto

- **Usuario:** demedm  
  **Legajo:** 213.881-5  
  **Nombre Completo:** Denise A Medina Mosquera

## **Objetivos**
- Aplicar el uso de interfaces y módulos.
- Construir un programa formado por más de una unidad de traducción.
- Comprender el proceso de traducción o build cuando intervienen varios archivos fuente.
- Aplicar el uso de Makefile.

## **Temas**
- Makefile.
- Archivos header (`.h`).
- Funciones.
- Pruebas unitarias.
- `assert`.
- Interfaces e Implementación.
- Tipo de dato `double`.

**Nota:**  
La comparación de tipos flotantes, como `double`, no es trivial ni directa debido a su representación y precisión.  
Se debe incorporar la comparación con tolerancia mediante una función `bool` que reciba dos flotantes a comparar y un flotante que represente la tolerancia. La función debe retornar `true` si los flotantes están cerca según la tolerancia. Se propone la función `AreNear`

## **Problema**
Se necesita una tabla que presente las temperaturas Celsius convertidas a Fahrenheit y otra en el sentido opuesto.

## **Solución**
Desarrollar un programa que imprima dos tablas de conversión:  
- Una de Fahrenheit a Celsius.  
- Otra de Celsius a Fahrenheit.

## **Tareas**
1. Escribir el `Makefile`.
2. Escribir `Conversion.h`.
3. Escribir `ConversionTest.c`.
4. Escribir `Conversion.c`.
5. Escribir `TablasDeConversion.c`.

## **Restricciones**
- Las dos funciones públicas deben llamarse `Celsius` y `Fahrenheit`.
- Utilizar `assert`.
- Utilizar `const` o `constexpr`, y no `#define`.
- Utilizar `for` con declaración (C99).

## **Estructura del Proyecto**
- readme.md
- Makefile
- Conversion.h
- ConversionTest.c
- Conversion.c
- TablasDeConversion.c

## **Crédito Extra**

1. **Funciones adicionales en `TablasDeConversion.c`:**  
   Desarrolle funciones como:
   - `PrintTablas`
   - `PrintTablaCelsius`
   - `PrintTablaFahrenheit`
   - `PrintFilas`
   - `PrintFila`

   Los límites inferior y superior, y el incremento deben ser parámetros.

2. **Generalización de la función `PrintFilas`:**  
   Haga que `PrintFilas` sea genérica, es decir, que pueda invocarse tanto desde `PrintTablaFahrenheit` como desde `PrintTablaCelsius`.  
   La función `PrintFilas` debe invocar a `PrintFila`. Considere el uso de punteros a función para implementar esta generalización.

## **Hipótesis de trabajo**
Organizar el código en tres archivos separados, con sus respectivos archivos `.h`, y agregar pruebas que verifiquen su funcionamiento, permite que el programa esté bien estructurado y sea más fácil de entender y comprobar que funciona correctamente. Además, asumimos que la fase de traducción se puede hacer directamente en el Makefile, pero a fines de mostrar el procedimiento paso a paso, elegimos esta forma.

