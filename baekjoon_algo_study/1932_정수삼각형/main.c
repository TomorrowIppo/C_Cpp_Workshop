#include <stdio.h>
#define MAX 500

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int n;
int dp[MAX][MAX];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<=i; j++) 
            scanf("%d", &dp[i][j]);
        
    for(int i=n-1; i>=1; i--)
        for(int j=0; j<i; j++)
            dp[i-1][j] += max(dp[i][j], dp[i][j+1]);

    printf("%d\n", dp[0][0]);

    return 0;
}