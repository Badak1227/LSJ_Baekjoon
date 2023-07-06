#include <stdio.h>
#include <stdlib.h>

int nums[8] = { 0 };

void print(int N, int M, int start, int cnt, int arr[]) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < N; i++) {

        arr[cnt] = nums[i];

        print(N, M, i, cnt + 1, arr);
    }
}

int compare(int* num1, int* num2) {
    return *num1 - *num2;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    qsort(nums, N, sizeof(int), compare);

    int arr[8] = { 0 };
    print(N, M, 0, 0, arr);
}