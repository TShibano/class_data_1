#include <stdio.h>

// wasa関数の宣言
void WaSa(int *a, int *b);

int main(void){
    int a, b;

    printf("2つの整数を入力してください．\n");
    scanf("%d", &a);
    scanf("%d", &b);

    WaSa(&a, &b);

    printf("和：%d, 差：%d\n", a, b);

    return 0;
}

void WaSa(int *a, int *b){
    int tmp_a, tmp_b;
    tmp_a = *a;
    tmp_b = *b;

    *a = tmp_a + tmp_b;
    *b = tmp_a - tmp_b;
}