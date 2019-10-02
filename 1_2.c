// 練習問題1.2

#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    double ans;
    ans = 1;

    for (long long int i = 1; i <= N; i++){
        ans *= i;
    }
    printf("%0f\n", ans);

    return 0;
}