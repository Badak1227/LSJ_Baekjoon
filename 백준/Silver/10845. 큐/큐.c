#include <stdio.h>

int main() {
	int N, queue[10000] = { 0 }, start = 0, end = 0;
	char str[6] = { 0 };
	
	scanf("%d", &N);

	while (N--) {
		scanf("%s", str);
		
		switch (str[0]) {
			case 'p':
				if (str[1] == 'u') {
					scanf("%d", &queue[end++]);
				}
				else {
					if (end != start) {
						printf("%d\n", queue[start++]);
					}
					else {
						printf("-1\n");
					}
				}
				break;
			case 's':
				printf("%d\n", end - start);
				break;
			case 'e':
				if (end != start) {
					printf("0\n");
				}
				else {
					printf("1\n");
				}
				break;
			case 'f':
				if (end != start) {
					printf("%d\n", queue[start]);
				}
				else {
					printf("-1\n");
				}
				break;
			case 'b':
				if (end != start) {
					printf("%d\n", queue[end-1]);
				}
				else {
					printf("-1\n");
				}
				break;
		}
	}
}