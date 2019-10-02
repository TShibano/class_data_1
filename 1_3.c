#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    printf("\n");   /*答えと入力を一行あける*/
    while(N >= 0){
        printf("%d\n", N);
        N--;
    }
    return 0;
}