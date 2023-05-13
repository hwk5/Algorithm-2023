#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    printf("이진트리 생성\n");

    Node* root = makeTree();
    printNode(root);

    return 0;
}