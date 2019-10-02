#include <stdio.h>
#include <math.h>


int main(void){
    FILE *fp;
    int t;
    double x, y, z;
    fp = fopen("1_7.txt", "rt");
    if (fp == NULL){
        // printf("Cannot open file.\n");
        return 0;
    }else{
        // printf("Can open file.\n");
    }

    // 以下線形回帰を行う
    // while文の中でデータを読み込み計算する
    
    double Sxx, Sxy, Sx, Sy;    // 合計を求める
    /* 
    x-z用
    double Sxx, Sxz, Sx, Sz;
    */
    // 1行目(t,x,y,z)を飛ばす
    while (fgetc(fp) != '\n' && !feof(fp)) ;

    while(fscanf(fp, "%d,%lf,%lf,%lf", &t, &x, &y, &z)!= EOF){
        // printf("%d,%lf,%lf,%lf\n", t, x, y, z);
        // 以下データをどんどん足していく
        Sxx += x * x;
        Sxy += x * y;
        Sx += x;
        Sy += y;

        // z ~ x用
        /*
        Sxx += x * x;
        Sxz += x * z;
        Sx += x;
        Sz += z;
        */
    }
    
    fclose(fp);

    // 係数を求める
    double D = 100 * Sxx - Sx * Sx;  // 分母
    double a = (100 * Sxy - Sx * Sy) / D;
    double b = (-Sx * Sxy + Sxx * Sy) / D;

    // z ~ x用
    /*
    double D = 100 * Sxx - Sx * Sx;
    double a = (100 * Sxz - Sx * Sz) / D;
    double b = (-Sx * Sxz + Sxx * Sz) / D;
    */

    // 式表示
    printf("y = %lfx + %lf\n", a, b);

    return 0;

}