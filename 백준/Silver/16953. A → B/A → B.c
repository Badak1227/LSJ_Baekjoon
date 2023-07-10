#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct queue {
    node* start;
    node* end;
}queue;

char visited[125000001] = { 0 };

queue num;

void input(int next) {
    visited[next / 8] |= 1 << (next % 8);

    if (num.start == NULL && num.end == NULL) {
        num.start = (node*)malloc(sizeof(node));

        num.start->data = next;
        num.start->next = NULL;

        num.end = num.start;
        return;
    }

    num.end->next = (node*)malloc(sizeof(node));
    num.end = num.end->next;

    num.end->data = next;
    num.end->next = NULL;
}

void delete() {
    node* tmp = num.start;

    num.start = num.start->next;

    if (num.start == NULL) num.end = num.start;

    free(tmp);
}

void freequeue() {

    while (num.start != NULL) {
        node* tmp = num.start;

        num.start = num.start->next;

        free(tmp);
    }
}

void sol(long long A, long long B) {
    
    num.start = NULL;
    num.end = NULL;

    int len = 1, ans = 1;
    
    if(A == B){
        printf("%d", ans);
        return;
    }
    
    input(A);

    while (len) {
        int tmplen = 0;

        while (len--) {
            long long cur = num.start->data;

            delete();

            if (cur * 10 + 1 <= B) {

                if (cur * 10 + 1 == B) {
                    printf("%d", ans + 1);
                    freequeue();
                    return;
                }

                if (!(visited[(cur * 10 + 1) / 8] & 1 << (cur * 10 + 1) % 8)) {
                    input(cur * 10 + 1);
                    tmplen++;
                }
            }
            
            if (cur * 2 <= B) {

                if (cur * 2 == B) {
                    printf("%d", ans + 1);
                    freequeue();
                    return;
                }

                if (!(visited[(cur * 2) / 8] & 1 << (cur * 2) % 8)) {
                    input(cur * 2);
                    tmplen++;
                }
            }
            
            
        }

        len = tmplen;
        ans++;
    }

    printf("-1");
}

int main() {
    long long A, B;
    

    scanf("%lld %lld", &A, &B);

    sol(A, B);
}