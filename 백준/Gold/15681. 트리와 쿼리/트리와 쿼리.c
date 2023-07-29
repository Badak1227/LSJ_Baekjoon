#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int vertex;

	struct node* next;
}node;

int N, R, Q, visited[100001] = { 0 };

node* vertex[100001] = { 0 };

node* newNode() {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->vertex = 0;
	tmp->next = NULL;

	return tmp;
}

void input(int v1, int v2) {
	
	node* cur;

	if (vertex[v1] == 0) {
		vertex[v1] = newNode();
		vertex[v1]->vertex = v2;
	}
	else {
		cur = vertex[v1];

		vertex[v1] = newNode();
		vertex[v1]->vertex = v2;
		vertex[v1]->next = cur;
	}

	if (vertex[v2] == 0) {
		vertex[v2] = newNode();
		vertex[v2]->vertex = v1;
	}
	else {
		cur = vertex[v2];

		vertex[v2] = newNode();
		vertex[v2]->vertex = v1;
		vertex[v2]->next = cur;
	}
}

int dfs(int cur) {

	visited[cur] = 1;

	if (vertex[cur] != 0) {
		node* next = vertex[cur];

		while (next != NULL) {
			if (visited[next->vertex] == 0) {
				visited[cur] += dfs(next->vertex);
			}
			
			next = next->next;
		}
	}
	
	return visited[cur];
}

int main() {
	
	scanf("%d %d %d", &N, &R, &Q);

	for (int i = 1; i <= N - 1; i++) {
		int v1, v2;

		scanf("%d %d", &v1, &v2);

		input(v1, v2);
	}

	dfs(R);

	while (Q--) {
		int query;

		scanf("%d", &query);

		printf("%d\n", visited[query]);
	}

	for (int i = 0; i < 100001; i++) {
		if (vertex[i] != NULL) {
			node* cur = vertex[i];

			while (cur != NULL) {
				node* tmp = cur;
				
				cur = cur->next;
				free(tmp);
			}
		}
	}
}