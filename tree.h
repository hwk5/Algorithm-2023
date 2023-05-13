#pragma once

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeTree();
Node* createNode(int value);
void printNode(Node* root);
void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);