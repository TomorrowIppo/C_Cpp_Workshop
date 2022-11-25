#include <stdio.h>
#define MAX 12

int t;
int k;
int dp[MAX] = {0, 1, 2, 4 };

int main() {
    scanf("%d", &t);

    for(int i=4; i<MAX; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    // 확인용
    // for(int i=1; i<MAX; i++) {
    //     printf("%4d ", dp[i]);
    //     if(i != 0 && i % 10 == 0)
    //         printf("\n");
    // }

    for(int i=0; i<t; i++) {
        scanf("%d", &k);
        printf("%d\n", dp[k]);
    }

    return 0;
}