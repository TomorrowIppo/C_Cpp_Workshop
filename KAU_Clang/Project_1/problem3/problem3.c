#include <stdio.h>

void binaryFunc(int n);

int main() {
    int input_num;
    printf("값을 입력해주세요: ");
    scanf("%d", &input_num);

    binaryFunc(input_num);

    return 0;
}

void binaryFunc(int n) {
    // 매개변수로 받아온 n을 16비트까지 표현하기 위해
    unsigned short int target = (n&0xFFFF);
    char find = 0;

    // 작동 원리
    // 16비트의 데이터를 하나씩 끝으로 시프트 이동시키면 대충 이런 그림이 된다
    // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
    // 얘를 0x01과 & 연산을 하게 되면 결과는 십진수 기준 1이 나오고
    // 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    // 이때 0x01과 & 연산을 하게 되면 결과는 십진수 기준 0이 나온다.
    // 이 방식으로 계속 시프트 연산을 하면서 출력되는 십진수를 하나씩 나열하면 그것이 곧 n을 이진수로 표현한 데이터가 된다.
	for(int i=15; i>-1; i--)
	{
        // 연속되는 상위 비트가 나올 때 x로 표시하고 만약 1이 나오는 순간 그부분부터 의미가 있는 수이기에 find를 1로 설정하고
        // 그부분부터 제대로 출력하도록 한다.
		if(find == 0 && ((target>>i)&0x01) == 0)
		{
			//printf(" x");
		}else{
			find = 1;
			printf("%d", ((target>>i)&0x01));
		}
	}
    printf("\n");

}