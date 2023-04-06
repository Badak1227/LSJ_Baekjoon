#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie_ {
    struct trie_* alphabet[26];
    int end;
}trie;

trie* new_trie() {
    trie* tmp = (trie*)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++) {
        tmp->alphabet[i] = NULL;
    }
    tmp->end = 1;
    return tmp;
}

void insert(char str[], trie* head) {
    trie* cur = head;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        int index = 0;
        index = str[i] - 'a';
        
        if (cur->alphabet[index] == NULL) {
            cur->alphabet[index] = new_trie();
        }
        cur = cur->alphabet[index];
    }
    cur->end = 0;
}


int comp(char str[], trie* hear, trie* result) {
    trie* cur = hear;
    for (int i = 0; i < strlen(str); i++) {
        int index = 0;
        index = str[i] - 'a';
        if (cur->alphabet[index] != NULL) {
            cur = cur->alphabet[index];
        }
        else {
            return 0;
        }
    }

    if (cur->end == 0) {
        insert(str, result);
        return 1;
    }

    return 0;
}

void print_trie(trie* root, char str[], int index) {
    trie* cur = root;

    if (cur->end == 0) {
        str[index] = 0;
        printf("%s\n", str);
    }

    for (int i = 0; i < 26; i++) {
        if (cur->alphabet[i] != NULL) {
            str[index] = i + 'a';
            print_trie(cur->alphabet[i], str, index + 1);
        }
    }

}

void trie_free(trie* root) {
    trie* cur = root;
    for (int i = 0; i < 26; i++) {
        if (cur->alphabet[i] != NULL) {
            trie_free(cur->alphabet[i]);
        }
    }
    free(cur);
}

int main() {
    int N, M;
    trie* hear = new_trie();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        char tmp[51] = "";
        scanf("%s", tmp);
        insert(tmp, hear);
    }

    trie* contain = new_trie();
    int count = 0;
    for (int i = 0; i < M; i++) {
        char tmp[51] = "";
        scanf("%s", tmp);
        count += comp(tmp, hear, contain);
    }

    char str[51] = "";
    int index = 0;
    printf("%d\n", count);
    print_trie(contain, str, index);

    trie_free(hear);
    trie_free(contain);
}