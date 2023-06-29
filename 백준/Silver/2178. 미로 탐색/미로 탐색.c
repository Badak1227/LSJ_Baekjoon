#include <stdio.h>

int queue[10001][2] = {0}, front = 0, rear = 0;

char mage[100][100] = { 0 };

void enqueue(int row, int col) {
	queue[rear][0] = row;
	queue[rear][1] = col;
	rear = (rear + 1) % 10001;

	mage[row][col] = '0';
}

void dequeue() {
	front = (front + 1) % 10001;
}

int main() {
	int N, M, cnt = 1, len = 1;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &mage[i][j]);
		}
	}

	enqueue(0, 0);

	while (1) {
		int tmplen = 0;

		while (len--) {
			int row = queue[front][0], col = queue[front][1];
			
			if (row == N - 1 && col == M - 1) {
				printf("%d", cnt);
				return 0;
			}

			dequeue();

			if (row + 1 < N) {
				if (mage[row + 1][col] == '1') {

					enqueue(row + 1, col);
					tmplen++;
				}
			}

			if (col + 1 < M) {
				if (mage[row][col + 1] == '1') {

					enqueue(row, col + 1);
					tmplen++;
				}
			}

			if (row - 1 > -1) {
				if (mage[row - 1][col] == '1') {

					enqueue(row - 1, col);
					tmplen++;
				}
			}

			if (col - 1 > -1) {
				if (mage[row][col - 1] == '1') {

					enqueue(row, col - 1);
					tmplen++;
				}
			}
		}

		len = tmplen;
		cnt++;
	}
}