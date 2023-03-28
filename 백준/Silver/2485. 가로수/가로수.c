#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2) {
    if (num1 > num2) {
        return num2 ? gcd(num1 % num2, num2) : num1;
    }
    return num1 ? gcd(num2 % num1, num1) : num2;
}

int main() {
    int N;
    scanf("%d", &N);
    int* trees;
    trees = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &trees[i]);
    }

    int* dist;
    dist = (int*)malloc(sizeof(int) * (N - 1));
    for (int i = 0; i < N - 1; i++) {
        dist[i] = trees[i + 1] - trees[i];
    }

    int gcd1 = gcd(dist[0], dist[1]);
    for (int i = 2; i < N - 1; i++) {
        gcd1 = gcd(gcd1, dist[i]);
    }

    printf("%d", (trees[N - 1] - trees[0]) / gcd1 - (N - 1));
}