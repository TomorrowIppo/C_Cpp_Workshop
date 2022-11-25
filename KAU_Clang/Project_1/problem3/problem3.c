#include <stdio.h>
void binaryFunc(int n);

int main()
{
    /* 변수 선언 부분: 수정하지 마세요 */
	int n; // 이진수로 변환하고자 하는 십진수
    /* ------------------------------- */

    /* 입력 부분: 수정하지 마세요 */
    printf("2진수로 출력하고자 하는 수를 입력하세요:\n");
    scanf("%d",&n);
    /* -------------------------- */


    /* 출력 부분: 수정하지 마세요 */
    printf("이진수 출력: ");
	binaryFunc(n);
    /* -------------------------- */
	
  return 0;
}

void binaryFunc(int n) {
    unsigned short int target = (n&0xFFFF);
    char find = 0;

    for(int i=15; i>-1; i--)
	{
        if(find == 0 && ((target>>i)&0b01) == 0)
		{
		}else{
			find = 1;
			printf("%d", ((target>>i)&0b01));
		}
	}
    printf("\n");
}