#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
    int a = 2;
    double b = 8;
    int ans = int(pow(a, b));
    printf("2^8 = %d\n", ans);


    double alpha = 67; // 角度(単位は°)
    double theta = M_PI * 67 / 180; // radに変換
    printf("sin(67°) = %lf\n", sin(theta));

    double c = -23.456;
    printf("|-23.456| = %.3lf\n", fabs(c));

    double d = 7;
    double e = 3;
    printf("7/3の剰余 =  %d\n", int(fmod(d, e)));

    srand((unsigned int) time(NULL));   // 現在時刻をもとにseedを生成
    for (int i = 0; i < 10; i++){
        printf("%d回目：%f\n", i+1, (double)rand()/RAND_MAX);
    }

    return 0;
}