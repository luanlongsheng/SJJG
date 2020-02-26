/*************************************************************************
	> File Name: Unstable_sort.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 13时04分14秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a)  __temp = a;\
    a = b; b = __temp;\
}

#define P(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s= ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[ind]) ind = j;
        }
        swap(num[i], num[ind]);
    }
}

void quick_sort(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("num(%d) = [", n);
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("]\n");
}

int main() {
    srand(time(0));
    #define max_op 20
    int arr[max_op];
    randint(arr, max_op);
    P(arr, max_op, select_sort, num, max_op);
    P(arr, max_op, quick_sort, num, 0, max_op - 1);
    return 0;
}
