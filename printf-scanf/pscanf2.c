#include <stdio.h>


int main()
{
    int a = 2;
    int b = 3;

    // stdout: pantalla
    // stderr: pantalla
    // stdin: teclado
    fprintf(stdout, "%d + %d = %d\n", a, b, a + b);
    
    fprintf(stderr, "%d + %d = %d\n", a, b, a + b);

    // hay q calcular mas o menos el tamanio del buffer.
    char buf[100];
    // para escribir en buffers
    sprintf(buf, "%d + %d = %d\n", a, b, a + b);

    puts(buf);

    int c = 248;
    char cs[16];
    sprintf(cs, "%d\n", c);

    printf("%s\n", cs);
}