#include <stdio.h>

int heap[100001] = { 0 }, end = 1;

int M(int a, int b) {
    return heap[a] > heap[b] ? a : b;
}

void swap(int pos1, int pos2) {
    int tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
}

void down_up(int pos) {
    if (pos == 1) return;

    if (heap[pos] > heap[pos / 2]) {
        swap(pos, pos / 2);
        down_up(pos / 2);
    }
}

void insert(int num) {
    heap[end] = num;
    down_up(end);
    end++;
}

void up_down(int pos) {
    if (pos * 2 >= end) {
        return;
    }

    int next = M(pos * 2, pos * 2 + 1);

    if (heap[pos] < heap[next]) {
        swap(pos, next);
        up_down(next);
    }
}

void delete() {
    if (end == 1) {
        printf("0\n");
        return;
    }

    printf("%d\n", heap[1]);
    end--;

    heap[1] = heap[end];

    up_down(1);
}

int main() {
    int N;

    scanf("%d", &N);

    while (N--) {
        int num;
        scanf("%d", &num);

        if(num != 0){
            insert(num);
        }
        else {
            delete();
        }
    }
}