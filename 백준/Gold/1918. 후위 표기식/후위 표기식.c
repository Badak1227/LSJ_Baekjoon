#include <stdio.h>

char operator[500] = { 0 };

int end = 0;

void push(char cur) {
	operator[end] = cur;
	end++;
}

void pop(char cur) {

	while (end > 0) {
		if (cur == '*' || cur == '/') {
			if (operator[end - 1] == '(') {
				break;
			}

			if (operator[end - 1] == '*' || operator[end - 1] == '/') {
				printf("%c", operator[end - 1]);
				end--;
			}
			else {
				break;
			}
		}
		else if (cur == ')') {
			if (operator[end - 1] == '(') {
				end--;
				break;
			}

			printf("%c", operator[end - 1]);
			end--;
		}
		else {
			if (operator[end - 1] == '(') {
				break;
			}

			printf("%c", operator[end - 1]);
			end--;
		}
	}
}

void popAll() {
	while (end > 0) {
		printf("%c", operator[end - 1]);
		end--;
	}
}

int main() {
	char cur;

	while (scanf("%c", &cur), cur != '\n') {
		if ('A' <= cur && cur <= 'Z') {
			printf("%c", cur);
		}
		else if(cur == '(') {
			push(cur);
		}
		else if (cur == ')') {
			pop(cur);
		}
		else {
			if (end == 0) {
				push(cur);
			}
			else {
				if (cur == '-') {
					pop(cur);
				}
				else {
					pop(cur);
				}

				push(cur);
			}
		}
	}

	popAll(0);
}