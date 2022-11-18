#include <stdio.h>

int min(int a, int b, int c, int err);

int main() {
    int n;
    scanf("%d", &n);

    int arr[n+1];
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for(int i=4; i<=n; i++) {
        int a = arr[i-1];
        int b = arr[i/3];
        int c = arr[i/2];
        
        arr[i] = min(a, b, c, i) + 1;
    }

    // 확인용
    for(int i=1; i<=n; i++) {
        printf("%5d : %2d | ", i, arr[i]);
        if(i%10 == 0)
            printf("\n");
    }
    
    // 제출용
    //printf("%d\n", arr[n]);

    return 0;
}

int min(int a, int b, int c, int i) {
    int num_min = a;
    if(num_min > b && i%3 == 0) 
        num_min = b;
    if(num_min > c && i%2 == 0)
        num_min = c;
    
    return num_min;
}