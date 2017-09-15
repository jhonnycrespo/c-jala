#include <stdio.h>

int main()
{
    puts("Enter your fullname");

    char name[100];

    // tiene problemas al leer espacios
    // scanf("%s", name);

    // Esta funcion es peligrosa, que pasa si el buffer no es lo suficientemente grande?
    // gets(name);
    fgets(name, 100, stdin);

    puts(name);

    // printf("Hello %s\n", name);
    

    const char* p = "1243";

    int n;

    sscanf(p, "%d", &n); 

    printf("%d\n", ++n);


    int m = 666;
    sscanf(p, "%d", &m); 
    printf("%d\n", ++m);
    
}

