#include <stdio.h>
#define MAX 91

long long dp[MAX][2];
long long countdp[MAX] = {1, 1, };

long long count_pinary(int k);

int main() {
    dp[1][0] = 0;
    dp[1][1] = 1;

    int k;
    scanf("%d", &k);

    //printf("k : %lld", count_pinary(k));

    return 0;
}

long long count_pinary(int k) {
    if(k==1) return 1;
    if(k==2) return 1;
    if(countdp[k] != 0) return countdp[k];

    return countdp[k] = count_pinary(k-1) + count_pinary(k-2);
}