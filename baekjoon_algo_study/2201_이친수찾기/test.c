#include <stdio.h>
#define MAX 1000

int binaryArray[MAX][MAX] = {0};
int DP[MAX] = {0};
void getBinary(int n);
int getMaxIdx(int* arr);
void binaryFunc(int n);
int binaryCount(int n);

int main() {
    binaryArray[0][0] = 0b1;
    binaryArray[1][0] = 0b10;

    for(int i=2; i<MAX; i++) {
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

    int cnt = 0;
    int loop = 0;
    int input;
    scanf("%d", &input);

    // 찾자
    int i=0;
	while(loop != 1 && i < MAX) {
        for(int j=0; j<MAX; j++) {
            if (binaryArray[i][j] == 0)
                break;
            cnt++;
            if (cnt == input) {
                binaryFunc(binaryArray[i][j]);
                loop = 1;
            }
        }
        i++;
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
    unsigned short int target = (n&0xFFFFFFFF);
    char find = 0;
	int str_idx = 0;

	for(int i=32; i>-1; i--) {
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