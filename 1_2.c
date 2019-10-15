// 練習問題1.2

#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    // N <= 20で成立, N > 20でオーバーフロー
    unsigned long long ans;
    ans = 1;
    
    for (int i = 1; i <= N; i++){
        ans *= i;
    }
    printf("%lld\n", ans);

    return 0;
}