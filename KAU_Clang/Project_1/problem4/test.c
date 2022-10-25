#include <stdio.h>
#define MAX 1000

int MyFinalArray[MAX] = {0};
int binaryArray[MAX][MAX] = {0};
int DP[MAX] = {0};
void getBinary(int n);
int getMaxIdx(int* arr);
void binaryFunc(int n);
long long int binaryCount(int n);

int main() {
    int n;
    printf("N을 입력하세요:\n");
    scanf("%d", &n);

    binaryArray[0][0] = 0b1;
    binaryArray[1][0] = 0b10;

    for(int i=2; i<n; i++) {
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
    
    
    printf("%d자리 갯수: %lld\n", n, binaryCount(n));
    for(int i=0; i<getMaxIdx(binaryArray[n-1]); i++)
    { 
        //printf("%10lld", binaryArray[n-1][i]);
        binaryFunc(binaryArray[n-1][i]);
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
	for(int i=15; i>-1; i--) {
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

long long int binaryCount(int n) {

    if(n == 1) 
        return 1;
    if(n == 2)
        return 1;
    if(DP[n] != 0)
        return DP[n];
    
    return DP[n] = binaryCount(n - 1) + binaryCount(n - 2);
}
