_This project has been created as part of the 42 curriculum by <jpedra-v>_

__Description__

El programa push_swap calcula la secuencia mas corta posible de instrucciones necesarias para
para ordenar una pila de numeros.


__Instructions__

# Compilar base
make re

# Compilar bonus

make bonus

# Prueba OK
./push_swap 4 1 3 2 | ./checker 4 1 3 2

-> ./push_swap 4 1 3 2
        1. Calcula como ordenar la pila [4, 1, 3, 2].
        2. Imprime una lista de instrucciones en la terminal.
 
->  |
        3. Coge esa salida de texto y en lugar de mostrarla en pantalla se la manda al checker.
  
-> ./checker 4 1 3 2
        4. El checker arranca con la misma pila [4, 1, 3, 2].
        5. Usa get_next_line para leer las instrucciones que le llegan por | .
        6. Al final comprueba si esta ordenada la pila A y vacia la B.

# Prueba KO
echo "sa" | ./checker 1 2 3

-> echo "sa"
        1. Envía el texto "sa\n" por la tubería.
 
-> ./checker 1 2 3
        2. El checker arranca con la pila [1, 2, 3] (ya ordenada).
        3. Usa get_next_line para leer las instrucciones que le llegan por | (osea "sa").
        4. Ejecuta el movimiento, quedando [2, 1, 3].
        5. Comprueba is_sorted. Como 2 > 1, la pila NO está ordenada.
    
# Prueba de error
echo "movimiento_falso" | ./checker 1 2 3

-> echo "movimiento_falso"
        1. Envía el texto "movimiento_falso" por la tubería.
 
-> ./checker 1 2 3
        2. El checker compara el string con "sa", "pb",...
        3. Como NO coincide con ninguno entra en el else final.

__Resources__

- Github para referencias
- Gemini para que me explicase la funcion de -> y |
