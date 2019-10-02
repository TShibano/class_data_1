#include <stdio.h>

int main(void){
    int N;

    scanf("%d", &N);
    switch (N)
    {
    case 1:
        printf("One.\n");
        break;
    case 2:
        printf("Two.\n");
        break;
    default:
        printf("It is neither one nor two.\n");
        break;
    }
    return 0;
}