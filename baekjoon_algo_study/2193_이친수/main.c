#include <stdio.h>
#define MAX 91

long long DP[MAX] = {0};
long long binaryCount(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", binaryCount(n));

    return 0;
}

long long binaryCount(int n) {
    if(n == 1) 
        return 1;
    if(n == 2)
        return 1;
    if(DP[n] != 0)
        return DP[n];
    
    return DP[n] = binaryCount(n - 1) + binaryCount(n - 2);
}
