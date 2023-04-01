#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* bitMap = (char*)malloc(2500001*sizeof(char));
    memset(bitMap, 0, 2500001 * sizeof(char));
    int N, bitMapIndex, bitIndex;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        num += 10000000;
        bitMapIndex = num / 8;
        bitIndex = num % 8;
        bitMap[bitMapIndex] |= (1 << bitIndex);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        num += 10000000;
        bitMapIndex = num / 8;
        bitIndex = num % 8;
        if (bitMap[bitMapIndex] & (1 << bitIndex)) {
            printf("1 ");
        }
        else {
            printf("0 ");
        }
    }
}