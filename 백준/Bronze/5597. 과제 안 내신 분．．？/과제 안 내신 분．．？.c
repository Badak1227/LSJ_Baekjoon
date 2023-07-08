#include <stdio.h>

int main() {
    int student[31] = { 0 }, ans = 0;

    for (int i = 1; i <= 28; i++) {
        int num;
        scanf("%d", &num);

        student[num] = 1;
    }

    for (int i = 1; i <= 30; i++) {
        
        if (student[i] == 0) {
            printf("%d\n", i);
            ans++;
        }

        if (ans == 2) break;
    }
}