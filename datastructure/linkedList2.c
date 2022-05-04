#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;


void addFront(Node *root, int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root) {
    Node *node = root->next;
    root->next = node->next;
    free(node);
}

void freeAll(Node *root) {
    Node *cur = root->next;
    while(cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root) {
    Node *cur = root->next;
    while(cur != NULL) {
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node*) malloc(sizeof(Node)); head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8); removeFront(head);
    showAll(head);
    freeAll(head);
    return 0;
}
