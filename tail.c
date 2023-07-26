#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256

typedef struct {
    char** lines;
    int size;
    int index;
    int count;
} CircularBuffer;

void initCircularBuffer(CircularBuffer* buffer, int n) {
    buffer->lines = (char*)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        buffer->lines[i] = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    buffer->size = n;
    buffer->index = 0;
    buffer->count = 0;
}

void destroyCircularBuffer(CircularBuffer* buffer) {
    for (int i = 0; i < buffer->size; i++) {
        free(buffer->lines[i]);
    }
    free(buffer->lines);
}

void insertLine(CircularBuffer* buffer, const char* line) {
    strcpy(buffer->lines[buffer->index], line);
    buffer->index = (buffer->index + 1) % buffer->size;
    buffer->count = (buffer->count < buffer->size) ? buffer->count + 1 : buffer->size;
}

void printLastNLines(CircularBuffer* buffer) {
    int start = (buffer->index + buffer->size - buffer->count) % buffer->size;
    for (int i = 0; i < buffer->count; i++) {
        printf("%s", buffer->lines[start]);
        start = (start + 1) % buffer->size;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value of n. Please provide a positive integer.\n");
        return 1;
    }

    CircularBuffer buffer;
    initCircularBuffer(&buffer, n);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        insertLine(&buffer, line);
    }

    printLastNLines(&buffer);

    destroyCircularBuffer(&buffer);

    return 0;
}
