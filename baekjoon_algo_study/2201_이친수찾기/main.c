#include <stdio.h>
#define MAX 91

long long k;
long long dp[MAX][2];
long long sum[MAX];

long long count_pinary(int k);

int main() {
    dp[1][0] = 0;
    dp[1][1] = 1;
    sum[1] = 1;

    scanf("%lld", &k);

    for(int i=2; i<MAX; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        sum[i] = sum[i-1] + dp[i][0] + dp[i][1];
    }
    
    if(k==1) {
        printf("1\n");
    } else {
        printf("1");
        // 몇자리인지 확인
        int n = 0;
        for(int i=2; i<MAX; i++) {
            if(k <= sum[i]) {
                n = i; 
                break;
            }
        }
        // 출력
        k -= (sum[n-1] + 1);
        n--;
        while(n>0) {
            if(k > sum[n-1]) {
                printf("1");
                k -= (sum[n-1] + 1);
            } else {
                printf("0");
            }
            n--;
        }
        printf("\n");
    }

    return 0;
}