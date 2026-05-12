# Grupo 03 - K2002 - 2025

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

# Fases de la Traducción y Errores

## Objetivos

Este trabajo tiene como objetivo identificar las fases del proceso de traducción o _build_ y los posibles errores asociados a cada fase.

Para lograr esa identificación se ejecutan las fases de traducción una a una, se detectan y corrigen errores, y se registran las conclusiones en este archivo `README.md`.

> No es un trabajo de desarrollo; el programa que se utiliza como ejemplo es simple (similar a `hello.c`), pero con errores que deben corregirse.  
> La complejidad está en la identificación y comprensión de las etapas y sus productos.

## Temas

- Fases de traducción
- Preprocesamiento
- Compilación
- Ensamblado
- Vinculación (Link)
- Errores en cada fase
- Compilación separada

## Hipótesis

Dado un archivo fuente en C con errores intencionales, si se ejecutan las fases del proceso de traducción por separado (preprocesamiento, compilación, ensamblado y vinculación), es posible identificar con mayor claridad en qué fase ocurre cada error. Esto permite comprender más profundamente cómo funciona el compilador, qué productos genera en cada etapa y qué rol cumplen los contratos en la compilación por módulos.

# Respuestas

1. **Preprocesamiento**  
   (-E) - Compilación a ensamblador (-S) - Compilación a objeto (-c) - Enlazado (implícito)

2. **Terminal:**
   - `gcc -E hello2.c -o hello2.i`
   - `gcc -E hello3.c -o hello3.i`
   - `gcc -S hello3.i -o hello3.s`
     ```
     hello3.c: In function 'main':
     hello3.c:6:5: error: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
     6 |     prontf("La respuesta es %d\n");
        |     ^~~~~~
        |     printf
     hello3.c:6:5: error: expected declaration or statement at end of input
     ```
   - `gcc -E hello4.c -o hello4.i`
   - `gcc -S hello4.i -o hello4.s`
   - `gcc -c hello4.s -o hello4.o`
   - `gcc hello4.o -o hello4`
   - `gcc hello5.c -o hello5`
   - `./hello5`
     ```
     La respuesta es -218671840 ->>> esta imprimiendo un numero pero no de una variable
     ```
   - `gcc hello6.c -o hello6`
   - `./hello6`
     ```
     La respuesta es 42
     ```
   - `gcc hello7.c -o hello7`
     ```
     hello7.c: In function 'main':
     hello7.c:4:5: error: implicit declaration of function 'printf' [-Wimplicit-function-declaration]     
     4 |     printf("La respuesta es %d\n", i);
        |     ^~~~~~
     hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
     +++ |+#include <stdio.h>
     1 | int main(void)
     hello7.c:4:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
     4 |     printf("La respuesta es %d\n", i);
        |     ^~~~~~
     hello7.c:4:5: note: include '<stdio.h>' or provide a declaration of 'printf'
     ```
   - `gcc -c studio1.c -o studio1.o`
     >> `gcc -c hello8.c -o hello8.o`
     ```
     studio1.c: In function 'prontf':
     studio1.c:3:5: error: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
     3 |     printf("La respuesta es %d\n", i);
        |     ^~~~~~
     studio1.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
     +++ |+#include <stdio.h>
     1 | void prontf(const char* s, int i)
     studio1.c:3:5: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
     3 |     printf("La respuesta es %d\n", i);
        |     ^~~~~~
     hello8.c: In function 'main':
     hello8.c:4:5: error: implicit declaration of function 'prontf' [-Wimplicit-function-declaration]
     4 |     prontf("La respuesta es %d\n", i);
        |     ^~~~~~
     ```

### Respuestas:

 **1.b:** 
    El preprocesador realiza las siguientes acciones:

  - Elimina comentarios (como `/*medio*/`) y no corrige errores tipográficos (como en `prontf`).
  - El archivo `hello2.i` muestra el código sin cambios en la lógica, solo con las siguientes modificaciones:

    - **0 "hello2.c"**: Indica que se está procesando el archivo fuente `hello2.c`.
    
    - **0 "<built-in>"**: Se están procesando las definiciones (`#include`) y macros (`#define`) incorporadas al compilador.
    
    - **0 "<command-line>"**: Se procesa cualquier macro definida explícitamente mediante la línea de comandos.
    
    - **1 "hello2.c"**: Se vuelve a procesar el archivo fuente original, el `1` indica que está en su primera línea luego de manejar las instrucciones anteriores.

   El error tipográfico en `prontf` será detectado en la fase de compilación, no en el preprocesador.

 **1.d:**  
   Es una declaración de la función `printf`. Retorna un `int`. Recibe al menos un parámetro, que este del tipo puntero apuntando a un `const char`, e indica con la palabra clave `restrict` (C99) que es el unico puntero en acceder a los datos apuntados.

 **1.e:**  
   El preprocesador solo agregó directivas o "macros", es decir, el código se mantiene casi igual, incluyendo el error en prontf y sin incluir la biblioteca estándar (#include <stdio.h>).

 **2.c:**  
El objetivo del código es imprimir "La respuesta es 42" en la consola utilizando `printf`, con el valor 42 pasado como argumento con el especificador `%d`.

 **5.b.i:**  
Arroja errores y advertencias: se necesita el `#include <stdio.h>` para poder usar `printf`.

 **5.b.ii:**  
Un prototipo es cuando declaras una función antes de utilizarla y especificas el nombre, lo que retorna y los tipos de parámetros. Se pueden generar antes del `main` o en algún archivo `.h` y este mismo incluirlo en el archivo fuente.

 **5.b.iii:**  
Una declaración implícita se le dice a una función sin declaración previa.

 **5.b.iv:**  
Depende del estándar, en algunos está prohibida (C99 en adelante) mientras que en otros está permitida pero podría causar errores.

 **5.b.v:**  
Las implementaciones modernas advierten o señalan un error al olvidar o no declarar un prototipo de función.

 **5.b.vi:**  
Una función `built-in` es una función especial reconocida por el compilador y que puede ser reemplazada por una instrucción más eficiente.

 **5.b.vii:**  
GCC se comporta así por compatibilidad con código antiguo (C89 o C90). Cumple con la especificación moderna cuando se le pide explícitamente, sino asume el comportamiento tradicional.

 **6.b:**  
Se puede compilar ambos archivos fuente para generar los archivos objeto, estos mismos vincularlos para crear el ejecutable y por último ejecutar el programa generado.

 **6.c:**  
Cambiar la cantidad de argumentos en `prontf` puede generar errores, ya que espera cierta cantidad específica de parámetros.

 **6.d.iv:**  
Incluir un archivo `.h` como contrato permite que el compilador verifique que la función se utilice correctamente, evita errores y hace el código más claro y fácil de mantener.


### Extra:
- Una biblioteca es una recopilación de archivos header y archivos que detallan rutinas. Los archivos header contienen los prototipos de funciones desarrolladas en otros archivos .c y la implementación de esas funciones esta contenida dentro de archivos que pertenecen a la biblioteca. El propósito general de las librerias es el de facilitar al programador herramientas para el desarrollo de software.
- Las librerias son distribuidas públicamente y son portables en tanto se utilicen dentro del mismo lenguaje de programación y no haya limitaciones que competan a los recursos del sistema operativo.

**Ventajas:**
+ Reutilización de código
+ Modularidad
+ Reduce el tamaño del código fuente

**Desventajas:**
+ Problemas de compatibilidad
+ Dependencias externas
+ Posibles errores por versiones o sistema operativo
