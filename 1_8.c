#include <stdio.h>

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
    // 1行目(t,x,y,z)を飛ばす
    while (fgetc(fp) != '\n' && !feof(fp)) ;

    // 読み込み
    while(fscanf(fp, "%d,%lf,%lf,%lf", &t, &x, &y, &z) != EOF){
        printf("%d,%lf,%lf,%lf\n", t, x, y, z);

    }
    
    fclose(fp);

    return 0;

}