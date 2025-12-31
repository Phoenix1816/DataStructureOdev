#include <stdio.h>
#include <stdlib.h>

#define MAX 64

typedef struct {
    int arr[MAX];
    int top;
    char name;
} Stack;

void init(Stack *s, char name) {
    s->top = -1;
    s->name = name;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

void moveDisk(Stack *from, Stack *to) {
    int disk = pop(from);
    push(to, disk);
    printf("Disk %d: %c --> %c\n", disk, from->name, to->name);
}

// Klasik rekürsif Hanoi algoritmasý
void hanoi(int n, Stack *from, Stack *aux, Stack *to) {
    if (n == 0) return;

    hanoi(n - 1, from, to, aux);      // n-1 diski yardýmcýya taþý
    moveDisk(from, to);               // en büyük diski hedefe taþý
    hanoi(n - 1, aux, from, to);      // n-1 diski yardýmcýdan hedefe taþý
}

int main() {
    int n = 3;

    Stack A, B, C;
    init(&A, 'A');
    init(&B, 'B');
    init(&C, 'C');

    // Baþta tüm diskleri A'ya koy
    for (int i = n; i >= 1; i--) {
        push(&A, i);
    }

    hanoi(n, &A, &B, &C);

    return 0;
}
