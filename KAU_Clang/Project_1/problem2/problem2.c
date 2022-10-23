#include <stdio.h>
#include <stdlib.h>

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

    printf("품목\t  가격\t 갯수\t  금액\t\n");
    printf("세트\t %5d\t %2d\t %5d\t\n", set[0], set[1], set[2]);
    total += set[2];
    
    int i;
    for(i=0; i<3; i++) {
        if(i == set[3])
            continue;
        int temp_price = price[i] * (product_num[i] - set[1]);
        printf("%s\t %5d\t %2d\t %5d\t\n", product[i], price[i], product_num[i] - set[1], temp_price);
        total += temp_price;
    }
    printf("--------------------------------\n");
    printf("총 지불 금액           %7d\n", total);

}

int* get_setArray(int coffee, int cake, int sandwich) {
    int temp[3] = {coffee, cake, sandwich};

    int min = temp[0];
    int i;
    int min_idx = 0;
    for(i=1; i<3; i++) {
        if(min > temp[i]) {
            min = temp[i];
            min_idx = i;
        }
    }

    int *set = (int*)malloc(4);
    set[0] = 12000;
    set[1] = min;
    set[2] = 12000*min;
    set[3] = min_idx;

    return set;
}