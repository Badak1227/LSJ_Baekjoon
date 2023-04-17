#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int num;
	struct list* next;
}list;

list* new_list(int num) {
	list* tmp = (list*)malloc(sizeof(list));
	tmp->num = num;
	tmp->next = NULL;
	return tmp;
}

int main() {
	int N;
	scanf("%d", &N);

	list* front = new_list(1);
	list* rear = front;
	for (int i = 2; i <= N; i++) {
		front->next = new_list(i);
		front = front->next;
	}
	
	while (front != rear) {
		list* tmp = rear;
		rear = rear->next;
		free(tmp);

		front->next = rear;

		rear = rear->next;

		front = front->next;

		front->next = NULL;

		list* tmp1 = rear;
	}

	printf("%d", rear->num);

	free(rear);
}