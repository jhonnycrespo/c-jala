/**
 * Macros
 * 
 * Son pedacitos de codigo al que se le da un nombre. Donde sea que se use ese nombre, es reemplazado
 * por el contenido del macro.
 *
 * Con los compiladores actuales ya no es neceario usar macros, los compiladores optimizan el codigo lo
 * mas posible.
 */

#include <stdio.h>

#define MMAX(x, y) (x > y ? x : y)
#define entero int
#define igual =
#define uno 1
#define MOSTRAR(X) printf("%d\n", X)
#define CREAR(tipo, nombre, valor) tipo nombre = valor;

int main()
{
    int p = MMAX(6, 9);
    printf("%d\n", p);

    entero num igual uno;
    MOSTRAR(uno);

    CREAR(int, pedro, 25);
    MOSTRAR(pedro);
}