#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    
    // ファイルに出力する
    // file name: 1_7.txt
    FILE *fp;
    fp = fopen("1_7.txt", "wt");

    if(fp == NULL){
        //printf("Cannot opne file.\n");
        return 1;
    }
    else{
        //printf("file is opne.\n");
    }
    fprintf(fp, "t,x,y,z\n");
    // srand((unsigned int) time(NULL));   // 現在時刻をもとにseedを生成
    srand(0);   // seed固定
    double x, y, z;
    for (int t = 0; t<100; t++){

        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z = (double) rand() / RAND_MAX;
        printf("%d,%lf,%lf,%lf\n", t, x, y, z);
        fprintf(fp, "%d,%lf,%lf,%lf\n", t, x, y, z);
    }
    fclose(fp);

    return 0;
}
