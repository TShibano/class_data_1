#include <stdio.h>
#include <math.h>

// 常微分方程式の宣言
double F(double x, double y);

int main(void){
    // 変数宣言
    // 定数
    double g, c, dt;
    g = 9.81;
    c = 0.1;
    dt = 0.1;

    // 初期値
    double v, t, true_v;
    v = 0;
    t = 0;
    true_v = 0;
    /* 
    微分方程式をとくと
    v = 98.1 - 98.1 * exp(-0.1 * t)
    */

    // 1回目の表示
    printf("t: %lf, v: %lf, true_v: %lf\n", t, v, true_v);


    // runge-kutta method
    for (int i = 1; i < 11; i++){
        // 定数kを求める
        double k1, k2, k3, k4, k;
        
        k1 = dt * F(t, v);
        k2 = dt * F(t + dt / 2, v + k1 / 2);
        k3 = dt * F(t + dt / 2, v + k2 / 2);
        k4 = dt * F(t + dt, v + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        // 値
        t += dt;
        v += k;
        true_v = 98.1 - 98.1 * exp(-0.1 * t);   
        
        printf("t: %lf, v: %lf, true_v: %lf\n", t, v, true_v);
    }

    return 0;
}

// 常微分方程式の定義
double F(double x, double y){
    double g, c;
    g = 9.81;
    c = 0.1;

    return g - c * y;
}