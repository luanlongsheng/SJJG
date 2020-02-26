/*************************************************************************
	> File Name: Stable_sort.cpp
	> Author:lls 
	> Mail:luanlongshengv@163.com 
	> Created Time: 2020年02月26日 星期三 13时01分35秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
    free(num);\
}

#define swap(a, b) {\
    a ^= b; b ^= a; a ^= b;\
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (num[j] < num[j - 1]) swap(num[j], num[j - 1]);
        }
    }
}

void bubble_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                flag = 0;
            }
        }
        if (flag) break;
    }
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r -l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int x = l, y = mid + 1, k = 0;
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    while (x <= mid || y <= r) {
        if (y > r || (x <= mid && num[x] <= num[y])) {
            temp[k++] = num[x++];
        } else {
           temp[k++] = num[y++]; 
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
}

void output(int *num, int n) {
    printf("num(%d) = [", n);
    for (int i = 0; i < n; i ++) {
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
    TEST(arr, max_op, insert_sort, num, max_op);
    TEST(arr, max_op, bubble_sort, num, max_op);
    TEST(arr, max_op, merge_sort, num, 0, max_op - 1);
    return 0;
}
