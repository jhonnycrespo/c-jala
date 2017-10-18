#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * String literals such as "hello" are stored in such a way that they 
 * are held over the lifetime of the program. They are often stored in 
 * a separate "data segment" (distinct from the stack or heap) which may 
 * be read-only.
 */

int main()
{
    // allocate 8 bytes in the stack and store "LINUS" in them.
    char c[8];

    c[0] = 'J';
    c[1] = 'U';
    c[2] = 'A';
    c[3] = 'N';
    c[4] = '\0';

    printf("%s\n", c);
    printf("Size in bytes = %zu\n", sizeof(c));
    // the null character does not count in the length
    int len = strlen(c);
    // prints 4
    printf("length = %d\n", len);


    // allocate 20 bytes in the stack and store "LINUS" in them.
    // Agrega automaticamente el caracter \0
    char b[20] = "BJARNE";
    printf("%s\n", b);
    printf("Size in bytes = %zu\n", sizeof(b));
    // the null character does not count in the length
    len = strlen(b);
    printf("length = %d\n", len);


    // allocate 7 bytes in the stack and store "LINUS" in them.
    // Agrega automaticamente el caracter \0
    char a[] = "DENNIS";
    printf("%s\n", a);
    printf("Size in bytes = %zu\n", sizeof(a));
    // the null character does not count in the length
    len = strlen(a);
    printf("length = %d\n", len);


    // allocate 6 bytes in the stack and store "LINUS" in them.
    char d[] = {'L', 'I', 'N', 'U', 'S', '\0'};
    printf("%s\n", d);
    printf("Size in bytes = %zu\n", sizeof(d));
    // the null character does not count in the length
    len = strlen(a);
    printf("length = %d\n", len);



    // allocate a pointer on the stack and point it to a static,
    // read-only buffer containing "RICHARD".
    char* e = "RICHARD"; // internamente se convierte a const char* e = "RICHARD"
    // segmentation faul
    // e[0] = 'r'; 

    // allocate 7 bytes in the heap (which by the way is not enough
    // to hold "RICHARD" due to the null character).
    char* heap = malloc(7);

    // reset heap to point to a static buffer...Memory Leak!!
    // we haven't freed the last malloc.
    heap = "RICHARD";
}
