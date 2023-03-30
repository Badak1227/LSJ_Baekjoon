#include <stdio.h>

int nums[1000001] = { 0 };

int main() {
    int T, num;
    scanf("%d", &T);

    for (int i = 2; i <= 1000000; i++) {
        if (nums[i] != 1) {
            nums[i] = i;
        }
        for (int j = 2 ; j*i <= 1000000; j++) {
            nums[j*i] = 1;
        }
    }

    for (int i = 0; i < T; i++) {
        int count = 0;
        scanf("%d", &num);
        for (int j = 2; j <= num / 2; j++) {
            if (nums[j] + nums[num - j] == num) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}