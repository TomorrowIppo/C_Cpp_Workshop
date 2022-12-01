#include <stdio.h>
#define MAX 1001

int n;
int dp[MAX];

int main() {
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    printf("%d\n", dp[n]);

    return 0;
}
