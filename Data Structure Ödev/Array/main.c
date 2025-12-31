#include <stdio.h>

#define MAX 100
#define EMPTY -1  // boþ düðüm iþareti

int tree[MAX];

// Aðacý boþla
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

    if (parentIndex <= 0 || parentIndex >= MAX) {
        printf("Gecersiz parent index!\n");
        return;
    }

    if (tree[parentIndex] == EMPTY) {
        printf("Parent yok! Once parent'i ekle.\n");
        return;
    }

    if (leftIndex >= MAX) {
        printf("Index disi (overflow)!\n");
        return;
    }

    if (tree[leftIndex] != EMPTY) {
        printf("Sol cocuk zaten var!\n");
        return;
    }

    tree[leftIndex] = value;
}

void insertRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 1;

    if (parentIndex <= 0 || parentIndex >= MAX) {
        printf("Gecersiz parent index!\n");
        return;
    }

    if (tree[parentIndex] == EMPTY) {
        printf("Parent yok! Once parent'i ekle.\n");
        return;
    }

    if (rightIndex >= MAX) {
        printf("Index disi (overflow)!\n");
        return;
    }

    if (tree[rightIndex] != EMPTY) {
        printf("Sag cocuk zaten var!\n");
        return;
    }

    tree[rightIndex] = value;
}

void preorder(int index) {
    if (index >= MAX) return;
    if (tree[index] == EMPTY) return;

    // Root
    printf("%d ", tree[index]);
    // Left
    preorder(2 * index);
    // Right
    preorder(2 * index + 1);
}

void deleteSubtree(int index) {
    if (index >= MAX) return;
    if (tree[index] == EMPTY) return;

    // Önce çocuklarý sil
    deleteSubtree(2 * index);
    deleteSubtree(2 * index + 1);

    // Sonra kendini boþalt
    tree[index] = EMPTY;
}

int main() {
    initTree();

    insertRoot(10);
    insertLeft(1, 5);
    insertRight(1, 15);
    insertLeft(2, 2);
    insertRight(2, 7);
    insertLeft(3, 12);
    insertRight(3, 20);

    printf("Preorder: ");
    preorder(1);
    printf("\n");

    printf("2. dugumun alt agacini siliyorum...\n");
    deleteSubtree(2);

    printf("Preorder sonra: ");
    preorder(1);
    printf("\n");

    return 0;
}
