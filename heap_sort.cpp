/*************************************************************************
	> File Name: heap_sort.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时51分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if (q->cnt >= q->size) return 0;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while (ind >> 1 && q->data[ind >> 1] < q->data[ind]) {
        swap(q->data[ind >> 1], q->data[ind]);
        ind /= 2;
    }
    return 1;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[q->cnt--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind * 2 + 1;
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (empty(q)) return ;
    free(q->data);
    free(q);
    return ;
} 

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("insert %d at queue\n", val);
    }
    for (int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    printf("\n");
    clear(q);
    return 0;
}
