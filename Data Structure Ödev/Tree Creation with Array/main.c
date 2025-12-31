#include <stdio.h>

#define MAX 100
#define EMPTY -1

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = EMPTY;
    }
}

void insertRoot(int value) {
    if (tree[1] != EMPTY) {
        printf("Root zaten var!\n");
        return;
    }
    tree[1] = value;
}

void insertLeft(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex;

    if (parentIndex <= 0 || leftIndex >= MAX) {
        printf("Gecersiz index!\n");
        return;
    }

    if (tree[parentIndex] == EMPTY) {
        printf("Parent yok! Once parent'i ekle.\n");
        return;
    }

    if (tree[leftIndex] != EMPTY) {
        printf("Sol cocuk zaten dolu!\n");
        return;
    }

    tree[leftIndex] = value;
}

void insertRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 1;

    if (parentIndex <= 0 || rightIndex >= MAX) {
        printf("Gecersiz index!\n");
        return;
    }

    if (tree[parentIndex] == EMPTY) {
        printf("Parent yok! Once parent'i ekle.\n");
        return;
    }

    if (tree[rightIndex] != EMPTY) {
        printf("Sag cocuk zaten dolu!\n");
        return;
    }

    tree[rightIndex] = value;
}

void preorder(int index) {
    if (index >= MAX) return;
    if (tree[index] == EMPTY) return;

    printf("%d ", tree[index]);
    preorder(2 * index);
    preorder(2 * index + 1);
}

void inorder(int index) {
    if (index >= MAX) return;
    if (tree[index] == EMPTY) return;

    inorder(2 * index);
    printf("%d ", tree[index]);
    inorder(2 * index + 1);
}

void postorder(int index) {
    if (index >= MAX) return;
    if (tree[index] == EMPTY) return;

    postorder(2 * index);
    postorder(2 * index + 1);
    printf("%d ", tree[index]);
}

int main() {
    initTree();

    // aðaç oluþtur:
    //          10
    //        /    \
    //       5      15
    //      / \    /
    //     2   7  12

    insertRoot(10);
    insertLeft(1, 5);
    insertRight(1, 15);
    insertLeft(2, 2);
    insertRight(2, 7);
    insertLeft(3, 12);

    printf("Preorder: ");
    preorder(1);
    printf("\n");

    printf("Inorder: ");
    inorder(1);
    printf("\n");

    printf("Postorder: ");
    postorder(1);
    printf("\n");

    return 0;
}
