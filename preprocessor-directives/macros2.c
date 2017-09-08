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
#include <stdlib.h>

#define MMAX(x, y) (x > y ? x : y)
#define entero int
#define igual =
#define uno 1
#define MOSTRAR(X) printf("%d\n", X)
#define CREAR(tipo, nombre, valor) tipo nombre = valor;

#define CREAR_LISTA(tipo, nombre_tipo) \
typedef struct \
{ \
    tipo* data; \
    size_t n; \
} nombre_tipo; \
void init(nombre_tipo* p) \
{ \
    p->data = malloc(0); \
    p->n = 0; \
} \
void add(nombre_tipo* p, tipo n) \
{ \
    p->data = realloc(p->data, (p->n+1)*sizeof(tipo)); \
    p->data[p->n++] = n; \
}

CREAR_LISTA(entero, lista_enteros)

int main()
{
    lista_enteros p;
    init(&p);
    add(&p, 12);
    add(&p, 15);

    for (int i = 0; i < p.n; i++)
    {
        printf("%d\n", p.data[i]);
    }

    printf("%d\n", __LINE__);
    MOSTRAR(__LINE__);
    puts("the file is: " __FILE__);
}