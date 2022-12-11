#include <stdio.h>

// 배열 출력용 함수
void print_arr(int arr[3][3]);

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {7, 8, 9},
        {13, 14, 15}
    };

    int b[3][3] = {
        {4, 5, 6},
        {10, 11, 12},
        {16, 17, 18}
    };

    // 빈 배열 선언
    int c[3][3] = {};

    // 배열 값 채워주기
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // 출력부분
    print_arr(a);
    printf("\n");
    printf("%6c", '+');
    printf("\n\n");
    print_arr(b);
    printf("\n");
    printf("%6c", '=');
    printf("\n\n");
    print_arr(c);
    
    return 0;
}

void print_arr(int arr[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
}