#include <stdio.h>

int main() 
{ 
    int a, b, c, d, N, i;

    printf("제 1항(a), 제 2항(b), 제 3항(c), 항의 수(N)을 입력하시오:\n");
    scanf("%d %d %d %d", &a, &b, &c, &N);
    for(i = 1; i <= N-3; i++) {
        d = c + a;
        a = b;
        b = c;
        c = d;
    }
    printf("%d항: %d\n", N, d);

    return 0;
}