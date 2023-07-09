#include <stdio.h>

int movement[8][2] = { {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1} }, queue[90001][2] = {0}, start = 0, end = 0;

void input(int x, int y, char board[][300]) {
    queue[end][0] = x;
    queue[end][1] = y;

    board[y][x] = 1;

    end = (end + 1) % 90001;
}

void delete() {
    start = (start + 1) % 90001;
}

void sol(int I, int curx, int cury, int targetx, int targety) {
    char board[300][300] = { 0 };
    int len = 1, ans = 0;

    start = 0;
    end = 0;
    
    if (curx == targetx && cury == targety) {
        printf("%d\n", ans);
        return;
    }

    input(curx, cury, board);

    while (len) {
        int tmplen = 0;

        while (len--) {
            int x = queue[start][0], y = queue[start][1];
            delete();

            for (int i = 0; i < 8; i++) {
                int nextx = x + movement[i][0], nexty = y + movement[i][1];

                if (nextx == targetx && nexty == targety) {
                    printf("%d\n", ans + 1);
                    return;
                }
                
                if (-1 < nextx && nextx < I && -1 < nexty && nexty < I && board[nexty][nextx] == 0) {
                    input(nextx, nexty, board);
                    tmplen++;
                }
            }
        }

        len = tmplen;
        ans++;
    }
}

int main() {
    int T;

    scanf("%d", &T);

    while (T--) {
        int I, curx, cury, targetx, targety;

        scanf("%d", &I);

        scanf("%d %d", &curx, &cury);

        scanf("%d %d", &targetx, &targety);

        sol(I, curx, cury, targetx, targety);
    }
}