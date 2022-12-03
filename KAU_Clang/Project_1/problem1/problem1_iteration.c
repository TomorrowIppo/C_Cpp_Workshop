#include <stdio.h>

int main(void)
{
    /* 변수 선언 부분: 수정하지 마세요 */
    int a, b, c, n; // 제 1항, 제 2항, 제 3항, 항의 수
    int output;  // 출력하고자 하는 값(제 n항)을 output 변수에 저장하세요.
    /* ------------------------------ */

    /* 입력 부분: 수정하지 마세요 */
    printf("제 1항(a), 제 2항(b), 제 3항(c), 항의 수(N)을 입력하세요:\n");
    scanf("%d%d%d%d",&a,&b,&c,&n);
    /* ---------------------------*/

    int origin_a = a;
    int origin_b = b;
    int origin_c = c;

    int i;
    for(i = 1; i <= n-3; i++) {
        output = c + a;
        a = b;
        b = c;
        c = output;
    }

    if(n==1)
        output = origin_a;
    if(n==2)
        output = origin_b;
    if(n==3)
        output = origin_c;


    /* 출력 부분: 수정하지 마세요 */  
    printf("%d항: %d",n,output);
	/* -------------------------- */ 

    return 0;
}
