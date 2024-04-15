#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char graph[100][100] = { 0 }, N;

int bfs(int num, int target) {
	char visited[100] = { 0 }, queue[101] = { 0 }, front = 0, rear = 0;

	queue[rear++] = num;

	while (front < rear) {
		char cur = queue[front++];


		for (int i = 0; i < N; i++) {
			char next = graph[cur][i];

			if (next == 1 && visited[i] == 0) {
				if (i == target) return 1;

				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", bfs(i, j));
		}
		printf("\n");
	}

}