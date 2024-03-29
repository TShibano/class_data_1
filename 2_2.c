#include <stdio.h>

int main(void){
    FILE *fp;

    typedef struct 
    {
        int t;
        double x, y, z;
    }DATA;
    
    int t;
    double x, y, z;
    DATA data[100];
    // file open

    /* 
    file = "C:-----¥¥1_7.txt";
    パスをしっかり書く
    */
    fp = fopen("1_7.txt", "rt");
    // fp = fopen(file, "rt");
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
        data[cnt].t = t;
        data[cnt].x = x;
        data[cnt].y = y;
        data[cnt].z = z;
        
        cnt++;
    }
    
    fclose(fp);
    printf("t,x,y,z\n");
    // デバッグ
    for(int i = 0; i <100; i++){
        printf("%d,%lf,%lf,%lf\n", data[i].t, data[i].x, data[i].y, data[i].z);
    }

    return 0;

}