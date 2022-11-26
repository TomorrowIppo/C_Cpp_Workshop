#include <stdio.h>
#define MAX 301

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int dp[MAX];
int stair[MAX];
int t;

int main() {
    scanf("%d", &t);
    int point;
    for(int i=1; i<=t; i++) {
        scanf("%d", &point);
        stair[i] = point;
    }

    dp[1] = stair[1];
    dp[2] = max((stair[1] + stair[2]), stair[2]);
    dp[3] = max((stair[2] + stair[3]), (stair[1] + stair[3]));

    for(int i=4; i<=t; i++) {
        dp[i] = max((stair[i] + stair[i-1] + dp[i-3]), (stair[i] + dp[i-2])); 
    }

    //확인용
    // for(int i=0; i<=t; i++) {
    //     printf("i : %d // %d\n", i, dp[i]);
    // }

    printf("%d\n", dp[t]);

    return 0;
}