#include <stdio.h>

void changeValue(char** g)
{
    *g = "mundo";
}

int main() {
	char* s = "hola";

    printf("s: %p\n", s);
    printf("*s: %c\n", *s);
    
    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    // s++;
    // printf("s: %p\n", s);
    // printf("*s: %c\n", *s);

    printf("la direccion de memoria de s es: %p\n", &s);

    puts("Despues del cambio");

    changeValue(&s);

    puts(s);

    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    puts("Desde aqui llegamos de nuevo a hola");

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    s++;
    printf("s: %p\n", s);
    printf("*s: %c\n", *s);

    // Esto tambien se puede hacer
    s = "java";
    puts(s);

}