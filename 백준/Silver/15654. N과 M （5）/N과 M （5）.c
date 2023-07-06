#include <stdio.h>
#include <stdlib.h>

int visited[8] = { 0 }, nums[8] = { 0 };

void print(int N, int M, int cnt, int arr[]) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++) {

        if (!visited[i]) {

            visited[i] = 1;

            arr[cnt] = nums[i];

            print(N, M, cnt + 1, arr);

            visited[i] = 0;
        }
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
    print(N, M, 0, arr);
}