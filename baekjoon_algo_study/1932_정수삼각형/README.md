# 백준 1932 정수 삼각형 (C)

이 문제는 맨 꼭대기 (idx기준 (0, 0))에서부터 아래로 내려가면서 누적합을 구해도 되지만 맨 아래에서부터 누적합을 구하는 것이 최종적으로 값을 출력할 때 편하기 때문에 후자 방법을 택하여 문제를 해결했다.
그렇게 되면 배열 dp기준 dp[0][0]은 각 경로에서 가장 큰 수를 누적해온 결과인 dp[1][0], dp[1][1] 중 하나를 골라 더해주면 되기 때문에 최종적인 값을 출력할 땐 dp[0][0]을 출력함으로써 간단히 해결할 수 있다.

[Main Code]
``` c
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
```