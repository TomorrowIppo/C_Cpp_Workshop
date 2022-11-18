#include <stdio.h>
// idx와 kg을 맞추기 위해서.
#define MAX 5001
int arr[MAX];

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

int dp(int n);

int main() {
    int n;
    scanf("%d", &n);

    // 배열을 -1로 초기화
    for(int i=0; i<=5; i++) {
        if(i==3 || i==5) {
            arr[i] = 1;
            continue;
        }
        arr[i] = -1;
    }

    for(int i=6; i<=n; i++) {
        if(arr[i-3] == -1 || arr[i-5] == -1) {
            arr[i] = 1 + max(arr[i-3], arr[i-5]);
            if(arr[i] == 0)
                arr[i] = -1;
            continue;
        }
        
        arr[i] = 1 + min(arr[i-3], arr[i-5]);
    }

    printf("%d\n", arr[n]);
    
    return 0;
}

