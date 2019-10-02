#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
    int a = 2;
    double b = 8;
    printf("2^8 = %lf\n", pow(a, b));


    double alpha = 67; // 角度(単位は°)
    double theta = M_PI * 67 / 180; // radに変換
    printf("sin(67°) = %f\n", sin(theta));

    double c = -23.456;
    printf("|-23.456| = %f\n", fabs(c));

    double d = 7;
    double e = 3;
    printf("7/3の剰余 =  %lf\n", fmod(d, e));

    srand((unsigned int) time(NULL));   // 現在時刻をもとにseedを生成
    for (int i = 0; i < 10; i++){
        printf("%d回目：%f\n", i+1, (double)rand()/RAND_MAX);
    }

    return 0;
}