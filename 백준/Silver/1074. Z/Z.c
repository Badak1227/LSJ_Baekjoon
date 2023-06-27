#include <stdio.h>
#include <math.h>

int cnt = 0;

void sol(int y1, int x1, int y2, int x2, int r, int c) {
	int mx = (x1 + x2) / 2, my = (y1 + y2) / 2, darea = (x2 - x1 + 1) * (y2 - y1 +1) / 4;

	if (y1 == y2 && x1 == x2) {
		printf("%d", cnt);
		return;
	}

	if (r <= my &&  c <= mx) {

		sol(y1, x1, my, mx, r, c);
	}
	else if (r <= my && c > mx) {
		cnt += darea;

		sol(y1, mx + 1, my, x2, r, c);
	}
	else if (r > my && c <= mx) {
		cnt += darea * 2;

		sol(my + 1, x1, y2, mx, r, c);
	}
	else if (r > my && c > mx) {
		cnt += darea * 3;

		sol(my + 1, mx + 1, y2, x2, r, c);
	}
}

int main() {
	int N, r, c, len;

	scanf("%d %d %d", &N, &r, &c);

	len = pow(2, N);

	sol(0, 0, len - 1, len - 1, r, c);
}