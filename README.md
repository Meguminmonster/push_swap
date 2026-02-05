# Datos a estudiar

<stdio.h>   // printf

<unistd.h>  // write, read

<stdlib.h>  // malloc, free, exit

<limits.h>  // INT_MAX, INT_MIN

---

### Aquí es donde defines la "forma" que tendrán los vagones de tu tren (tu lista enlazada).

    typedef struct s_stack

    {

    int             n;
    
    // ... otros datos ...
 
    struct s_stack  *next;
    
    }     t_stack;

A. La struct s_stack

Es la definición pura de tu estructura de datos. Le estás diciendo a C: "Oye, voy a crear un tipo de dato compuesto que tiene un entero, unos índices y un puntero al siguiente elemento".

n: El número real que tienes que ordenar.

main_index, position, target_pos...: Son datos extra que añades a cada nodo para facilitarte la vida al calcular el algoritmo (costes, posiciones objetivo, etc.).

struct s_stack *next: El puntero que une este nodo con el siguiente. Es lo que hace que sea una "lista" y no una variable suelta.

B. El typedef (Type Definition)

Si no usaras typedef, cada vez que quisieras declarar una variable de este tipo tendrías que escribir todo el nombre y apellidos: struct s_stack *mi_pila

Al envolverlo con typedef ... t_stack;, estás creando un alias o apodo. Le dices al compilador: "A partir de ahora, t_stack es lo mismo que struct s_stack". Así, en tu código puedes escribir simplemente: t_stack *sa;

### Qué es un Nodo? (t_stack)

El nodo es la caja individual donde guardas la información. En tu código, cada vez que haces un new_node, estás creando un vagón nuevo.

Si miras tu archivo push_swap.h, verás esto:

    typedef struct s_stack
    {
    int             n;              // <--- La CARGA del vagón (el número a ordenar)
    int             main_index;     // <--- Etiquetas extra (tu ranking)
    // ... más datos ...
    struct s_stack  *next;          // <--- El GANCHO que lo une al siguiente vagón
    }                   t_stack;

Tu Nodo (t_stack) tiene dos partes principales:

Datos: n, main_index, position, etc. (Lo que llevas dentro).

El enlace: *next.

---

complex_moves.c (Algoritmo principal)

complex_moves_prep.c (Cálculo de costes)

complex_moves_do.c (Ejecución optimizada)

checker.c (Bonus)

---

### La flecha -> 

Este símbolo es el "operador flecha" y es la llave maestra para trabajar con tus nodos y punteros.

¿Qué significa? Significa:

"Ve a la dirección de memoria a la que apunta este puntero y dame el dato que hay dentro llamado X".

¿Por qué la usas? 

Como tu variable stack es un puntero (t_stack *), no tienes el vagón físico, tienes la "dirección" de dónde está aparcado.

Si tuvieras el objeto directo usarías un punto: objeto.dato.

Como tienes un puntero (una dirección), usas la flecha: puntero->dato.

### La tuberia |

Este símbolo es el "Pipe" (tubería). Se usa cuando ejecutas comandos en la terminal.

Significa: "Coge todo lo que el programa de la izquierda escupe (output) e inyéctaselo al programa de la derecha como si lo escribieras tú (input)".

¿Por qué la usamos en Push Swap? push_swap calcula los movimientos y los imprime (pa, ra, sa...) en la pantalla. Tu checker necesita leer esos movimientos para comprobarlos. En lugar de copiar y pegar a mano, usas el tubo.

