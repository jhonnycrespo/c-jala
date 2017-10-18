#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * int strcmp (const char* str1, const char* str2);
 * void * memcpy (void* destination, const void* source, size_t num);
 */

// a pointer to void is a generic pointer type. A void* can be
// converted to any other pointer type without an explicit cast (only in C).
// In c++ you need to cast.
int cmp_str(const void* a, const void* b)
{
    // c++ compatible
    return strcmp((char*) a, (char*) b);
}

char* create_string_heap(char* str)
{
    // the null character does not count in the length.
    size_t len = strlen(str);
    // +1 for the \0 character
    char* s = (char*) malloc(len + 1);
    memcpy(s, str, len + 1);

    return s;
}

int main()
{
    // internamente se convierte a const char*
    // estos strings no estan en el heap ni en el stack.
    // son constantes.
    char* a = "Google";
    char* b = "Facebook";
    // estos strings, no se pueden modificar.
    // segmentation fault.
    // a[0] = 'D';
    int c = cmp_str(a, b);
    printf("%d\n", c);



    // estos strings se almacenan en el stack.
    // estos strings, si se pueden modificar.
    char d[] = "Mvidia";
    char e[] = "AMD";

    d[0] = 'N';

    c = cmp_str(d, e);
    printf("%d\n", c);


    // estos strings, se almacenan en el heap.
    char* f = create_string_heap("Stanford");
    char* g = create_string_heap("Oxford");

    c = cmp_str(f, g);
    printf("%d\n", c);
}