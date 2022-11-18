#include <stdio.h>
#define MAX 41

int fibo(int n, int *one_cnt, int *zero_cnt);
int arr[MAX] = {};

int main() {
    int n, t;
    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        int one_cnt = 0;
        int zero_cnt = 0;
        int result = fibo(n, &one_cnt, &zero_cnt);
        //printf("i : %2d | zero : %10d | one : %10d | result : %10d\n", i, zero_cnt, one_cnt, result);
        printf("%d %d\n", zero_cnt, one_cnt);
    }
    return 0;
}

int fibo(int n, int *one_cnt, int *zero_cnt) {
    if(n==0) {
        *zero_cnt += 1;
        return 0;
    }
    if(n==1) {
        *one_cnt += 1;
        return 1;
    }
    // if(arr[n] != 0)
    //     return arr[n];
    
    return arr[n] = fibo(n-1, one_cnt, zero_cnt) + fibo(n-2, one_cnt, zero_cnt);
}