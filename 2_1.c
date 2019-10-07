#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES

int main(void){
    double y[11];
    double A = 50;
    double T = 4;
    double lambda = 10;
    double time[11];

    for (int i = 0; i <= 10; i++){
        scanf("%lf", &time[i]);
        int x = 2 * i;
        y[i] = A * sin(2 * M_PI * (time[i] / T - x / lambda));
    }

    for (int i = 0; i <= 10; i++){
        printf("%d:time is %lf: %lf\n", i, time[i], y[i]);
    }

    return 0;
}