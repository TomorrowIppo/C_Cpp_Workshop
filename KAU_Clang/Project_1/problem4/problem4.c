#include <stdio.h>
#define MAX 1000

int MyFinalArray[MAX] = {0};
int binaryArray[MAX][MAX] = {0};
int DP[MAX] = {0};
void getBinary(int n);
int getMaxIdx(int* arr);
void binaryFunc(int n);
int binaryCount(int n);

int main() {
    /* 변수 선언 부분: 수정하지 마세요 */
	int N; // N자리 이진수
    /* ------------------------------- */

    /* 입력 부분: 수정하지 마세요 */
    printf("N을 입력하세요:\n");
    scanf("%d",&N);
    /* -------------------------- */

    //출력 형식은 printf(“%d자리 갯수: %d\n”, 해당하는 변수, 해당하는 변수); 를 이용해주세요.
    // 함수 내 출력 또는 main에서 출력 등 자유롭게 작성 가능

    binaryArray[0][0] = 0b1;
    binaryArray[1][0] = 0b10;

    for(int i=2; i<N; i++) {
        int root = 1 << i;
        int idx_1 = getMaxIdx(binaryArray[i-1]);
        int idx_2 = getMaxIdx(binaryArray[i-2]);
        int new_idx = getMaxIdx(binaryArray[i]);
        
        for(int j=0; j<idx_1; j++)
            binaryArray[i][j] = root + (binaryArray[i-1][j] ^ (1 << (i-1)));
        
        new_idx = getMaxIdx(binaryArray[i]);

        for(int j=0; j<idx_2; j++)
            binaryArray[i][j+new_idx] = root + binaryArray[i-2][j];
    }

    // 문제 조건에 맞는 배열 만들기
	int pinary_cnt = binaryCount(N);
	MyFinalArray[0] = pinary_cnt;
	for(int i=1; i<=pinary_cnt; i++)
		MyFinalArray[i] = binaryArray[N-1][i-1];
    
    
    printf("%d자리 갯수: %d\n", N, MyFinalArray[0]);
    for(int i=0; i<getMaxIdx(binaryArray[N-1]); i++) {	        
        if(i % 10 == 0 && i != 0)
			printf("\n"); 
        binaryFunc(MyFinalArray[i+1]);
    }
    printf("\n");

    return 0;
}

int getMaxIdx(int* arr) {
    int idx = 0;
    for(int i=0; i<MAX; i++)
        if(arr[i] == 0 && arr[i+1] == 0) {
            idx = i;
            break;
        }
    return idx;
}

void binaryFunc(int n) {
    unsigned short int target = (n&0xFFFF);
    char find = 0;
	int str_idx = 0;

	for(int i=15; i>-1; i--) {
		if(find == 0 && ((target>>i)&0x01) == 0)
		{
			//printf(" x");
		}else{
			find = 1;
			printf("%d", ((target>>i)&0x01));
		}
	}
    printf(" ");
}

int binaryCount(int n) {
    if(n == 1) 
        return 1;
    if(n == 2)
        return 1;
    if(DP[n] != 0)
        return DP[n];
    
    return DP[n] = binaryCount(n - 1) + binaryCount(n - 2);
}
