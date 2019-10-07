// Windowsだと文字化けした

#include <stdio.h>

// 構造体型struct kaikeiの宣言
typedef struct kaikei
{
    /* data */
    int money;
    char koumoku[100];
}Kaikei;

int main(void){

    // 
    Kaikei kaikei1;
    
    // ファイルの読み込み
    FILE *fp;
    // パスをしっかり書く
    fp = fopen("shushi.dat", "r+");
    
    if(fp == NULL){
        // printf("Cannot open dile.\n");
        return 0;
    }else{
        // printf("Can open file.\n");
    }

    // 読み込み
    int cut = 0;
    int goukei = 0;
    printf("金額,合計,項目\n");

    while (fscanf(fp, "%d,%s", &kaikei1.money, kaikei1.koumoku) != EOF){
        goukei += kaikei1.money;
        printf("%d,%d,%s\n", kaikei1.money, goukei, kaikei1.koumoku);
    }
    
    // 入力
    while(1){
        printf("データを入力しますか？(YES:1, NO:0)\n");
        int i;
        scanf("%d", &i);
        if(i == 1){
            bool flag = true;
            while(flag){
                printf("金額を入力してください．\n");
                scanf("%d", &kaikei1.money);
                printf("項目を入力してください．\n");
                scanf("%s", kaikei1.koumoku);

                printf("訂正しますか？(YES:1, NO:0)\n");
                int num;
                scanf("%d", &num);
                if (num == 0){
                    fprintf(fp, "%d,%s\n", kaikei1.money, kaikei1.koumoku);
                    printf("追加しました．\n");
                    flag = false;
                }else{ 
                    break;
                }    
            }
        }else if(i == 0){
            printf("入力を終えます．\n");
            break;
        }else{
            continue;
        }
    }
    fclose(fp);
    return 0;
}