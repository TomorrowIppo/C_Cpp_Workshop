#include <stdio.h>

int main() {
    int n;
    int arr[3] = {1, 2, 3};

    int site;
    scanf("%d", &site);

    for(int i=site; i<2; i++) {
        arr[i] = arr[i+1];
    }

    for(int i=0; i<2; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}