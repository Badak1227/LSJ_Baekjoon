#include <stdio.h>

int N, house[16][16] = { 0 }, cnt = 0;

// state 0 : 가로, state 1 : 대각선, state 2 : 세로
void sol(int curx, int cury, int state) {
    if (curx == N - 1 && cury == N - 1) {
        cnt++;
        return;
    }

    if (state == 0) {
        if (curx + 1 < N) {
            if (house[cury][curx + 1] == 0) {
                sol(curx + 1, cury, 0);
            }
        }

        if (curx + 1 < N && cury + 1 < N) {
            if (house[cury + 1][curx + 1] == 0 && house[cury + 1][curx] == 0 && house[cury][curx + 1] == 0) {
                sol(curx + 1, cury + 1, 1);
            }
        }
    }
    else if (state == 1) {
        if (curx + 1 < N) {
            if (house[cury][curx + 1] == 0) {
                sol(curx + 1, cury, 0);
            }
        }

        if (curx + 1 < N && cury + 1 < N) {
            if (house[cury + 1][curx + 1] == 0 && house[cury + 1][curx] == 0 && house[cury][curx + 1] == 0) {
                sol(curx + 1, cury + 1, 1);
            }
        }

        if (cury + 1 < N) {
            if (house[cury + 1][curx] == 0) {
                sol(curx, cury + 1, 2);
            }
        }
    }
    else {
        if (curx + 1 < N && cury + 1 < N) {
            if (house[cury + 1][curx + 1] == 0 && house[cury + 1][curx] == 0 && house[cury][curx + 1] == 0) {
                sol(curx + 1, cury + 1, 1);
            }
        }

        if (cury + 1 < N) {
            if (house[cury + 1][curx] == 0) {
                sol(curx, cury + 1, 2);
            }
        }
    }
}

int main() {
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &house[i][j]);
        }
    }

    sol(1, 0, 0);

    printf("%d", cnt);
}