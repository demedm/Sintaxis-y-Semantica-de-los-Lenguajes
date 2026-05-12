<div align="center">

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&width=500&lines=Grupo+03+-+K2002;TP+4+-+Scanner+Léxico;TP+4+-+Parser">

***


</div>
<div align="center">
<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=500&lines=Miembros+del+grupo">

<div align="center">
<table>
  <tr align="center">
    <td><b>Usuario</b></td>
    <td><b>Legajo</b></td>
    <td><b>Nombre Completo</b></td>
  </tr>
  <tr align="center">
    <td><b>FedeIann</b></td>
    <td>213.797-5</td>
    <td>Federico Iannino</td>
  </tr>
  <tr align="center">
    <td><b>AgustinaDuran</b></td>
    <td>222.281-4</td>
    <td>Agustina Duran</td>
  </tr>
  <tr align="center">
    <td><b>DanteMedici</b></td>
    <td>213.878-5</td>
    <td>Dante Medici</td>
  </tr>
  <tr align="center">
    <td><b>lovngkndl1</b></td>
    <td>209.531-2</td>
    <td>Ezequiel Carrizo Rizzuto</td>
  </tr>
  <tr align="center">
    <td><b>demedm</b></td>
    <td>213.881-5</td>
    <td>Denise A Medina Mosquera</td>
  </tr>
</table>


***

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&duration=5000&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=Objetivos"/>

<div align="justify"> El objetivo principal es desarrollar un sistema de traducción de declaraciones complejas de C a lenguaje natural, dividido en dos etapas fundamentales:

1. **Etapa Léxica (Scanner):** Transformar el flujo de caracteres de un archivo fuente (.c) en una secuencia de tokens.
2. **Etapa Sintáctica (Parser):** Implementar un analizador descendente recursivo que consuma dichos tokens, interprete la estructura gramatical de la declaración y genere la traducción final en español.
</div>

<br>
<br>
<br>

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&duration=5000&pause=700&color=FFD700&center=true&vCenter=true&repeat=false&width=1000&lines=⚠️Limitaciones⚠️"/>

Solamente acepta el conjunto desarrollado en la especificación. Se definio un estado de rechazo tanto en el automata como en la implementacion, pero no se da una definicion formal de que sería un error lexico o como se forma su expresion regular, ya que no es aceptada por nuestro lenguaje regular en el primer lugar.
Además, el Scanner opera con buffers de tamaño fijo, limitando la longitud máxima de cualquier lexema (identificador o literal numérico) a 127 caracteres.

***

</div>

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=Especificaci%C3%B3n">

Definimos los siguientes conjuntos que formaran parte de nuestro alfabeto

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int = {0,...,9}`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`char = {a,...,z,A,...,Z,_}`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`esp = { }`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`op (operador) = { * , ( , ), [ , ]}`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`punct = { ; }`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`inval : son aquellos caracteres no reconocidos por el analizador lexico (ej : @)`

<br>

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=Expresiones+Regulares">

A partir del automata y el alfabeto definido, definimos las siguientes expresiones regulares:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ID:  char (char | int)*`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`Lit_Num:  int (int)*`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`BRACKETS:  [ (int*) ]`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`PARS:  ( )`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`LPAR:  (`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`RPAR:  )`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ASTERISK:  *`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`PUNCT:  ;`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ERROR_LEX: errores léxicos encontrados`

<br>

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=Lenguaje+Natural">

- ID : es un caracter del abecedario o guion bajo, seguido por cualquier secuencia de caracteres del abecedario, guiones bajos o digitos
- Lit_Num : es un Digito seguido por cualquier secuencia de digitos
- BRACKETS : es un corchete de apertura seguido por cualquier secuencia de digitos, seguido por un corchete de cierre
- PARS : es un parentesis izquierdo seguido por un parentesis derecho
- LPAR : es el caracter de parentesis izquierdo
- RPAR : es el caracter de parentesis derecho
- ASTERISK : es el caracter de asterisco
- Punct : es el caracter de punto y coma
- ERROR_LEX : simboliza errores lexicos encontrados por el scanner

<img src = "https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=TT+%3A+Tabla+de+Transiciones+de+Estados">

<img width="1254" height="284" alt="image" src="https://github.com/user-attachments/assets/8a16d5e2-8b08-45e3-9244-827a71d0b632" />

ACLARACION : A pesar de haber definido el conjunto op para englobar todos los operadores, se decidio representar cada operador de forma individual en la tabla para casos especificos a un solo operador

<br>

<img src="https://readme-typing-svg.herokuapp.com?font=Science+Gothic&weight=600&size=30&pause=700&color=22B455&center=true&vCenter=true&repeat=false&width=1000&lines=BNF+(Parser)">
Basandonos en la teoria desarrollada en el capitulo 5.12 del libro "El lenguaje de programacion C" por por Kernigan y Ritchie, la cual introduce el metodo de descripcion verbal dcl, el cual nos permite convertir declaraciones hechas en C en descripciones hechas con lenguaje natural. A continuacion las definiciones de los conceptos claves para el manejo de declaraciones, las cuales nos permiten descomponerlas mediante el armado de un arbol sintactico para asi facilitar la representación en lenguaje natural

UT (Unidad de Traducción):        
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```declaracion```  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```UT declaracion```

declaracion:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```tipo-de-dato dcl ;```
   
dcl:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```_*s optativos_ dir-dcl```

dir-dcl:   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```nombre```  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```(dcl)```  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```dir-dcl( )```  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;```dir-dcl[_tamaño optativo_]```




