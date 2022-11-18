#include <stdio.h>
#define FLOOR 15
#define UNIT 15

int person[FLOOR][UNIT] = {};

int main() {
    int t, k, n;

    // 0층 거주민 초기화
    for(int i=0; i<UNIT; i++) 
        person[0][i] = i;

    for(int i=1; i<FLOOR; i++) {
        for(int j=1; j<UNIT; j++) {
            person[i][j] = person[i-1][j] + person[i][j-1];
            //printf("i : %d, j : %d // %d\n", i, j, person[i][j]);
        }
    }

    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%d %d", &k, &n);
        printf("%d\n", person[k][n]);
    }
    
    return 0;
}