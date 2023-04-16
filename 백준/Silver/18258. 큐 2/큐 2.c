#include <stdio.h>

int queue[2000000] = { 0 };

int start = 1999999;
int end = 1999999;

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		char str1[6] = "";
		scanf("%s", str1);

		switch (str1[1]) {
			case 'u':
				scanf("%d", &queue[end--]);
				break;
			case 'o':
				printf("%d\n", start == end ? -1 : queue[start--]);
				break;
			case 'i':
				printf("%d\n", start - end);
				break;
			case 'm':
				printf("%d\n", start == end ? 1 : 0);
				break;
			case 'r':
				printf("%d\n", start == end ? -1 : queue[start]);
				break;
			case 'a':
				printf("%d\n", start == end ? -1 : queue[end + 1]);
				break;
		}
	}

	return 0;
}