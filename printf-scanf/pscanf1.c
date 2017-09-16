#include <stdio.h>

int main()
{
    printf("%d\n", 12);
    int e = 15;

    const char* s = "Juan";

    // %s recibe char*
    // %d es para decimales (int)
    // %x es para hexadecimales (int) -> cafe
    // %X es para hexadecimales (int) -> CAFE
    // %l es para long
    // %ll es para long long
    // %lu es para unsigned long
    // %ld es para unsigned int
    // %s es para char*, char[]
    // %f es para float
    // %g es para float
    // %p es para punteros
    printf("%s Tiene %d anios\n", s, e);

    int x = 0xCAFE;

    printf("%x %X\n", x, x);

    // %% es para imprimir %
    printf("100%%\n");
}