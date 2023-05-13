#include <stdio.h>

int main() {
	
	int on = 1;
	int sum = 0;

	scanf("%d", &sum);

	while (1) {
		char operator;
		int num;

		scanf("%c", &operator);

		if (operator == '\n') break;
		
		scanf("%d", &num);

		if (on) {
			if (operator == '+') {
				sum += num;
			}
			else {
				sum -= num;
				on--;
			}
		}
		else {
			sum -= num;
		}
	}

	printf("%d", sum);

	return 0;
}