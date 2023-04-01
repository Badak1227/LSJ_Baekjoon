#include <stdio.h>

int nums[20000001] = { 0 };

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        nums[num + 10000000] = 1;
    }
    
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        printf("%d ", nums[num + 10000000]);
    }
}