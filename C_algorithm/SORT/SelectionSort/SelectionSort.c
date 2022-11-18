#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PRINT 1
#define MAX 1000

// 선택정렬(Selection Sort) : 가장 작은 것을 선택해서 제일 앞으로 보내는 알고리즘
// 시간복잡도 
// O(N(N+1)/2) => O(N^2)
// 비효율적인 알고리즘

int main() {
    int i, j, min, idx, temp;
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

    // 선택정렬
    clock_t start = clock();
    for(i=0; i<MAX; i++) {
        min = MAX * MAX;        // arr 배열 내에 존재하는 원소들보다 훨씬 더 큰 임의의 수
        for(j=i; j<MAX; j++) {
            if(min > arr[j]) {
                min = arr[j];
                idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }
    clock_t end = clock();

    // 출력
    if(PRINT)
        for(i=0; i<MAX; i++) {
            printf("%d ", arr[i]);
        }
    printf("\n선택정렬 time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);


    return 0;
}