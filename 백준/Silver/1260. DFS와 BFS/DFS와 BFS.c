#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
	int num;
	struct graph* next;
}graph;

int visited[1001] = { 0 };

graph* num_graph[1001] = { 0 };

void insert(int num1, int num2) {
	if (num_graph[num1] != NULL) {
		graph* cur = num_graph[num1];
		graph* prev = cur;
		graph* tmp = (graph*)malloc(sizeof(graph));

		if (cur->num > num2) {
			tmp->num = num2;
			tmp->next = cur;

			num_graph[num1] = tmp;
		}
		else {
			while (cur) {
				if (cur->num > num2) break;

				prev = cur;
				cur = cur->next;
			}

			tmp->num = num2;
			tmp->next = prev->next;

			prev->next = tmp;
		}
	}
	else {
		num_graph[num1] = (graph*)malloc(sizeof(graph));

		num_graph[num1]->num = num2;
		num_graph[num1]->next = NULL;
	}

	if (num_graph[num2] != NULL) {
		graph* cur = num_graph[num2];
		graph* prev = cur;
		graph* tmp = (graph*)malloc(sizeof(graph));

		if (cur->num > num1) {
			tmp->num = num1;
			tmp->next = cur;

			num_graph[num2] = tmp;
		}
		else {
			while (cur) {
				if (cur->num > num1) break;

				prev = cur;
				cur = cur->next;
			}

			tmp->num = num1;
			tmp->next = prev->next;

			prev->next = tmp;
		}
		
	}
	else {
		num_graph[num2] = (graph*)malloc(sizeof(graph));

		num_graph[num2]->num = num1;
		num_graph[num2]->next = NULL;
	}
}

void dfs(int num) {
	visited[num] = 1;

	printf("%d ", num);

	graph* cur = num_graph[num];

	while (cur != NULL) {
		if (visited[cur->num] == 0) {
			dfs(cur->num);
		}
		
		cur = cur->next;
	}
}

void bfs(int num) {
	int queue[1000] = { 0 }, front = 0, rear = 1;

	queue[0] = num;
	
	visited[num] = 1;

	while (front != rear) {
		int cur = queue[front++];

		printf("%d ", cur);

		graph* tmp = num_graph[cur];

		while (tmp != NULL) {
			if (visited[tmp->num] == 0) {
				queue[rear++] = tmp->num;

				visited[tmp->num] = 1;
			}

			tmp = tmp->next;
		}
	}
}

void free_all(graph* num_graph[1000]) {
	for (int i = 0; i < 1000; i++) {
		graph* cur = num_graph[i];

		while (cur != NULL) {
			graph* tmp = cur;
			
			cur = cur->next;

			free(tmp);
		}
	}
}

int main() {
	int N, M, V;

	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int num1, num2;

		scanf("%d %d", &num1, &num2);

		insert(num1, num2);
	}

	dfs(V);

	printf("\n");

	for (int i = 0; i < 1001; i++) {
		visited[i] = 0;
	}

	bfs(V);

	free_all(num_graph);

}