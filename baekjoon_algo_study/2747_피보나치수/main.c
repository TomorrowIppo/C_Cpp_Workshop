#include <stdio.h>
#define MAX 45+1

int arr[MAX] = {};

int main() {
    int n;
    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;

    for(int i=3; i<=n; i++) {
        arr[i] = arr[i-2] + arr[i-1];
        //printf("i : %d // %d\n", i, arr[i]);
    }

    printf("%d\n", arr[n]);

    return 0;
}