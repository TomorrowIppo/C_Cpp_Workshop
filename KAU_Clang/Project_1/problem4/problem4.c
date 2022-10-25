#include <stdio.h>

int binaryArray[1000] = {0};
long long int DP[1000] = {0,};

long long int binaryCount(int n);
long long int makeBinary(int init, int n);

int main() {
	int n = 0;
	printf("N을 입력하세요:\n");
	scanf("%d", &n);

	printf("%d자리 갯수: %lld\n", n, binaryCount(n));
	for(int i=0; i<n; i++) {
		printf("%10d", binaryArray[i]);
	}
	printf("\n");

	return 0;
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
