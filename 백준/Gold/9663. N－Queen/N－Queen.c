#include <stdio.h>

int N, board[16][16] = { 0 }, cnt = 0;

int crosscheck(int row, int col) {
    int check = 1, con = 1;

    while (con) {
        
        con = 0;

        if (row + check <= N && col + check <= N) {
            con = 1;
            if (board[row + check][col + check] == 1) {
                return 0;
            }
        }
        
        if (row + check <= N && col - check >= 1) {
            con = 1;
            if (board[row + check][col - check] == 1) {
                return 0;
            }
        }
        
        if (row - check >= 1 && col + check <= N) {
            con = 1;
            if (board[row - check][col + check] == 1) {
                return 0;
            }
        }

        if (row - check >= 1 && col - check >= 1) {
            con = 1;
            if (board[row - check][col - check] == 1) {
                return 0;
            }
        }

        check++;
    }

    return 1;
}

void sol(int col) {

    if (col > N) {
        cnt++;

        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!board[i][0] && crosscheck(i, col)) {
            board[i][0] = 1;
            board[i][col] = 1;
            
            sol(col + 1);

            board[i][0] = 0;
            board[i][col] = 0;
        }
        
    }
}

int main() {

    scanf("%d", &N);

    sol(1);

    printf("%d", cnt);
}