/*************************************************************************
	> File Name: BinaryTree.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时58分04秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getnewnode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *gettree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insert(Node *node, int val, int *ret) {
    if (node == NULL) {
        *ret = 1;
        return getnewnode(val);
    }
    if (node->data == val) return node;
    if (val < node->data) node->lchild = insert(node->lchild, val, ret);
    else node->rchild = insert(node->rchild, val, ret);
    return node;
}

void insert1(Tree *tree, int val) {
    int flag = 0;
    tree->root = insert(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void outputNode(Node *root) {
    if (root == NULL) return ;
    printf("%d", root->data);
    if (!root->lchild && !root->rchild) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    printf("tree(%d) :", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

void preordernode(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->data);
    preordernode(root->lchild);
    preordernode(root->rchild);
    return ;
}

void preorder(Tree *tree) {
    printf("pre_order :");
    preordernode(tree->root);
    printf("\n");
    return ;
}
void inordernode(Node *root) {
    if (root == NULL) return ;
    inordernode(root->lchild);
    printf("%d ", root->data);
    inordernode(root->rchild);
    return ;
}

void inorder(Tree *tree) {
    printf("in_order :");
    inordernode(tree->root);
    printf("\n");
    return ;
}

void postordernode(Node *root) {
    if (root == NULL) return ;
    postordernode(root->lchild);
    postordernode(root->rchild);
    printf("%d ", root->data);
    return ;
}

void postorder(Tree *tree) {
    printf("post_order :");
    postordernode(tree->root);
    printf("\n");
    return ;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return ;
}
void clear_tree(Tree *tree) {
    if (tree == NULL) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 10
    Tree *tree = gettree();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert1(tree, val);
        output(tree);
    }
    preorder(tree);
    inorder(tree);
    postorder(tree);
    clear_tree(tree);
    return 0;
}
