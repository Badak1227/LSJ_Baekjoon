#include <stdio.h>

int visited[100001] = { 0 }, queue[100002] = { 0 }, start = 0, end = 0;

void enqueue(int N) {
	queue[end] = N;
	end = (end + 1) % 100002;

	visited[N] = 1;
}

int dequeue() {
	int res = queue[start];
	start = (start + 1) % 100002;

	return res;
}

void sol(int N, int K) {
	int cnt = 0, len = 1;

	enqueue(N);

	while (len) {
		int tmplen = 0;

		while (len--) {
			int num = dequeue();

			if (num == K) {
				printf("%d", cnt);
				return;
			}

			if (num - 1 >= 0) {
				if (visited[num - 1] != 1) {
					enqueue(num - 1);
					tmplen++;
				}
			}

			if (num + 1 <= 100000) {
				if (visited[num + 1] != 1) {
					enqueue(num + 1);
					tmplen++;
				}
			}

			if (num * 2 <= 100000) {
				if (visited[num * 2] != 1) {
					enqueue(num * 2);
					tmplen++;
				}
			}
		}

		len = tmplen;
		cnt++;
	}
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);

	sol(N, K);
}