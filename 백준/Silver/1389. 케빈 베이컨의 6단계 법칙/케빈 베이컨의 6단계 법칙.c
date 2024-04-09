#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct rel {
	int from;
	int to;
}rel;

int user[102] = { 0 }, min = 2147483647, answer = 0;
rel relation[5000] = { 0 };


int comp(rel* relation1, rel* relation2) {
	if (relation1->from < relation2->from) return -1;
	else if (relation1->from > relation2->from) return 1;
	else {
		if (relation1->to > relation2->to)return 1;
		else return 0;
	}
}

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < 2 * M; i += 2) {
		int u1, u2;
		scanf("%d %d", &u1, &u2);

		relation[i].from = u1;
		relation[i].to = u2;
		
		relation[i + 1].from = u2;
		relation[i + 1].to = u1;

		user[u1 + 1]++;
		user[u2 + 1]++;
	}

	for (int i = 1; i <= N; i++) {
		user[i + 1] += user[i];
	}

	qsort(relation, 2 * M, sizeof(rel), comp);

	//1부터 N까지 케빈 베이컨
	for (int i = 1; i <= N; i++) {
		int result = 0;

		int visited[100] = { 0 }, queue[100] = { 0 }, front = 0, rear = 0;

		queue[rear++] = i;
		visited[i] = 0;

		while (front != rear) {
			int cur = queue[front++];

			for (int j = user[cur]; j < user[cur + 1]; j++) {
				if (visited[relation[j].to] == 0 && visited[relation[j].to] != i) {
					queue[rear++] = relation[j].to;
					visited[relation[j].to] = visited[cur] + 1;

					result += visited[relation[j].to];
				}
			}
		}

		if (result < min) {
			min = result;
			answer = i;
		}
	}

	printf("%d", answer);
}