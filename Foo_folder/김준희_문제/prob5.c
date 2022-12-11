#include <stdio.h>

int even(int a, int b);

int main() {
    int a, b, result;
    printf("두수를 입력하시오.");
    scanf_s("%d %d", &a, &b);
    result = even(a, b);
    if(result == 0)
        printf("입력한 두수는 짝수가 아니다.");
    else   
        printf("입력한 두수는 모두 짝수이다.");

    return 0;
}

int even(int a, int b) {
    // 둘 다 짝수이면 2로 나눴을 때 나머지가 0이고, 짝수일 때 0이 아닌 임의의 수(보통 이분화 할 때 1로 함)를 골라 반환시켰다.
    if(a%2==0 && b%2==0)
        return 1;
    else
        return 0;
}