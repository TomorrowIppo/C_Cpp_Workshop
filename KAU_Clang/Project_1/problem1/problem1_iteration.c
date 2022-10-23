#include <stdio.h>

int main() 
{ 
    int a, b, c, d, N;

    printf("제 1항(a), 제 2항(b), 제 3항(c), 항의 수(N)을 입력하시오: ");
    scanf("%d %d %d %d", &a, &b, &c, &N);
    d = c + a;

    int i = 1;
    printf("i : %2d) a : %4d, b : %4d, c : %4d, d : %4d\n", i, a, b, c, d);
    for(i = 2; i <= N-3; i++) {
        a = b;
        b = c;
        c = d;
        d = c + a;
        printf("i : %2d) a : %4d, b : %4d, c : %4d, d : %4d\n", i, a, b, c, d);
    }
    printf("%d\n", d);

    return 0;
}