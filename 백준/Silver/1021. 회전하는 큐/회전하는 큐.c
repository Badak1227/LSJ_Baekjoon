#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int data;
	struct queue* prev;
	struct queue* next;
}queue;

queue* new_queue() {
	queue* tmp = (queue*)malloc(sizeof(queue));
	tmp->data = 0;
	tmp->prev = NULL;
	tmp->next = NULL;
	return tmp;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	queue* start = 0;
	queue* end = 0;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			start = new_queue();
			end = start;
			end->data = i + 1;
			end->prev = start;
			end->next = start;
			continue;
		}

		end->next = new_queue();
		end->next->prev = end;
		end = end->next;

		start->prev = end;
		end->data = i + 1;
		end->next = start;
	}

	int idx[51] = { 0 };
	int index = 0;

	for (int i = 0; i < M; i++) {
		scanf("%d", &idx[i]);
	}

	int cnt = 0;
	while (idx[index] != 0) {
		int count = 0;
		while (start->data != idx[index]) {
			start = start->next;
			end = end->next;
			count++;
		}

		if (count > N / 2) {
			count = N - count;
		}
		cnt += count;

		queue* tmp = start;
		start->prev->next = start->next;
		start->next->prev = start->prev;
		start = start->next;

		N--;
		index++;

		if (start != end) {
			free(tmp);
		}
	}

	printf("%d", cnt);

	while (start != end) {
		queue* tmp = start;
		start = start->next;
		free(tmp);
	}
	free(start);
}