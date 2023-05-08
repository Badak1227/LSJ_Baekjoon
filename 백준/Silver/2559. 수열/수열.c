#include <stdio.h>

int main() {
    int N, M, max = -100;
    int nums[100001] = { 0 };

    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);

        nums[i] = nums[i - 1] + tmp;
    }
    
    max = nums[M];
    for (int i = 2; i <= N - M + 1; i++) {
        max = (nums[i + M - 1] - nums[i - 1]) > max ? (nums[i + M - 1] - nums[i - 1]) : max;
    }

    printf("%d", max);
}