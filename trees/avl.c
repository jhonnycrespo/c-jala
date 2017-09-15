#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bst_node
{
    void* data;
    struct bst_node* left;
    struct bst_node* right;
} node;

typedef struct
{
    node* root;
    size_t height;
    size_t nodes:
    int (*cmp) (const void*, const void*);
    void (*f) (void*);
} avl;

int cmp_int(const void* a, const void* b)
{
    int x = *((int*) a);
    int y = *((int*) b);

    return x - y;
}

void bst_init(avl* x, int (*cmp)(const void*, const void*), void (*f)(void*))
{
    x->root = NULL;
    x->cmp = cmp;
    x->f = f;
}

int* get_int(int n)
{
    int* r = (int*) malloc(sizeof(n));
    *r = n;
    
    return r;
}

int height(node* node)
{
    if (node == NULL)
        return -1;

    return node->height;
}

int size(node* node)
{
    if (node == NULL)
        return 0;

    return node->size;
}

int heights_difference(node* node)
{
    return height(node->left) - height(node->right);
}

int bst_add_r(avl* tree, node** n, void* p)
{
    if (*n == NULL)
    {
        *n = (node*) malloc(sizeof(node));
        (*n)->left = NULL;
        (*n)->right = NULL;
        (*n)->data = p;
        (*n)->nodes = 1;
        (*n)->heights = 1;

        return 1;
    }
    
    int r = tree->cmp((*n)->data, p);
    
    if (r == 0)
        return 0;
        
    if (r > 0)
        return bst_add_r(tree, &((*n)->left), p);
        
    return bst_add_r(tree, &((*n)->right), p);
}

int bst_add(avl* tree, void* p)
{
    return bst_add_r(tree, &(tree->root), p);
}

void print_int(void* x, const void* p)
{
    printf("%d\n", *((int*)p));
}

void bst_iterate_r(node* n, void* tag, void(*f)(void*, const void*))
{
    if (n == NULL)
        return;

    bst_iterate_r(n->left, tag, f);
    f(tag, n->data);
    bst_iterate_r(n->right, tag, f);
}

void bst_iterate(avl* tree, void* tag, void(*f)(void*, const void*))
{
    bst_iterate_r(tree->root, tag, f);
}

void acum(void* tag, const void* p)
{
    int* s = (int*) tag;
    int n = *((int*) p);

    *s += n;
}

void* bst_search_r(const avl* tree, const node* n, const void* s)
{
    // si el arbol esta vacio, o si s no se encuentra en el arbol
    if (n == NULL)
        return NULL;

    int c = tree->cmp(n->data, s);

    if (c == 0)
        return n->data;

    if (c > 0)
        return bst_search_r(tree, n->left, s);

    return bst_search_r(tree, n->right, s);
}

void* bst_search(const avl* p, const void* s)
{
    // pasamos el arbol, porque en el arbol esta la funcion comparadora.
    return bst_search_r(p, p->root, s);
}

void bst_release_r(avl* tree, node* n)
{
    if (n == NULL)
        return;

    bst_release_r(tree, n->left);
    bst_release_r(tree, n->right);
    tree->f(n->data);
    free(n);
    puts("bye");
}

void bst_release(avl* tree)
{
    // El arbol tiene la funcion que sabe liberar la memoria
    bst_release_r(tree, tree->root);
}

char* get_str(const char* s) {
    size_t len = strlen(s);
    char* p = (char*) malloc(len);
    memcpy(p, s, len + 1);

    return p;
}

// Recibimos void* x en caso de enviarle NULL.
void print_str(void* x, const void* s)
{
    puts((char*) s);
}

int cmp_str(const void* a, const void* b)
{
    return strcmp((char*) a, (char*) b);
}

int main()
{
    avl tree;
    bst_init(&tree, cmp_int, free);

    bst_add(&tree, get_int(25));
    bst_add(&tree, get_int(30));
    bst_add(&tree, get_int(22));
    bst_add(&tree, get_int(40));
    bst_add(&tree, get_int(17));

    // printf("%p\n", tree.root);
    printf("%d\n", *(int*) tree.root->data);
    
    // Para que pasar el argumento null?
    bst_iterate(&tree, NULL, print_int);

    int s = 0;
    bst_iterate(&tree, &s, acum);
    printf("suma: %d\n", s);


    int n = 40;
    // Esta funcion debe ser lo bastante generica para buscar cualquier cosa. Por eso pasamos
    // direccion de memoria en lugar de pasar directamente el entero.
    void* x = bst_search(&tree, &n);

    if (x == NULL)
        puts("Not Found");
    else
        printf("%d\n", *((int*) x));

    bst_release(&tree);

    avl tree2;

    bst_init(&tree2, cmp_str, free);

    bst_add(&tree2, get_str("java"));
    bst_add(&tree2, get_str("c"));
    bst_add(&tree2, get_str("c++"));
    bst_add(&tree2, get_str("pascal"));
    bst_add(&tree2, get_str("fortran"));
    bst_add(&tree2, get_str("javascript"));

    bst_iterate(&tree2, NULL, print_str);

    const char* txt = "javascript";

    void* rr = bst_search(&tree2, txt);

    if (rr == NULL)
        puts("Not Found");
    else
        print_str(NULL, rr);

    bst_release(&tree2);
}