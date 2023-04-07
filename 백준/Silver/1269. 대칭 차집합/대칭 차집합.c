#include <stdio.h>

char bit_map[12500001] = { 0 };

int count = 0;

void mapping(int num) {
	int bit_map_index = num / 8;
	int bit_index = num % 8;
	if (bit_map[bit_map_index] & 1 << bit_index) {
		bit_map[bit_map_index] &= ~(1 << bit_index);
		count--;
	}
	else {
		bit_map[bit_map_index] |= 1 << bit_index;
		count++;
	}
}

int main() {
	int N, M;
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		mapping(tmp);
	}
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", &tmp);
		mapping(tmp);
	}
	printf("%d", count);
}