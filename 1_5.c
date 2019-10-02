#include <stdio.h>
#include <gconio.h>

int main(void){
    int cnt = 0;
    while (1){
        if (_kbhit() != 0){
            char ans = getch();
            printf("%s", ans);
        }

        printf("Waiting for keyin.\n");
    }
    return 0;
}
