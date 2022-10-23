#include <stdio.h>
#include <stdlib.h>

void DiceGame();
//전역 변수 선언
int x_point = 0;
int y_point = 0;

int main()
{
	int i;

	for(i=1;i<=3;i++)
	{
		DiceGame();
	}
		
	printf("\nx 누적점수: %d, y 누적점수: %d\n",x_point, y_point); 

	if(x_point > y_point)
		printf("x 사용자 승!\n");
	else if(x_point < y_point)
		printf("y 사용자 승!\n");
	else
		printf("x,y 사용자 동점!\n");

	return 0;
}


void DiceGame()
{
	int x, y;

	//x, y 주사위 점수 입력
	do{
        printf("x, y 주사위 숫자를 입력하세요:\n");
		scanf("%d %d", &x, &y);
	}while((x < 1 || x > 6) || (y < 1 || y > 6)); //x,y모두 1~6사이의 값이 들어오면 do while문 종료

	printf("x: %d, y: %d\n",x, y); 

    //누적 점수 계산
    x_point += x;
    y_point += y;
}
