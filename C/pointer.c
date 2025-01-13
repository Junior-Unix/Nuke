#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define CONTEXT_WORDS 2

void print_context(char *words[], int start, int end, int total_words) {
    for (int i = start; i <= end && i < total_words; i++) {
        if (i >= 0) {
            printf("%s ", words[i]);
        }
    }
    printf("\n");
}

int main() {
    FILE *file;
    char filename[] = "zelda.txt";
    char word[MAX_WORD_LENGTH];
    char *words[1000];
    char buffer[MAX_WORD_LENGTH];
    int word_count = 0;

    printf("Enter the word to search: ");
    scanf("%s", word);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        words[word_count] = strdup(buffer);
        word_count++;
    }
    fclose(file);

    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], word) == 0) {
            int start = i - CONTEXT_WORDS;
            int end = i + CONTEXT_WORDS;
            print_context(words, start, end, word_count);
        }
    }

    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}