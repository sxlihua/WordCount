#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

void count_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int char_count = 0;
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        char_count += strlen(buffer);
    }

    fclose(file);
    printf("×Ö·ûÊý£º%d\n", char_count);
}

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int word_count = 0;
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        char *token = strtok(buffer, " ,\t\n");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ,\t\n");
        }
    }

    fclose(file);
    printf("µ¥´ÊÊý£º%d\n", word_count);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s -c|-w <input_file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count_characters(argv[2]);
    } else if (strcmp(argv[1], "-w") == 0) {
        count_words(argv[2]);
    } else {
        fprintf(stderr, "Invalid parameter: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
