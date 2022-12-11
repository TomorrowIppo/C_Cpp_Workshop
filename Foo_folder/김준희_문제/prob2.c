#include <stdio.h>

int main() {
    int mon[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int input;

    while(1) {
        printf("원하는 달을 입력하시오 : 종료 0 입력 : ");
        scanf("%d", &input);
        // 0이 입력되면 종료
        if(input == 0)
            break;

        // mon[] 배열에 값을 저장할 때 n월달의 일(day)를 구하려면 인덱스 기준 n-1의 값을 통해 접근해야함
        printf("%d월은 %d일입니다.\n", input, mon[input-1]);
    }

    return 0;
}