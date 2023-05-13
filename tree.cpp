#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* makeTree() {
    Node* root = createNode(100);
    Node* node1 = createNode(200);
    Node* node2 = createNode(300);
    Node* node3 = createNode(400);
    Node* node4 = createNode(500);

    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;

    return root;
}

void printNode(Node* root) {
    printf("Pre-order: ");
    preOrder(root);
    printf("\n");

    printf("In-order: ");
    inOrder(root);
    printf("\n");

    printf("Post-order: ");
    postOrder(root);
    printf("\n");
}

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}