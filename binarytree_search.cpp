/*************************************************************************
	> File Name: binarytree_search.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时15分04秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getnode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getnode(key);
    if (root->key == key) return root;
    if (key < root->key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}

Node *predecessor(Node *node) {
    Node *temp = node->lchild;
    while (temp != NULL && temp->rchild != NULL) {
        temp = temp->rchild;
    }
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->lchild = erase(root->lchild, key);
    else if (key > root->key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NULL || root->rchild == NULL) {
            Node *temp = root->lchild ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    return root;
}

void _inorder(Node *node) {
    if (node == NULL) return ;
    _inorder(node->lchild);
    printf("%d ", node->key);
    _inorder(node->rchild);
    return ;
}

void inorder(Node *node) {
    printf("inorder : ");
    _inorder(node);
    printf("\n");
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

int main() {
    int op, val;
    Node *node = NULL;
    while (scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: node = insert(node, val); break;
            case 2: node = erase(node, val); break;
        }
        inorder(node);
    }
    clear(node);
    return 0;
}
