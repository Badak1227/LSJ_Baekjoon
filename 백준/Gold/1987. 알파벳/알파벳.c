#include <stdio.h>

int R, C;
char board[20][20] = { 0 }, alphabet[26] = { 0 }, movement[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} }, ans = 0;

void sol(int x, int y, int cnt){
    alphabet[board[y][x] - 'A'] = 1;

    for (int i = 0; i < 4; i++) {
        int nextx = x + movement[i][0], nexty = y + movement[i][1];

        if (-1 < nextx && nextx < C && -1 < nexty && nexty < R && alphabet[board[nexty][nextx] - 'A'] == 0) {
            sol(nextx, nexty, cnt + 1);
        }
        
    }

    alphabet[board[y][x] - 'A'] = 0;
    ans = cnt > ans ? cnt : ans;
}

int main() {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    sol(0, 0, 1);

    printf("%d", ans);
}