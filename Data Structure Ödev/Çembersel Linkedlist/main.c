#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void printList(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node* insertFront(Node *head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return newNode;
}

void insertAfter(Node *prev, int data) {
    if (prev == NULL) return;

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = prev->next;
    prev->next = newNode;
}

Node* deleteValue(Node *head, int key) {
    if (head == NULL) return NULL;

    Node *curr = head;

    if (curr->data == key && curr->next == head) {
        free(curr);
        return NULL;
    }

    if (curr->data == key) {
        while (curr->next != head)
            curr = curr->next;

        curr->next = head->next;
        free(head);
        return curr->next;
    }

    Node *prev = head;
    curr = head->next;

    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main() {
    Node *head = NULL;

    head = insertFront(head, 3);
    head = insertFront(head, 2);
    head = insertFront(head, 1);

    printList(head);

    insertAfter(head, 99);
    printList(head);

    head = deleteValue(head, 2);
    printList(head);

    return 0;
}
