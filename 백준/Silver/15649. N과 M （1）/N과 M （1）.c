#include <stdio.h>

int visited[9] = { 0 };

void print(int N, int M, int cnt, int arr[]) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {

        if (!visited[i]) {

            visited[i] = 1;

            arr[cnt] = i;

            print(N, M, cnt + 1, arr);

            visited[i] = 0;
        }
    }
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    int arr[8] = { 0 };
    print(N, M, 0, arr);
}