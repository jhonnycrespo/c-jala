#include <stdio.h>

void changeValue(const char** s)
{
    printf("s: %p\n", s);
    printf("*s: %p\n", *s);
    printf("**s: %c\n", **s);

    *s = "mundo";
}

// Esto no funciona
// void changeValue2(const char* s)
// {
    // no funciona
    // *s = "mundo";
// }

int main()
{
    int x = 25;
    printf("&x: %p\n", &x);

    int* a = &x;

    printf("a: %p\n", a);
    printf("*a: %d\n", *a);

    int** b = &a;
    printf("b: %p\n", b);
    printf("*b: %p\n", *b);
    printf("**b: %d\n", *(*b));

    int*** c = &b;
    printf("c: %p\n", c);
    printf("*c: %p\n", *c);
    printf("**c: %p\n", **c);
    printf("***c: %d\n", ***c);

    // Esto no se puede hacer
    // int* d = 25;

    // Pero esto si
    const char* e = "hola";
    puts(e);
    printf("e: %p\n", e);
    // Solo imprime h. porque? Porque "hola" es en realidad
    // un arreglo, y un arreglo apunta al primer elemento.
    printf("*e: %c\n", *e);
    printf("&e: %p\n", (void*) &e);

    changeValue(&e);

    puts(e);

    e = "hey hey";

    puts(e);
}