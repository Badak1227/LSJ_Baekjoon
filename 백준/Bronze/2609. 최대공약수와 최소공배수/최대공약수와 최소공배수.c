#include <stdio.h>

int gcd(int num1, int num2) {
	if (num1 == 0) return num2;
	
	int res;

	if (num1 < num2) {
		res = gcd(num2 % num1, num1);
	}
	else {
		res = gcd(num1 % num2, num2);
	}

	return res;
}

int main() {
	int num1, num2, g;

	scanf("%d %d", &num1, &num2);

	g = gcd(num1, num2);

	printf("%d\n%d", g, num1 * num2 / g);
}