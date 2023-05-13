#include <stdio.h>

char calc[51] = { 0 };

int stack[51] = { 0 };
int send = 0;

int operator[51] = { 0 };
int oend = 0;

void to_num(int start, int digit) {
	int res = 0;

	for (int i = 1; digit > 0; digit--, i *= 10) {
		res += (calc[start--] - '0') * i;
	}

	stack[send++] = res;
}

void calculate() {
	while (oend != 0) {
		if (operator[oend - 1] == '+') {
			stack[send - 2] = stack[send - 2] + stack[send - 1];

			send--;
			oend--;
		}
		else {
			stack[send - 2] = stack[send - 2] - stack[send - 1];

			send--;
			oend--;
		}
	}
}

int Calc() {

	int digit = 0;
	int i = 0;

	for (i = 0; calc[i] != 0; i++) {
		
		if (calc[i] >= '0' && calc[i] <= '9') {
			digit++;
		}
		else {
			to_num(i - 1, digit);
			digit = 0;

			if (calc[i] == '-') {
				calculate();
				operator[oend++] = '-';
			}
			else {
				operator[oend++] = '+';
			}
		}
	}

	to_num(i - 1, digit);
	calculate();
}

int main() {
	scanf("%s", calc);

	Calc();

	for (int i = 0; i < send; i++) {
		printf("%d ", stack[i]);
	}


	return 0;
}