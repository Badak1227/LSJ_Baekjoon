#include <stdio.h>
#include <stdlib.h>

int compare(char** board, int row, int column) {
    int answer = 0;
    int r = row, c = column;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            answer+=(board[r][c] == 'W')^((r+c)%2 == 0);
            c++;
        }
        r++; c = column;
    }
    if(answer > 32){
        return 64-answer;
    }
    return answer;
}

int main() {
    int N, M, min = 64;
    scanf("%d %d", &N, &M);
    char** board;
    board = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        board[i] = (char*)malloc(M * sizeof(char));
    }
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    int answer = 64;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            answer = compare(board, i, j);
            min = (answer < min) ? answer : min;
        }
    }

    printf("%d", min);
}