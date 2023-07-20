#include <stdio.h>

int N, M, ans = 0;
char graph[1001][1001] = { 0 }, visited[1001] = { 0 };

void connect(int node) {
	visited[node] = 1;

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && graph[node][i]) {
			connect(i);
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);

	while (M--) {
		int e1, e2;
		
		scanf("%d %d", &e1, &e2);

		graph[e1][e2] = 1;
		graph[e2][e1] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			connect(i);
			ans++;
		}
	}

	printf("%d", ans);
}