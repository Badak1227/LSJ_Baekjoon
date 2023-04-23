#include <stdio.h>

void sort(int start, int end, int prior[]) {
	int l = start, r = end, m = prior[(l + r) / 2];

	while (l <= r) {
		while (prior[l] < m) {
			l++;
		}
		while (prior[r] > m) {
			r--;
		}

		if (l <= r) {
			int tmp = prior[l];
			prior[l] = prior[r];
			prior[r] = tmp;

			l++;
			r--;
		}
	}

	if (start < r) {
		sort(start, r, prior);
	}
	if (l < end) {
		sort(l, end, prior);
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N, M;

		int queue[101] = { 0 };
		int front = 0, end = 0;

		int prior[101] = { 0 };
		int index = 0;

		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++) {
			int n;
			scanf("%d", &n);
			prior[index++] = n;
			queue[end++] = n;
		}
		sort(0, index - 1, prior);
		
		int count = 0;
		while (front != end && index > 0) {
			if (queue[front] == prior[index - 1]) {
				count++;
				index--;

				if (front == M) {
					printf("%d\n", count);
                    break;
				}
				front = (front + 1) % 101;
			}
			else {
				if (front == M) {
					M = end;
				}

				queue[end] = queue[front];
				front = (front + 1) % 101;
				end = (end + 1) % 101;
			}
		}
	}

	return 0;
}