#include <stdio.h>
#define SIZE 10000
#define INF 9999999

int stack[SIZE];
int top=-1;

void push(int data) {
    if(top >= SIZE-1) {
        printf("overflow");
        return;
    }
    stack[++top] = data;
}

void pop() {
    if(top < 0) {
        printf("underflow");
        return;
    }
    --top;
}

void show() {
    int idx = top;
    while(idx>-1) {
        printf("%d\n",stack[idx--]);
    }
}

int main() {
  push(7);
  push(5);
  push(4);
  pop();
  push(6);
  pop();
  show();
  return 0;
}
