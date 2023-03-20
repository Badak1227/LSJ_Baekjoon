#include <stdio.h>
#include <stdlib.h>

char w[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};

char b[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};

int compare_w(char** board, int row, int column) {
    int answer = 0;
    int r = row, c = column;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (w[i][j] != board[r][c++]) {
                answer++;
            }
        }
        r++; c = column;
    }
    return answer;
}

int compare_b(char** board, int row, int column) {
    int answer = 0;
    int r = row, c = column;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (b[i][j] != board[r][c++]) {
                answer++;
            }
        }
        r++; c = column;
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
            answer = compare_w(board, i, j);
            min = (answer < min) ? answer : min;
            answer = compare_b(board, i, j);
            min = (answer < min) ? answer : min;
        }
    }

    printf("%d", min);
}