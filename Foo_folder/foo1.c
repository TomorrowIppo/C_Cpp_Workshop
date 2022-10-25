#include <stdio.h>

int main() {
    int i;
    int sum = 0;
    for(i=1; i<101; i++) {
        sum += i;
        if(i>50)
            printf("%d\n", i);
        if(i==100)
            printf("%d\n", sum);
    }

    return 0;
}