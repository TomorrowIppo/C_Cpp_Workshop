#include <stdio.h>

int binaryArray[1000] = {0};
void binaryFunc(int n);

int main() {

    return 0;
}

void binaryFunc(int n) {
    // 매개변수로 받아온 n을 16비트까지 표현하기 위해
    unsigned short int target = (n&0xFFFF);
    char find = 0;

	for(int i=15; i>-1; i--)
	{
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