#include <stdio.h>

int main(void){
    typedef struct{
        int t;
        double x, y, z;
    }DATA;

    // file open
    FILE *fp;
    fp = fopen("1_7.txt", "rt");
    if (fp == NULL){
        printf("Cannot open file.\n");
        return 0;
    }else{
        printf("Can open file\n");
    }
    while (fgetc(fp) != '\n' && !feof(fp)); // 1行目をとばす

    // 1.ファイルを読み込み，行数をカウントする
    int cnt = 0;    // counter
    int t;
    double x, y, z;
    while(fscanf(fp, "%d,%lf,%lf,%lf", &t, &x, &y, &z) != EOF){
        cnt ++;
    }

    // 2. 読み込みに必要な配列を確保する
    DATA* ptr;
    ptr = new DATA[cnt];

    // ファイル位置が終端(EOF)に来ているので先頭に戻す
    rewind(fp);
    while (fgetc(fp) != '\n' && !feof(fp)); // 1行目をとばす
    // 3. 確保した配列にデータを読み込む
    int i = 0;
    while(fscanf(fp, "%d,%lf,%lf,%lf", &t, &x, &y, &z) != EOF){
        ptr[i].t = t;
        ptr[i].x = x;
        ptr[i].y = y;
        ptr[i].z = z;
        i++;
    }

    fclose(fp);


    printf("display data\n");
    printf("t,x,y,z\n");
    for(int i = 0; i < cnt; i++){
        printf("%d,%lf,%lf,%lf\n", ptr[i].t, ptr[i].x, ptr[i].y, ptr[i].z);
    }

    delete []ptr;

    return 1;
}