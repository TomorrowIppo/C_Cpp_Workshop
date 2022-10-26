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
    unsigned short int target = (n&0xFFFF);
    char find = 0;

    for(int i=15; i>-1; i--)
	{
        if(find == 0 && ((target>>i)&0x01) == 0)
		{
		}else{
			find = 1;
			printf("%d", ((target>>i)&0x01));
		}
	}
    printf("\n");
}