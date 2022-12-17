#include <stdio.h>
#include <string.h>

/* 변수 선언 부분: 수정하지 마세요 */
#define price_americano 3500
#define price_icetea 3000
#define price_smoothie 5000
#define price_carrot 7000
#define price_cheese 6000
#define price_choco 5500
/* ------------------------------ */

int min(int a, int b) {
    if(a == 0 || b == 0)
         return 0;
    if (a>=b)
        return b;
    else   
        return a;
}

int main(){
    /* 변수 선언 부분: 수정하지 마세요 */
    int num_americano;
    int num_icetea;
    int num_smoothie;
    int num_carrot;
    int num_cheese;
    int num_choco;
    int num_set1;
    int num_set2;
    int total_price_set1;
    int total_price_set2;
    int total_price;
    /* ------------------------------ */

    // 반드시 다음 코드 사용해서 출력하세요. 
    // 주문 받을 때: printf("주문하고자 하는 음료(커피, 아이스티, 스무디)와 케잌(당근, 치즈, 초코)의 갯수를 각각 입력하세요:\n"); 이용하여 출력
    // 음료 갯수가 10개 넘었을 때: printf("음료 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n"); 이용하여 출력
    // 케잌 갯수가 10개 넘었을 때: printf("케잌 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n"); 이용하여 출력
    
    /*put your answer*/
    total_price_set1 = 0;
    total_price_set2 = 0;
    total_price = 0;

    int total_bev;
    int total_cake;
    while(1) {
        printf("주문하고자 하는 음료(커피, 아이스티, 스무디)와 케잌(당근, 치즈, 초코)의 갯수를 각각 입력하세요:\n");
        scanf("%d %d %d %d %d %d", &num_americano, &num_icetea, &num_smoothie, &num_carrot, &num_cheese, &num_choco);

        total_bev = num_americano + num_icetea + num_smoothie;
        total_cake = num_carrot + num_cheese + num_choco;

        if(total_bev > 10) {
            printf("음료 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n");
            continue;
        }
        if(total_cake > 10) {
            printf("케잌 갯수가 10개를 넘었습니다. 다시 주문해주세요.\n\n");
            continue;
        }

        break;
    }
    // 가격이 비싼 순으로 먼저 넣음
    int* bev_arr[3] = {&num_smoothie, &num_americano, &num_icetea};
    int bev_price_arr[3] = {price_smoothie, price_americano, price_icetea};

    int* cake_arr[3] = {&num_carrot, &num_cheese, &num_choco};
    int cake_price_arr[3] = {price_carrot, price_cheese, price_choco};

    int bev_cnt = total_bev;
    int cake_cnt = total_cake;
    
    // 세트1이 만들어지는 경우
    num_set1 = min(bev_cnt/2, cake_cnt/2);
    //printf("num_set1 : %d\n", num_set1);
    if(num_set1 >= 1) { 
        bev_cnt -= num_set1 * 2;
        cake_cnt -= num_set1 * 2;

        int bev = num_set1 * 2;
        for(int i=0; i<3; i++) {
            bev -= *bev_arr[i];

            if(bev <= 0) {
                total_price_set1 += ((*bev_arr[i] + bev) * bev_price_arr[i]);
                *bev_arr[i] = -1 * bev;
            } else {
                total_price_set1 += (*bev_arr[i] * bev_price_arr[i]);
                *bev_arr[i] = 0;
            }
        }

        int cake = num_set1 * 2;
        for(int i=0; i<3; i++) {
            cake -= *cake_arr[i];

            if(cake <= 0) {
                total_price_set1 += ((*cake_arr[i] + cake) * cake_price_arr[i]);
                *cake_arr[i] = -1 * cake;
            } else {
                total_price_set1 += (*cake_arr[i] * cake_price_arr[i]);
                *cake_arr[i] = 0;
            }
        }

        total_price_set1 = total_price_set1 * 0.8;
    }

    // 세트2가 만들어지는 경우
    num_set2 = min(bev_cnt/2, cake_cnt);
    if(num_set2 >= 1) { 
        bev_cnt -= num_set2 * 2;
        cake_cnt -= num_set2 * 2;

        int bev = num_set2 * 2;
        for(int i=0; i<3; i++) {
            bev -= *bev_arr[i];

            if(bev <= 0) {
                total_price_set2 += ((*bev_arr[i] + bev) * bev_price_arr[i]);
                *bev_arr[i] = -1 * bev;
            } else {
                total_price_set2 += (*bev_arr[i] * bev_price_arr[i]);
                *bev_arr[i] = 0;
            }
        }

        int cake = num_set2;
        for(int i=0; i<3; i++) {
            cake -= *cake_arr[i];

            if(cake <= 0) {
                total_price_set2 += ((*cake_arr[i] + cake) * cake_price_arr[i]);
                *cake_arr[i] = -1 * cake;
            } else {
                total_price_set2 += (*cake_arr[i] * cake_price_arr[i]);
                *cake_arr[i] = 0;
            }
        }

        total_price_set2 = total_price_set2 * 0.9;
    }

    total_price = total_price_set1 + total_price_set2 + price_americano * num_americano + price_icetea * num_icetea + 
    price_smoothie * num_smoothie + price_carrot * num_carrot + price_cheese * num_cheese + price_choco * num_choco;

    /* 출력 부분: 수정하지 마세요 */ 
    printf("\n품목      갯수   금액\n");
    if (num_set1 > 0)
        printf("세트1    %4d %7d\n",num_set1, total_price_set1);
    if (num_set2 > 0)
        printf("세트2    %4d %7d\n", num_set2, total_price_set2);
    if (num_americano > 0)
        printf("커피     %4d %7d\n", num_americano, price_americano * num_americano);
    if (num_icetea > 0)
        printf("아이스티 %4d %7d\n", num_icetea, price_icetea * num_icetea);
    if (num_smoothie > 0)
        printf("스무디   %4d %7d\n", num_smoothie, price_smoothie * num_smoothie);
    if (num_carrot > 0)
        printf("당근케잌 %4d %7d\n", num_carrot, price_carrot * num_carrot);
    if (num_cheese > 0)
        printf("치즈케잌 %4d %7d\n", num_cheese, price_cheese * num_cheese);
    if (num_choco > 0)
        printf("초코케잌 %4d %7d\n", num_choco, price_choco * num_choco);
    printf("----------------------------\n");
    printf("총 지불 금액 %8d\n", total_price);
    /* ------------------------- */

    return 0;

}