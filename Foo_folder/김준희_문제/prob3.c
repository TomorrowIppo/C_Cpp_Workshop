#include <stdio.h>

// 함수 선언부분
void gugudan(int i);

int main() {
    int dan;
    printf("단값을 입력하시오. ");
    scanf_s("%d", &dan);
    gugudan(dan);
    return 0;
}

// 함수 정의부분
void gugudan(int i) {
    // 이건 문제가 잘못된게, 매개 변수를 int j로 하는 것이 아닌 int i로 해야 요구조건을 나타내는 코드랑 알맞게 돌아갈 수 있다.
    // 즉, 매개변수를 int j가 아닌 int i로 해야함. 문제에 오타 있다고 생각함
    int j;
    for(j=1; j<10; j++)
        printf("%d x %d = %d\n", i, j, i*j);
}