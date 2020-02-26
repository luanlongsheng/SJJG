/*************************************************************************
	> File Name: List.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时23分09秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node head;
    int length;
} List;

Node *getnode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getlist() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *node = getnode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length++;
    return 1;
}

int delete_node(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length--;
    return 1;
}

void reverse(List *l) {
    if (l == NULL) return ;
    Node *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}

void output(List *l) {
    if (l == NULL) return ;
    printf("List[%d] = [", l->length);
    for (Node *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}


void clear_node(Node *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_list(List *l) {
    if (l == NULL) return ;
    Node *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int op, ind, val;
    List *l = getlist();
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf("reverse the list\n");
                reverse(l);
            } break;
            case 3: {
                printf("delete item at %d from List = %d\n", ind, delete_node(l, ind));
            } break;
        }
        output(l);
        printf("\n");
    }
    clear_list(l);
    return 0;
}
