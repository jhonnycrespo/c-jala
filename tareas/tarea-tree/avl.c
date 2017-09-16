#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct avl_node
{
    void* data;
    struct avl_node* left;
    struct avl_node* right;
    int height;

} node;

typedef struct
{
    node* root;
    int (*cmp)(const void*, const void*);
    void (*f)(void*);
} avl;

void avl_init(avl* tree, int (*cmp)(const void*, const void*), void (*f)(void*))
{
    tree->root = NULL;
    tree->cmp = cmp;
    tree->f = free;

}

int cmp_int(const void* a, const void* b)
{
    int x = *((int*) a);
    int y = *((int*) b);

    return x - y;
}

int* get_int(int n)
{
    int* n_ptr = (int*) malloc(sizeof(int));
    *n_ptr = n;

    return n_ptr;
}

int height(node* n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void update_height(node* p)
{
    p->height = 1 + max(height(p->left), height(p->right));
}

int balance_factor(node* n)
{
    return height((n)->left) - height((n)->right);
}

node* rotate_right(node* p)
{
    node* q = p->left;

    p->left = q->right;
    q->right = p;

    update_height(p);
    update_height(q);

    return q;
}

node* rotate_left(node* p)
{
    node* q = p->right;

    p->right = q->left;
    q->left = p;

    update_height(p);
    update_height(q);

    return q;
}

node* balance(node* p)
{
    update_height(p);

    if (height(p->left) - height(p->right) == 2)
    {
        if (height(p->left->right) > height(p->left->left))
            p->left = rotate_left(p->left);

        return rotate_right(p);
    }
    else if (height(p->right) - height(p->left) == 2)
    {
        if (height(p->right->left) > height(p->right->right))
            p->right = rotate_right(p->right);

        return rotate_left(p);
    }

    return p;
}

node* create_node(void* data)
{
    node* n = (node*) malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->height = 1;

    return n;
}

int avl_add_r(avl* tree, node** n, void* data)
{
    int res = 0;

    if (*n == NULL)
    {
        *n = create_node(data);
        return 1;
    }

    int c = tree->cmp((*n)->data, data);

    if (c == 0)
        return 0;

    if (c > 0)
    {
        res = avl_add_r(tree, &((*n)->left), data);
    } else {
        res = avl_add_r(tree, &((*n)->right), data);    
    }

    balance(*n);

    return res;
}

int avl_add(avl* tree, void* data)
{
    avl_add_r(tree, &(tree->root), data);
}

void print_int(void* x, const void* p)
{
    printf("%d\n", *((int*) p));
}

void avl_iterate_r(node* n, void* tag, void (*f)(void*, const void*))
{
    if (n == NULL)
        return;

    avl_iterate_r(n->left, tag, f);
    f(tag, n->data);
    printf("%d\n", n->height);
    avl_iterate_r(n->right, tag, f);
}

void avl_iterate(avl* tree, void* tag, void (*f)(void*, const void*))
{
    avl_iterate_r(tree->root, tag, f);
}

int main()
{
    avl tree;

    avl_init(&tree, cmp_int, free);

    avl_add(&tree, get_int(50));
    avl_add(&tree, get_int(30));
    avl_add(&tree, get_int(70));
    avl_add(&tree, get_int(15));
    avl_add(&tree, get_int(40));
    avl_add(&tree, get_int(10));

    avl_iterate(&tree, NULL, print_int);
}