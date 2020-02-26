/*************************************************************************
	> File Name: Vector.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 12时20分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int length, size;
} Vector;

void init(Vector *v, int size) {
    v->data = (int *)malloc(sizeof(int) * size);
    v->size = size;
    v->length = 0;
}

void expand(Vector *v) {
    int *old = v->data;
    v->size *= 2;
    v->data = (int *)malloc(sizeof(int) * v->size);
    for (int i = 0; i < v->length; i++) {
        v->data[i] = old[i];
    }
    free(old);
}

int insert(Vector *v, int loc, int val) {
    if (loc < 0 || loc > v->length) return 0;
    if (v->length >= v->size) expand(v);
    for (int i = v->length; i > loc; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[loc] = val;
    v->length++;
    return 1;
}

int delete1(Vector *v, int loc) {
    if (v->length == 0) return 0;
    if (loc < 0 || loc >= v->length) return 0;
    for (int i = loc + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length--;
    return 1;
}

int reaserch(Vector *v, int val) {
    if (v->length == 0) return 0;
    for (int i = 0; i < v->length; i++) {
