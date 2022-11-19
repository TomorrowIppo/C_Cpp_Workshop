#include <stdio.h>
#include <stdlib.h>
#define SET_EXIST 1
#define SET_NOT_EXIST 0
#define ALL_SAME -1

void print_price(int coffee, int cake, int sandwich);
int* get_setArray(int coffee, int cake, int sandwich);

int main() {
    int coffee, cake, sandwich;
    printf("주문하고자 하는 커피, 케잌, 샌드위치의 갯수를 각각 입력하세요:\n");
    scanf("%d %d %d", &coffee, &cake, &sandwich);

    print_price(coffee, cake, sandwich);

    return 0;
}

void print_price(int coffee, int cake, int sandwich) {
    int total = 0;
    int* set = get_setArray(coffee, cake, sandwich);
    int price[3] = {4000, 5000, 6000};
    int product_num[3] = {coffee, cake, sandwich};
    char* product[3] = {"커피", "케잌", "샌드위치"};

    printf("%-10s\t %s\t %s\t %s\t\n", "품목", "가격", "갯수", "금액");

    // set가 존재할 경우
    if(set[4] == SET_EXIST) {
        printf("%-8s\t %-5d\t %-2d\t %-5d\t\n", "세트", set[0], set[1], set[2]);
        total += set[2];
    }
    
    // 수량이 모두 같지 않을 때
    int i;
    if(set[4] != ALL_SAME)
        for(i=0; i<3; i++) {
            if(i == set[3] && set[4] != SET_NOT_EXIST)
                continue;
            int temp_price = price[i] * (product_num[i] - set[1]);
            printf("%-8s\t %-5d\t %-2d\t %-5d\t\n", product[i], price[i], product_num[i] - set[1], temp_price);
            total += temp_price;
        }
    printf("-------------------------------------------\n");
    printf("총 지불 금액\t\t\t %-7d\n", total);
}

int* get_setArray(int coffee, int cake, int sandwich) {
    int temp[3] = {coffee, cake, sandwich};
    int *set = (int*)malloc(5);    
    int min = temp[0];

    // 수량 중 0이 하나라도 있을 때
    if(min == 0) {
        set[1] = 0;
        set[4] = SET_NOT_EXIST;
        return set;
    }

    int i;
    int min_idx = 0;
    for(i=1; i<3; i++) {
        // 수량 중 0이 하나라도 있을 때
        if(temp[i] == 0) {
            set[1] = 0;
            set[4] = SET_NOT_EXIST;
            return set;
        }

        if(min > temp[i]) {
            min = temp[i];
            min_idx = i;
        }
    }

    set[0] = 12000;         // 세트가격
    set[1] = min;           // 주문 수량 제일 적은 수 = 세트 수
    set[2] = 12000*min;     // 세트 총 가격
    set[3] = min_idx;       // 주문 수량 제일 적은 것의 인덱스

    // 세트로 묶이는지 여부
    // SET_EXIST : 세트 존재, SET_NOT_EXIST : 세트 존재 x, ALL_SAME : 수량이 같음
    if(temp[0] == temp[1] && temp[0] == temp[2])
        set[4] = ALL_SAME;    // 모두 수량이 같을 때
    else
        set[4] = SET_EXIST;        

    return set;
}