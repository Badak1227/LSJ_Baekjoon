#include <stdio.h>
#include <stdlib.h>

int count = 0, K;

int arr[500000] = { 0 };

void merge(int start, int mid, int end, int arr[]) {
    int l = start, r = mid + 1;

    int* tmp = (int*)malloc(sizeof(int) * (end - start + 1));
    int idx = 0;

    while (l <= mid && r <= end) {
        if (arr[l] <= arr[r]) {
            tmp[idx++] = arr[l++];
        }
        else {
            tmp[idx++] = arr[r++];
        }
    }
    while (l <= mid) {
        tmp[idx++] = arr[l++];
    }
    while (r <= end) {
        tmp[idx++] = arr[r++];
    }

    idx = 0;
    l = start;
    while (l <= end) {
        if (++count == K) {
            printf("%d", tmp[idx]);
            return;
        }
        arr[l++] = tmp[idx++];
    }

    free(tmp);
}

void merge_sort(int start, int end, int arr[]) {
    int l = start, r = end, m = (l + r) / 2;
    if (l < r) {
        merge_sort(l, m, arr);
        merge_sort(m + 1, r, arr);
        merge(l, m, r, arr);
    }
}

int main() {
    int N;
    scanf("%d %d", &N, &K);

    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(0, N - 1, arr);
    if (count < K) {
        printf("-1");
    }
}