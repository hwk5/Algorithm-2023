#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    printf("����Ʈ�� ����\n");

    Node* root = makeTree();
    printNode(root);

    return 0;
}