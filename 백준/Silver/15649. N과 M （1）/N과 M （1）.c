#include <stdio.h>

void print(int N, int M, int cnt, int arr[]) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        int con = 1;

        for (int j = 0; j < cnt; j++) {
            if (arr[j] == i) {
                con = 0;
            }
        }

        arr[cnt] = i;
        if(con) print(N, M, cnt + 1, arr);
    }
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    int arr[8] = { 0 };
    print(N, M, 0, arr);
}