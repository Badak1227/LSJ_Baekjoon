#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int heap[100001] = { 0 }, top = 1;

void insert(int num) {
	int ab_num = num < 0 ? -num : num, pos = top;

	heap[top++] = num;

	while (pos != 1) {
		int ab_parent = heap[pos / 2] < 0 ? -heap[pos / 2] : heap[pos / 2];
		
		if (ab_parent > ab_num) {
			int tmp = heap[pos / 2];

			heap[pos / 2] = heap[pos];
			heap[pos] = tmp;

			pos /= 2;
		}
		else if (ab_parent == ab_num) {
			if (heap[pos / 2] > heap[pos]) {
				int tmp = heap[pos / 2];

				heap[pos / 2] = heap[pos];
				heap[pos] = tmp;

				pos /= 2;
			}
			else break;
		}
		else break;
	}
}

int pop() {
	if (top == 1) return 0;

	int res = heap[1], pos = 1, ab_num;

	heap[1] = heap[top - 1];
	top--;

	ab_num = heap[1] < 0 ? -heap[1] : heap[1];

	while (pos * 2 < top) {
		int child = pos * 2, ab_child;

		if (pos * 2 + 1 < top) {
			int ab1 = heap[pos * 2] < 0 ? -heap[pos * 2] : heap[pos * 2], ab2 = heap[pos * 2 + 1] < 0 ? -heap[pos * 2 + 1] : heap[pos * 2 + 1], tmp;

			if (ab1 == ab2) {
				if (heap[pos * 2] > heap[pos * 2 + 1]) {
					child = pos * 2 + 1;
				}
			}
			else if (ab1 > ab2) {
				child = pos * 2 + 1;
			}
		}

		ab_child = heap[child] < 0 ? -heap[child] : heap[child];

		if (ab_num > ab_child) {
			int tmp = heap[pos];

			heap[pos] = heap[child];
			heap[child] = tmp;

			pos = child;
		}
		else if (ab_num == ab_child) {
			if (heap[pos] > heap[child]) {
				int tmp = heap[pos];

				heap[pos] = heap[child];
				heap[child] = tmp;

				pos = child;
			}
			else break;
		}
		else break;
	}

	return res;
}

int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp;

		scanf("%d", &tmp);

		if (tmp) {
			insert(tmp);
		}
		else printf("%d\n",pop());
	}
}