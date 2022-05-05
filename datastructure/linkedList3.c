#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

void insert(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node *cur = head->next;
    printf("insert data is %d\n",data);
    while(cur != tail && cur->data < node->data) {
            printf("cur data1 is : %d\n",cur->data);
            cur = cur->next;
    }
    node->prev=cur->prev;
    node->next=cur;
    cur->prev->next=node;
    cur->prev=node;
}

void removeFront() {
    Node *node = head->next;
    if(node != tail) {
        head->next = node->next;
        node->next->prev=head;
        free(node);
    }

}

void show() {
    Node *cur = head->next;
    while(cur!=tail) {
        printf("%d ",cur->data);
        cur = cur->next;
    }
}

/**
* 양방향 연결리스트 구현
*/
int main() {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
    insert(2);
    insert(1); 
    insert(3);
    insert(9);
    insert(7);
    removeFront();
    removeFront();
    show();
    return 0;
}

