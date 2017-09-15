#include <stdio.h>

typedef struct {
    char* data;
} node;

void changeValue(node* n) {
    n->data = "chau";
}

void funcA(node* n) {
    puts(n->data);
    changeValue(n);
}

void node_init(node* n)
{
    n->data = "hola";
}

int main()
{
    node n;
    node_init(&n);

    funcA(&n);

    puts(n.data);
}