#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    struct tree* prev;
    long long int data;
    struct tree* next;
}tree;

int contain(long long int num1, tree* groupA) {
    if (groupA->data== num1) {
        return 1;
    }
    if (groupA->data < num1) {
        if (groupA->next != NULL) {
            return contain(num1, groupA->next);
        }
    }
    else {
        if (groupA->prev != NULL) {
            return contain(num1, groupA->prev);
        }
    }
    
    return 0;
}

void add(tree* cur, tree* new) {
    if ((cur->data) < (new->data)) {
        if (cur->next != NULL) {
            add(cur->next, new);
        }
        else {
            cur->next = new;
        }
    }
    else {
        if (cur->prev != NULL) {
            add(cur->prev, new);
        }
        else {
            cur->prev = new;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    tree* head = (tree*)malloc(sizeof(tree));
    long long int num1;
    scanf("%lld", &num1);
    head->data = num1;
    head->next = NULL;
    head->prev = NULL;

    for (int i = 1; i < N; i++) {
        tree* tmp = (tree*)malloc(sizeof(tree));
        scanf("%lld", &num1);
        tmp->data = num1;
        tmp->next = NULL;
        tmp->prev = NULL;
        add(head, tmp);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        long long int num2;
        scanf("%lld", &num2);
        int result = contain(num2, head);
        printf("%d ", result);
    }
}