#include <stdio.h>

int n, m, init_x, init_y, queue[1000001][2] = {0}, start = 0, end = 0, map[1000][1000] = { 0 }, dp[1000][1000] = { 0 }, movement[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void input(int x, int y) {
    queue[end][0] = x;
    queue[end][1] = y;

    map[y][x] = 0;

    end = (end + 1) % 1000001;
}

void delete() {
    start = (start + 1) % 1000001;
}

void sol() {

    input(init_x, init_y);

    while (start != end) {
        int curx = queue[start][0], cury = queue[start][1];
        
        delete();

        for (int i = 0; i < 4; i++) {
            int nextx = curx + movement[i][0], nexty = cury + movement[i][1];

            if (0 <= nextx && nextx < m && 0 <= nexty && nexty < n) {
                
                if (map[nexty][nextx] == 1) {
                    input(nextx, nexty);
                    dp[nexty][nextx] = dp[cury][curx] + 1;
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);

            if (map[i][j] == 2) {
                init_x = j;
                init_y = i;
                dp[init_y][init_x] = 0;
            }
            else if (map[i][j] == 0) {
                dp[i][j] = 0;
            }
        }
    }

    sol();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}