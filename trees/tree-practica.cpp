#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node
{
    public:
        const char* data;
        Node* left;
        Node* right;

        Node()
        {

        }
};

class Tree
{
    public:
        Node* root;

        Tree()
        {
            this->root = NULL;
        }

        int Add(const char* data)
        {
            return Add_r(data, &(this->root));
        }

        int Add_r(const char* data, Node** node)
        {
            if (*node == NULL)
            {
                *node = new Node();
                (*node)->left = NULL;
                (*node)->right = NULL;
                (*node)->data = data;

                return 1;
            }

            int r = strcmp((*node)->data, data);

            if (r == 0)
            {
                puts("el dato ya existe en el arbol");
                return 0;
            }

            if (r > 0)
                return Add_r(data, &((*node)->left));

            return Add_r(data, &((*node)->right));
        }

        void print()
        {
            print_r(this->root);
        }

        void print_r(Node* node)
        {
            if (node == NULL)
                return;

            print_r(node->left);
            printf("%s\n", node->data);
            print_r(node->right);
        }
};


int main()
{
    Tree tree;

    tree.Add("Joey");
    tree.Add("Johnny");

    tree.print();
}