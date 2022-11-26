#include <stdio.h>
#define MAX 1001

int dp[MAX][3];
int t;

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


int main() {
    scanf("%d", &t);
    int r, g, b;
    for(int i=1; i<=t; i++) {
        scanf("%d%d%d", &r, &g, &b);
        
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r;
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g;
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b;
    }

    printf("%d\n", min(dp[t][0], min(dp[t][1], dp[t][2])));

    return 0;
}