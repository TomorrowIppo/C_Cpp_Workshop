#include <stdio.h>

int main(void)
{
    /* ?? ?? ??: ???? ??? */
    int price_coffee = 4000; // ??, ??, ???? ??
    int price_cake = 5000;
    int price_sandwich = 6000;
    int price_set = 12000;
    int num_coffee; // ??, ??, ???? ?? ??
    int num_cake;
    int num_sandwich;
    int num_set;
    int total_price; // ?? ??
    /* ------------------------------ */

    /* ?? ??: ???? ??? */
    printf("????? ?? ??, ??, ????? ??? ?? ?????:\n");
    scanf("%d%d%d",&num_coffee,&num_cake,&num_sandwich);
    /* -------------------------- */

    int temp[3] = {num_coffee, num_cake, num_sandwich};
    int i;
    int min = temp[0];

    // ?? ?? ? 0? ??? min? 0? ??? ???? ???? ????,
    // ???? min? ??? 0? ?? ???? ?? ??.
    for(i=0; i<3; i++) {
        if(min > temp[i])
            min = temp[i];

        if (temp[i] == 0)
            break;
    }

    num_set = min;
    num_coffee -= num_set;
    num_cake -= num_set;
    num_sandwich -= num_set;
    total_price = (price_set * num_set) + (price_coffee * num_coffee) + (price_cake * num_cake) + (price_sandwich * num_sandwich);

    /* ?? ??: ???? ??? */
    printf("??      ??  ??   ??\n");
    if (num_set > 0)
        printf("?? %9d %4d %7d\n", price_set, num_set, price_set * num_set);
    if (num_coffee > 0)
        printf("?? %9d %4d %7d\n", price_coffee, num_coffee, price_coffee * num_coffee);
    if (num_cake > 0)
        printf("?? %9d %4d %7d\n", price_cake, num_cake, price_cake * num_cake);
    if (num_sandwich > 0)
        printf("???? %5d %4d %7d\n", price_sandwich, num_sandwich, price_sandwich * num_sandwich);
    printf("----------------------------\n");
    printf("? ?? ?? %14d", total_price);
    /* ------------------------- */

    return 0;
}