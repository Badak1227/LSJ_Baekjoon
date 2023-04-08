#include <stdio.h>
#include <stdlib.h>

int count = 0;

typedef struct trie_ {
    struct trie_* alphabet[26];
}trie;

trie* new_trie() {
    trie* tmp = (trie*)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++) {
        tmp->alphabet[i] = NULL;
    }
    return tmp;
}

void insert(char str[], int end, trie* head) {
    trie* cur = head;

    for (int i = 0; i <=  end; i++) {
        int index = str[i] - 'a';
        if (!cur->alphabet[index]) {
            cur->alphabet[index] = new_trie();
            count++;
        }
        cur = cur->alphabet[index];
    }
}

int main() {
    char str[1001] = "";
    trie* str_trie = new_trie();
    scanf("%s", str);

    int len = 0;
    char c;
    while ((c = getchar()) != '\n') {
        str[len++] = c;
    }

    for (int i = 0; str[i]; i++) {
        for (int j = i; str[j]; j++) {
            insert(str + i, j-i, str_trie);
        }
    }

    printf("%d", count);
}