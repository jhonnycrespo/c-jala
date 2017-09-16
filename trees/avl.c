#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avl_node
{
    void* data;
    // height of the subtree
    size_t height;
    // number of nodes in subtree
    size_t size;
    struct avl_node* left;
    struct avl_node* right;
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

int avl_is_empty(avl* tree)
{
    return (tree->root == NULL);
}

size_t node_size(node** node)
{
    if(*(node) == NULL)
        return 0;

    return (*(node))->size;
}

size_t node_height(node** node)
{
    if (*(node) == NULL)
        return 0;

    return (*(node))->height;
}

// la diferencia entre las alturas de los sub-trees deben ser a lo mucho 1
int balance_factor(node* node)
{
    return node_height(&(node->left)) - node_height(&(node->right));
}

int int_max(int a, int b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;

    return a;
}

void rotate_right(node** oldRoot)
{
    node** newRoot = *oldRoot->left;
    *oldRoot->left = *newRoot->right;
    *newRoot->right = *oldRoot;

    newRoot->size = oldRoot->size;
    oldRoot->size = node_size(&(oldRoot->left)) + node_size(&(oldRoot->right)) + 1;
    
    oldRoot->height = int_max(node_height(&(oldRoot->left)), node_height(&(oldRoot->right))) + 1;
    newRoot->height = int_max(node_height(&(newRoot->left)), node_height(&(newRoot->right))) + 1;
}

void rotate_left(node** oldRoot)
{
    node* newRoot = oldRoot->right;
    oldRoot->right = newRoot->left;
    newRoot->left = oldRoot;

    newRoot->size = oldRoot->size;
    oldRoot->size = node_size(&(oldRoot->left)) + node_size(&(oldRoot->right)) + 1;
    
    oldRoot->height = int_max(node_height(&(oldRoot->left)), node_height(&(oldRoot->right))) + 1;
    newRoot->height = int_max(node_height(&(newRoot->left)), node_height(&(newRoot->right))) + 1;
}


void balance(node** node)
{
    if (balance_factor(*node) < -1)
    {
        if (balance_factor((*node)->right) > 0)
        {
            rotate_right((*node)->right);
        }
        rotate_left(&(*node));
    }
    else
    {
        if (balance_factor((*node)) > 1)
        {
            if (balance_factor((*node)->left) < 0)
            {
                rotate_left((*node)->left);
            }
            rotate_right(&(*node));
        }
    }
}

void avl_init(avl* tree, int (*cmp)(const void*, const void*), void (*f)(void*))
{
    tree->root = NULL;
    tree->cmp = cmp;
    tree->f = f;
}

int* get_int(int n)
{
    int* r = (int*) malloc(sizeof(n));
    *r = n;
    
    return r;
}

int avl_add_r(avl* tree, node** n, void* p)
{
    int res;

    if (*n == NULL)
    {
        *n = (node*) malloc(sizeof(node));
        (*n)->left = NULL;
        (*n)->right = NULL;
        (*n)->data = p;

        (*n)->height = 0;
        (*n)->size = 1;

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

    printf("r: %d\n", r);

    if (r == 0)
        return 0;

    // si el node root es mayor
    if (r > 0)
    {
        res =  avl_add_r(tree, &((*n)->left), p);    
        
    }
    else
    {
        res =  avl_add_r(tree, &((*n)->right), p);
    } 

    (*n)->size = node_size(&((*n)->left)) + node_size(&((*n)->right)) + 1;
    (*n)->height = int_max(node_height(&((*n)->left)), node_height(&((*n)->right))) + 1;

    balance(&(*n));

    return res;
}

int avl_add(avl* tree, void* p)
{
    return avl_add_r(tree, &(tree->root), p);
}

void print_int(void* x, const void* p)
{
    printf("%d\n", *((int*)p));
}


void avl_iterate_r(node* n, void* tag, void(*f)(void*, const void*))
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
    avl_iterate_r(n->left, tag, f);
    f(tag, n->data);
    avl_iterate_r(n->right, tag, f);
}

void avl_iterate(avl* tree, void* tag, void (*f)(void*, const void*))
{
    avl_iterate_r(tree->root, tag, f);
}

void acum(void* tag, const void* p)
{
    int* s = (int*) tag;
    int n = *((int*) p);

    *s += n;
}

void* avl_search_r(const avl* tree, const node* n, const void* s)
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
        return avl_search_r(tree, n->left, s);

    return avl_search_r(tree, n->right, s);
}

// void* avl_search(const avl* p, const void* s)
// {
    // pasamos el arbol, porque en el arbol esta la funcion comparadora.
    // return avl_search_r(p, p->root, s);
// }

void avl_release_r(avl* tree, node* n)
{
    if (n == NULL)
        return;

    avl_release_r(tree, n->left);
    avl_release_r(tree, n->right);
    tree->f(n->data);
    free(n);
    puts("bye");
}

void avl_release(avl* tree)
{
    // El arbol tiene la funcion que sabe liberar la memoria
    avl_release_r(tree, tree->root);
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

    avl_init(&tree, cmp_int, free);

    avl_add(&tree, get_int(50));
    avl_add(&tree, get_int(45));
    avl_add(&tree, get_int(65));
    avl_add(&tree, get_int(55));
    avl_add(&tree, get_int(75));
    avl_add(&tree, get_int(70));


    // printf("%p\n", tree.root);
    // printf("%d\n", *(int*) tree.root->data);
    
    // Para que pasar el argumento null?
    avl_iterate(&tree, NULL, print_int);

    // int s = 0;
    // avl_iterate(&tree, &s, acum);
    // printf("suma: %d\n", s);

    avl_release(&tree);
}