#include <stdio.h>

int nums[1000001] = { 0 };

int main() {
    int T, num;
    scanf("%d", &T);

    for (int i = 2; i * i < 1000000; i++) {
        if (nums[i] != 1) {
            nums[i] = 0;
        }
        for (int j = i * i; j < 1000000; j += i) {
            nums[j] = 1;
        }
    }

    for (int i = 0; i < T; i++) {
        int count = 0;
        scanf("%d", &num);
        for (int j = 2; j <= num / 2; j++) {
            if (nums[j] == 0 && nums[num - j] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}