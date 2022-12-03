#include <stdio.h>
#define MAX 1000001

int n, m, i, j;
int arr[MAX];

int main() {
    scanf("%d%d", &n, &m);
    for(int s=1; s<=n; s++) {
        int temp;
        scanf("%d", &temp);
        arr[s] = temp;
    }

    for(int s=1; s<=n; s++) {
        arr[s] += arr[s-1];
        //printf("s : %d, arr : %d\n", s, arr[s]);
    }

    for(int s=0; s<m; s++) {
        scanf("%d%d", &i, &j);
        printf("%d\n", arr[j] - arr[i-1]);
    }

    return 0;
}