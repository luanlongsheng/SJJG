/*************************************************************************
	> File Name: Stack.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时42分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
} Stack;

void init(Stack *s, int size) {
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
}

int empty(Stack *s) {
    return s->top < 0;
}

int top(Stack *s) {
    return s->data[s->top];
}

int push(Stack *s, int val) {
    if (s->top >= s->size - 1) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (empty(s)) return 0;
    s->top--;
    return 1;
}

void output(Stack *s) {
    if (empty(s)) return ;
    printf("Stack(%d) = [", s->top + 1);
    for (int i = 0; i <= s->top; i++) {
        i && printf(" ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
}

void clear(Stack *s) {
    if (empty(s)) return ;
    free(s->data);
    free(s);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, max_op);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d at Stack = %d\n", val, push(s, val));
            } break;
            case 3: {
                printf("pop item from Stack = %d\n", pop(s));
            } break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
