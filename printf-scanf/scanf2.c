#include <stdio.h>

int main()
{
    FILE* f = fopen("cuentas.txt", "r");
    
    if (!f)
        return -4;

    int a, b, c;

    while (1)
    {
        int r = fscanf(f, "%d %d %d", &a, &b, &c);

        if (r == -1)
            break;

        printf("%d, %d, %d = %d\n", a, b, c, a + b+ c);
    }
}

