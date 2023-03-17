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
        
        while(tmpi){
            tmpM += tmpi%10;
            tmpi /= 10;
        }
        
        if (tmpM == N) {
            M = i;
        }
    }
    printf("%d", M);
}