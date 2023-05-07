#include <stdio.h>

void khan(int l, int r, char* arr) {
    if (r - l < 3) return;

    int p1 = l + (r - l) / 3;
    int p2 = l + (r - l) / 3 * 2;

    for (int i = p1; i < p2; i++) {
        arr[i] = ' ';
    }



    if (p1 - l >= 3) {
        khan(l, p1, arr);
    }
    if (r - p2 >= 3) {
        khan(p2, r, arr);
    }
}

int main() {
    int N;
    char arr[531442] = { 0 };

    while (scanf("%d", &N) != EOF) {
        int len = 1;
        for (int i = 0; i < N; i++) {
            len *= 3;
        }

        
        for (int i = 0; i < len; i++) {
            arr[i] = '-';
        }
        arr[len] = 0;

        khan(0, len, arr);
        printf("%s\n", arr);
    }
}