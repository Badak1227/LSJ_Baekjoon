#include <stdio.h>

int nidx = 1, sidx = 0;

int stack[100000] = { 0 };

char result[200000] = { 0 };

int rstart = 0, rend = 0;

int main() {
    int N;
    scanf("%d", &N);

    int YN = 1;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        while (nidx <= num) {
            stack[sidx++] = nidx++;
            result[rend++] = '+';
        }
        while (stack[sidx - 1] > num) {
            sidx--;
            result[rend++] = '-';
        }

        if (stack[sidx - 1] == num) {
            sidx--;
            result[rend++] = '-';
        }
        else {
            YN = 0;
        }
    }
    
    if (YN == 1) {
        for (int i = rstart; i < rend; i++) {
            printf("%c\n", result[i]);
        }
    }
    else {
        printf("NO");
    }
    return 0;
}