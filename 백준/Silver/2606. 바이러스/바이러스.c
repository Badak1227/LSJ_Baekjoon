#include <stdio.h>

int V, E, com[101][101] = { 0 }, visited[101] = { 0 }, ans = 0;

void sol(int cur) {
    
    visited[cur] = 1;

    for (int i = 1; i <= V; i++) {
        
        if (com[cur][i] == 0 || visited[i] == 1) continue;
        
        ans++;
        
        sol(i);
    }
}

int main() {

    scanf("%d %d", &V, &E);

    while (E--) {
        int v1, v2;

        scanf("%d %d", &v1, &v2);

        com[v1][v2] = 1;
        com[v2][v1] = 1;
    }

    sol(1);

    printf("%d", ans);
}