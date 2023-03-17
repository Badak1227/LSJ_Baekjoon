#include <stdio.h>

int numlen(int N) {
    int len = 0;
    int i = 1;
    while (N / i > 0) {
        len++;
        i *= 10;
    }
    return len;
}

int main() {
    int N, M = 0;
    scanf("%d", &N);
    int len = numlen(N);
    for (int i = (N - 1); i >= (N - 9 * len); i--) {
        
        int tmpi = i;
        int tmpM = i;
        int tmplen = 1;
        for (int j = 1; j < numlen(i); j++) {
            tmplen *= 10;
        }

        for (int j = 0; j < numlen(i); j++) {
            tmpM += tmpi / tmplen;
            tmpi -= tmpi / tmplen * tmplen;
            tmplen /= 10;
        }
        if (tmpM == N) {
            M = i;
        }
    }
    printf("%d", M);
}