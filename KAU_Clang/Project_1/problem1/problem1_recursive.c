#include <stdio.h>

int d[100] = {0};

int fibo(int a, int b, int c, int n) {
    if (n == 1) 
        return a;
    if (n == 2)
        return b;
    if (n == 3)
        return c;
    if (d[n] != 0)
        return d[n];
    
    return d[n] = fibo(a, b, c, n - 1) + fibo(a, b, c, n - 3);
}

int main() {
    int a, b, c, N;

    printf("제 1항(a), 제 2항(b), 제 3항(c), 항의 수(N)을 입력하시오: ");
    scanf("%d %d %d %d", &a, &b, &c, &N);

    printf("%d\n", fibo(a, b, c, N));

    return 0;
}