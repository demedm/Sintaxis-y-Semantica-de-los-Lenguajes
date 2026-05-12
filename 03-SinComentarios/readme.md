# Grupo 03 - K2002
# TP3 -  Máquinas de Estado — Sin Comentarios
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

## **Objetivo**
 El objetivo es diseñar una máquina de estado que remueva comentarios,
 implementar dos versiones, e informar cual es la más eficiente mediante un
 benchmark.

 ## **Restricciones**
- Primero diseñar y especificar la máquina de estado y luego derivar dos
 implementaciones.
- Utilizar el lenguaje dot para dibujar los digrafos.
- Incluir comentarios de una sola línea (//).
- Considerar las variantes no comunes de literales carácter y de literales
 cadenas que son parte del estándar de C.
- Diseñar el programa para que pueda invocarse de la siguiente manera:
 RemoveComments < Test.c > NoComments.c
- Ninguna de las implementaciones debe ser la Implementación #1: estado
 como variable y transiciones con selección estructurada.
- Indicar para la implementación cómo se representan los estados y cómo las
 transiciones.
- Respetar la máquina de estado especificada, en cada implementación utilizar
 los mismos nombres de estado y cantidad de transiciones.
- En el caso que sea necesario, utilizar enum, y no define.
- Diseñar el archivo Makefile para que construya una, otra o ambas
 implementaciones, y para que ejecute las pruebas. 

 ## **Resolución**
Para la creación del automata, creamos la siguiente 6 - upla :
- (Σ)input = ASCII
Este alfabeto de input esta dividido en los siguientes subconjuntos :
- B = { / }  
- As = { * } 
- S = { " }
- C = { ' }
- N = { n }
- Nl = { \n }
- E = { \ } 
- O = ASCII - { B, As, S, C, N, E }
 
- (Σ)output = {accion_putchar, accion_doble_putchar, accion_espacio}
- Q = { Out, Posible_Coment, In_Simple, In_Mult, Posible_ExitM, In_Char, In_String, Escape_String, Escape_Char}
- q0 = Out
- F = Q (cualquiera de los estados definidos es un posible estado de Aceptación, ya que podria haber EOF en cualquier punto)

## TT : Tabla de Transiciones de Estados Completada


<img width="1355" height="229" alt="AUTOMATA_ULTIMATE_DEFINITIVO" src="https://github.com/user-attachments/assets/cc6e3b50-871f-458c-b076-1d6d3c83bc89" />


- Completamos las transiciones indefinidas de forma que, incluso si esta mal que dentro de un tipo de dato char haya mas de un caracter, o de no poner un caracter valido para escapar el significado de un caracter con barra invertida, llegamos a la conclusion que al estar simulando el funcionamiento de la fase de preprocesamiento, no hace falta tener en cuenta errores sintacticos o semanticos.

## Tabla de Acciones

<img width="1492" height="263" alt="ACCIONES" src="https://github.com/user-attachments/assets/f734753e-ad55-415d-85c3-8bde174daa47" />


## IMPLEMENTACIONES 

### FUNCION GO TO Y ETIQUETAS 
- Cada estado es representado como una etiqueta que se encuentra en main, y a partir del caracter obtenido con la funcion getchar, utilizamos la funcion goto para dirgirnos a la etiqueta correspondiente junto con las acciones correspondientes, a partir de la cual se realizara otro getchar y otro goto segun el caracter obtenido. Agregamos tambien para cada etiqueta un caso EOF en el caso de que el archivo termine
### MATRIZ DE ESTADOS Y ACCIONES
- A partir de la tabla de transiciones de Estados Completa, cuyas celdas contienen un tipo de dato denominado Estado que definimos con enum; y la tabla de Acciones asociada, que es una matriz cuyas celdas contienen un puntero a funcion, llamamos iterativamente a la funcion getchar mientras el caracter obtenido no sea EOF, Se compara, y a partir de la entrada recibida y el estado actual, realizamos la transicion y accion correspondiente

## Benchmark
- Para poder cronometrar el funcionamiento de los ejecutables, recurrimos a un comando de bash que se convoca de la siguiente manera:

```bash
/usr/bin/time -v ./RemoveComments1 < Test.c > NoComments.c
/usr/bin/time -v ./RemoveComments2 < Test.c > NoComments.c
```

Utilizamos esta funcion para cronometrar las dos implementaciones un total de diez veces cada una y promediamos los resultados.

```bash
- Promedios
1. **RemoveComments1** → Implementación basada en `goto`.
User time (seconds): 0.026
System time (seconds): 0.00
Percent of CPU this job got: 73.9%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.039
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 1411.6
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 68
Voluntary context switches: 1
Involuntary context switches: 205
Swaps: 0
File system inputs: 0
File system outputs: 1488
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0

2. **RemoveComments2** → Implementación basada en `Matrices`.
User time (seconds): 0.043
System time (seconds): 0.00
Percent of CPU this job got: 80.7%
Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.06
Average shared text size (kbytes): 0
Average unshared data size (kbytes): 0
Average stack size (kbytes): 0
Average total size (kbytes): 0
Maximum resident set size (kbytes): 1373.6
Average resident set size (kbytes): 0
Major (requiring I/O) page faults: 67
Voluntary context switches: 1
Involuntary context switches: 214
Swaps: 0
File system inputs: 0
File system outputs: 1488
Socket messages sent: 0
Socket messages received: 0
Signals delivered: 0
Page size (bytes): 4096
Exit status: 0
```

## Conclusión

En promedio, la implementación con **`goto`** (`RemoveComments1`) procesó el archivo de prueba más rápido que la basada en **matrices** (`RemoveComments2`):

| Métrica                          | RemoveComments1 (`goto`) | RemoveComments2 (matrices) | Diferencia                        |
| -------------------------------- | ------------------------ | -------------------------- | --------------------------------- |
| **User time (s)**                | 0.026                    | 0.043                      | `goto` es \~1.65× más rápido      |
| **Elapsed (s)**                  | 0.039                    | 0.060                      | `goto` \~1.54× más rápido         |
| **% CPU**                        | 73.9%                    | 80.7%                      | Ligeramente mayor en matrices     |
| **Max RSS (KB)**                 | 1411.6                   | 1373.6                     | Prácticamente igual               |
| **Involuntary context switches** | 205                      | 214                        | `goto` reduce cambios de contexto |

### Interpretación

* **Rendimiento puro:** gana `goto` en CPU user y tiempo total.
* **%CPU mayor ≠ más veloz:** matrices usa más CPU relativa, pero tarda más.
* **Memoria e I/O:** diferencias mínimas; irrelevantes.

**Conclusión final:**
Si se prioriza el **desempeño**, `goto` es mejor. En cambio, en cuanto a **claridad y mantenibilidad**, la versión con **matrices** es más preferible, dado a que es un fiel reflejo de las tablas realizadas.


