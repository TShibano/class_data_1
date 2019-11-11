// 練習問題1.2
// オーバーフローを改善
// https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1320627493
// を参考に作成


#include <stdio.h>
#define NN 10000    // 配列の要素数 (NN - 1)*4桁まで計算可能

int main(){
    int c[NN];      // 10000進数の各桁 c[0]は有効桁数 c[n]がn桁目
    int cal_num;    // 計算用
    int up_num;     // 繰り上がり
    int num;        // 入力値
    int i, j;       

    // 初期化
    for (i = 0; i < NN; i++){
        c[i] = 0;
    }
    c[0] = 1;
    c[1] = 1;       // 最初の数は1

    // 入力
    scanf("%d", &num);
    if (num < 0) return -1;

    // 計算
    for (i = 1; i <= num; i++){
        // 1桁の掛け算 c = c * iを計算する
        up_num = 0;        // 繰り上がりクリア

        for (j = 1; j <= c[0]; j++){
            cal_num = c[j] * i + up_num;
            c[j] = cal_num % 10000;         // 桁確定
            up_num = cal_num / 10000;       // 繰り上げ
        }
        if (up_num > 0){
            if (c[0] < NN - 1){             // 配列に余裕があれば桁を拡張
                c[j] = up_num;
                c[0]++;
            }else{                          // 配列に入りきらない場合はエラー
                printf("over flow\n");
                return -1;
            }
        }

    }
    printf("%d\n", i);
    printf("c[1]=");
    printf("%d\n", c[1]);

    // 出力
    i = c[0];
    printf("%d", c[i--]);       // 最初の数字
    for(; i>0; i--){
        printf("%04d", c[i]);   // 2番目以降
    }
    printf("\n");
    return 1;
}