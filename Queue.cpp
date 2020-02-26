/*************************************************************************
	> File Name: Queue.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时39分54秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length, size, count;
} Queue;

Queue *init(int size) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = 0;
    q->tail = -1;
    q->length = 0;
    q->size = size;
    q->count = 0;
}

int empty(Queue *q) {
    return q->count == 0;
}


int push(Queue *q, int val) {
    if (q->count >= q->size) return 0;
    q->tail = (++q->tail) % q->size;
    q->data[q->tail] = val;
    q->count++;
    return 1;
}

int pop(Queue *q) {
    if (empty(q)) return 0;
    q->head++;
    q->count--;
    return 1;
}

int top(Queue *q) {
    return q->data[q->head];
}

void output(Queue *q) {
    if (empty(q)) return ;
    printf("Queue(%d) = [", q->length);
    for (int cnt = 0, i = q->head; cnt < q->count; cnt++) {
        cnt && printf(" ");
        printf("%d", q->data[i]);
        i = (++i) % q->size;
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (empty(q)) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(5);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d in the Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                printf("pop item from the Queue = %d\n", pop(q));
            } break;
        }
        output(q);
    }
    clear(q);
    return 0;
}
