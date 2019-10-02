// 練習問題1.2

#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    unsigned long long ans;
    ans = 1;

    for (int i = 1; i <= N; i++){
        ans *= i;
    }
    printf("%lld\n", ans);

    return 0;
}