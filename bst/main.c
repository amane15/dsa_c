#include <stdio.h>

#include "bst.h"

int main(void) {
    Node *root = init_root(10);

    insert(root, 7);
    insert(root, 8);
    insert(root, 6);
    insert(root, 15);
    insert(root, 13);
    insert(root, 16);

    // print_tree(root, 0);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    delete_tree(&root);
    return 0;
}