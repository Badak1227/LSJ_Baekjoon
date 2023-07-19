#include <stdio.h>

int sol(int cur, int target) {
	int ans = 0;

	if (cur > target) {
		return 0;
	}

	if (cur == target) {
		return 1;
	}

	ans += sol(cur + 1, target);

	ans += sol(cur + 2, target);

	ans += sol(cur + 3, target);
    
    return ans;
}

int main() {
	int T;

	scanf("%d", &T);
	
	while (T--) {
		int n;

		scanf("%d", &n);

		printf("%d\n", sol(0, n));
	}
}