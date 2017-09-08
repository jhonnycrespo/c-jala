#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[32];
} my_string;

void disklist_add(FILE* f, const char* s)
{
    my_string ms;

    strcpy(ms.data, s);
    fwrite(&ms, 1, sizeof(my_string), f);
}

size_t disklist_size(FILE* f)
{
    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    return len / sizeof(my_string);
}

void disklist_get(FILE* f, size_t index, my_string* s)
{
    fseek(f, index*sizeof(my_string), SEEK_SET);
    fread(s, 1, sizeof(my_string), f);
}

void disklist_put(FILE* f, size_t index, const my_string* ms)
{
    // set the position indicator associdated with the stream to a new position.
    // f is a pointer of type FILE*
    // offset  is number of bytes to offset from origin
    // origin is the position used as reference of the offset:
    // SEEK_SET: Beginning of file
    // SEEK_CUR: Current position of the file pointer
    // SEEK_END: End of file
    fseek(f, index * sizeof(my_string), SEEK_SET);
    fwrite(ms, 1, sizeof(my_string), f);
}

// Bubble sort
void disklist_sort(const char* fn)
{
    FILE* g = fopen(fn, "rb+");
    size_t len = disklist_size(g);

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            my_string aux1, aux2;
            // leer una cadena del disco
            disklist_get(g, j, &aux1);
            disklist_get(g, j + 1, &aux2);

            int c = strcmp(aux1.data, aux2.data);

            if (c > 0)
            {
                disklist_put(g, j, &aux2);
                disklist_put(g, j + 1, &aux1);
            }
        }
    }
    fclose(g);
}

int main()
{
    FILE* f = fopen("strs.dat", "w");

    disklist_add(f, "Lunes");
    disklist_add(f, "Martes");
    disklist_add(f, "Miercoles");
    disklist_add(f, "Jueves");
    disklist_add(f, "Viernes");
    disklist_add(f, "Sabado");
    disklist_add(f, "Domingo");

    fclose(f);

    // f = fopen("strs.dat", "rb");
    // size_t len = disklist_size(f);

    // leemos del final para adelante
    // for (int i = len - 1; i >= 0;  i--)
    // {
    //     my_string aux;
    //     disklist_get(f, i, &aux);
    //     puts(aux.data);
    // }



    disklist_sort("strs.dat");
    FILE* z = fopen("strs.dat","rb");
    size_t len = disklist_size(z);

    for (int i = 0; i < len; i++)
    {
        my_string aux;

        disklist_get(z, i, &aux);
        puts(aux.data);
    }

    fclose(f);
}