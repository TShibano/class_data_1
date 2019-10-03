#include <stdio.h>

int main(void){
    FILE *fp;
    int t;
    double x, y, z;
    double data[100][4];    // 時刻tがdouble型になってしまう
    // file open
    fp = fopen("1_7.txt", "rt");
    if (fp == NULL){
        // printf("Cannot open file.\n");
        return 0;
    }else{
        // printf("Can open file.\n");
    }

    // 1行目(t,x,y,z)を飛ばす
    while (fgetc(fp) != '\n' && !feof(fp)) ;

    // 読み込み
    int cnt = 0;    // while内のカウント用
    while(fscanf(fp, "%d,%lf,%lf,%lf", &t, &x, &y, &z) != EOF){
        data[cnt][0] = t;
        data[cnt][1] = x;
        data[cnt][2] = y;
        data[cnt][3] = z;
        
        cnt++;
    }
    
    fclose(fp);
    
    /*
    デバッグ
    printf("%lf\n", data[0][0]);
    printf("%lf\n", data[50][3]);
    printf("%lf\n", data[99][3]);
    */
    return 0;

}