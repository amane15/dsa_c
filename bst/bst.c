#include "bst.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node *init_root(int value) {
    Node *root = (Node *)malloc(sizeof(Node));
    if (root == NULL) {
        printf(MEM_ALLOC_ERR);
        exit(1);
    }

    root->value = value;
    root->left = NULL;
    root->right = NULL;

    return root;
}

Node *create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf(MEM_ALLOC_ERR);
        exit(1);
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node *root, int value) {
    if (root->value == value) return;

    if (value < root->value) {
        if (root->left == NULL) {
            root->left = create_node(value);
            return;
        } else {
            insert(root->left, value);
        }
    }
    if (value > root->value) {
        if (root->right == NULL) {
            root->right = create_node(value);
            return;
        } else {
            insert(root->right, value);
        }
    }
}

void free_tree(Node *node) {
    if (node == NULL) return;

    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void delete_tree(Node **root_ptr) {
    if (root_ptr == NULL || *root_ptr == NULL) return;

    free(*root_ptr);
    *root_ptr = NULL;
}

void print_tree(Node *root, int space) {
    if (root == NULL) return;

    const int indent = 5;
    space += indent;

    print_tree(root->right, space);

    for (int i = indent; i < space; i++) printf(" ");
    printf("%d\n", root->value);

    print_tree(root->left, space);
}

bool find(Node *root, int value) {
    if (root == NULL) return false;
    if (root->value == value) return true;

    if (value < root->value) {
        return find(root->left, value);
    } else {
        return find(root->right, value);
    }
}

void inorder(Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) return;

    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}