#include <stdio.h>
#include <conio.h>  // Macでは動かない(Windows, Visual Studioなら可能)

int main(void){
    int cnt = 0;
    while (1){
        if (_kbhit() != 0){
            char ans = _getch();
            printf("%s", ans);
            break;
        }

        printf("Waiting for keyin.\n");
    }
    return 0;
}