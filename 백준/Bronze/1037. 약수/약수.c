#include <stdio.h>

int main(){
	int n, min = 1000000, max=2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		min = num < min ? num : min;
		max = num > max ? num : max;
	}
	printf("%d", min * max);
}