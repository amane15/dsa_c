#ifndef BST_H
#define BST_H

#include <stdbool.h>

#define MEM_ALLOC_ERR "Memory allocation error\n"

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *init_root(int value);
Node *create_node(int value);
void insert(Node *root, int value);
void delete_tree(Node **root_ptr);
void print_tree(Node *root, int space);
bool find(Node *root, int value);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);

#endif