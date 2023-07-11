#include <stdio.h>

char alphabet[26][2] = { 0 };

void sol1(char cur) {
    printf("%c", cur);

    if (alphabet[cur - 'A'][0]) {
        sol1(alphabet[cur - 'A'][0]);
    }

    if (alphabet[cur - 'A'][1]) {
        sol1(alphabet[cur - 'A'][1]);
    }
}

void sol2(char cur) {
    if (alphabet[cur - 'A'][0]) {
        sol2(alphabet[cur - 'A'][0]);
    }

    printf("%c", cur);

    if (alphabet[cur - 'A'][1]) {
        sol2(alphabet[cur - 'A'][1]);
    }
}

void sol3(char cur) {
    if (alphabet[cur - 'A'][0]) {
        sol3(alphabet[cur - 'A'][0]);
    }

    if (alphabet[cur - 'A'][1]) {
        sol3(alphabet[cur - 'A'][1]);
    }

    printf("%c", cur);
}

int main() {
    int N;
    
    scanf("%d", &N);

    while (N--) {
        char head, left, right;

        scanf(" %c %c %c", &head, &left, &right);

        if (left != '.') {
            alphabet[head - 'A'][0] = left;
        }

        if (right != '.') {
            alphabet[head - 'A'][1] = right;
        }
    }

    sol1('A');
    printf("\n");
    sol2('A');
    printf("\n");
    sol3('A');
}