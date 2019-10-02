#include <stdio.h>
#include <conio.h>

int main(void){
    /* int cnt = 0; */
    while (1){
        if (_kbhit() != 0){
            char ans = _getch();
         /* char ans = _getche(); */
         printf("%c", ans);
            break;
        }

        printf("Waiting for keyin.\n");
    }
    return 0;
}
