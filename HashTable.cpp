/*************************************************************************
	> File Name: HashTable.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月29日 星期六 00时11分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HasTable {
    Node **data;
    int size;
} HasTable;

Node *initnode(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HasTable *inithastable(int n) {
    HasTable *h = (HasTable *)malloc(sizeof(HasTable));
    h->size = n << 1;
    h->data = (Node **)calloc(h->size, sizeof(Node *));
    return h;
}

int BKDRHash(char *str) {//此函数是哈希映射函数，将一个字符映射到某一确定存储位置
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash & 0x7fffffff;
}

int insert(HasTable *h, char *str) {//h->data[i]中存放着所有哈希映射值为i的字符组成的链表的表头指针
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = initnode(str, h->data[ind]);
    return 1;
}

int search(HasTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clearnode(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    free(q);
    return ;
}

void clearhashtable(HasTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        clearnode(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    #define max_n 100
    char str[max_n + 5];
    HasTable *h = inithastable(max_n + 5);
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0:
                printf("insert %s to HasTable\n", str);
                insert(h, str);
                break;
            case 1:
                printf("search %s from HasTable = %d\n", str, search(h, str));
                break;
        }
    }
    clearhashtable(h);
    return 0;
}
