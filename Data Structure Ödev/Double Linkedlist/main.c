#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* pushFront(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

void printForward(Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printBackward(Node* tail) {
    printf("Backward: ");
    while (tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next = newNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

Node* deleteNode(Node* head, Node* del) {
    if (head == NULL || del == NULL)
        return head;

    if (head == del)
        head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return head;
}

int main() {
    Node* head = NULL;

    head = pushFront(head, 3);
    head = pushFront(head, 2);
    head = pushFront(head, 1);

    printForward(head);

    insertAfter(head, 99);
    printForward(head);

    head = deleteNode(head, head->next);
    printForward(head);

    return 0;
}
