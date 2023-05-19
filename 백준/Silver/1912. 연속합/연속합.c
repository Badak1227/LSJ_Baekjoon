#include <stdio.h>

int main() {
	int max, sum, n;
	scanf("%d", &n);

	scanf("%d", &sum);
	max = sum;

	for (int i = 1; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
        
        int check = tmp + sum;
        
		if (check < tmp) {
			sum = tmp;
		}
		else {
			sum = check;
		}

		max = sum > max ? sum : max;
	}

	printf("%d", max);
}