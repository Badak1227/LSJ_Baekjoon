#include <stdio.h>

int main() {
	int a = 1, b = 1, c = 1, max = 0;
	
	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if(a == 0 && b == 0 && c == 0) break;

		max = a > b && a > c ? a : b > c ? b : c;

		if (max * max == a * a + b * b + c * c - max * max) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
}