#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* arr[100001] = { 0 };

int N, visited[100001] = { 0 }, res[100001] = { 0 };

node* getNode() {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = 0;
	tmp->next = NULL;

	return tmp;
}

void insert(int v1, int v2) {

	if (arr[v1] == 0) {
		arr[v1] = getNode();

		arr[v1]->data = v2;
	}
	else {
		node* tmp = getNode();

		tmp->data = v2;
        tmp->next = arr[v1];
        
        arr[v1] = tmp;
	}

	if (arr[v2] == 0) {
		arr[v2] = getNode();

		arr[v2]->data = v1;
	}
	else {
		node* tmp = getNode();

		tmp->data = v1;
        tmp->next = arr[v2];
        
        arr[v2] = tmp;
	}
}

void dfs(int cur) {

	visited[cur] = 1;

	node* next = arr[cur];

	while (next != NULL) {

		if (!visited[next->data]) {
			res[next->data] = cur;

			dfs(next->data);
		}

		next = next->next;
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int v1, v2;

		scanf("%d %d", &v1, &v2);

		insert(v1, v2);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", res[i]);
	}

	for (int i = 1; i <= N; i++) {
		node* tmp = NULL;

		node* cur = arr[i];

		while (cur != NULL) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
}