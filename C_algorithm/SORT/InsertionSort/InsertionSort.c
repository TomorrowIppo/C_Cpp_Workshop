#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINT 0
#define MAX 1000

// 삽입정렬(InsertionSort) : 
// 시간복잡도 
// O(N(N+1)/2) => O(N^2)
// 비효율적인 알고리즘, 선택정렬과 같이 O(N^2)이지만, 버블정렬은 반복할 때마다 오른쪽의 원소와 swap을 계속하고 
// 선택정렬은 한번의 반복 때 한번의 swap만 있기 때문에 실제 수행시간은 버블정렬이 더 길다 이는 곧
// 버블정렬이 제일 쓰레기라는 것을 의미한다.

int main() {
    int i, j, temp;
    int arr[MAX];

    // 배열 만들기 (시드값 고정, 중복 없이)
    srand(1);
    for(i=0; i<MAX; i++){
        arr[i] = rand() % MAX + 1;
        for(j=0; j < i; j++) {
            if(arr[i] == arr[j]) {
                i--;
                break;
            }
        }
    }
    
    // 삽입정렬
    clock_t start = clock();
    for(i=0; i<MAX-1; i++) {
        j = i;
        while(arr[j] > arr[j+1]) {
            
        }
    }
    clock_t end = clock();
    
    //출력
    if(PRINT)
        for(i=0; i<MAX; i++) {
            printf("%d ", arr[i]);
        }
    printf("\n버블정렬 time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}