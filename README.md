# Datos a estudiar

<stdio.h>   // printf

<unistd.h>  // write, read

<stdlib.h>  // malloc, free, exit

<limits.h>  // INT_MAX, INT_MIN

---

complex_moves.c (Algoritmo principal)

complex_moves_prep.c (Cálculo de costes)

complex_moves_do.c (Ejecución optimizada)

checker.c (Bonus)

---

##### La flecha -> 

Este símbolo es el "operador flecha" y es la llave maestra para trabajar con tus nodos y punteros.

¿Qué significa? Significa:

"Ve a la dirección de memoria a la que apunta este puntero y dame el dato que hay dentro llamado X".

¿Por qué la usas? 

Como tu variable stack es un puntero (t_stack *), no tienes el vagón físico, tienes la "dirección" de dónde está aparcado.

Si tuvieras el objeto directo usarías un punto: objeto.dato.

Como tienes un puntero (una dirección), usas la flecha: puntero->dato.
