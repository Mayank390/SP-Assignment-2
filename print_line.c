#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct NODE {
    char *line;
    struct NODE *next; 
};

struct NODE *createNode(char *line) { 
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE)); 
    if (newNode) {
        newNode->line = line;
        newNode->next = NULL;
    }
    return newNode;
}

void insert_NODE(struct NODE **tail, char *line, int n) {
    struct NODE *newNode = createNode(line); 
    if (!newNode) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    if (*tail == NULL) {
        *tail = newNode;
    } else {
        struct NODE *current = *tail; 
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;

        if (n > 0) {
            struct NODE *temp = *tail; 
            *tail = (*tail)->next;
            free(temp->line);
            free(temp);
        }
    }
}

void freeLinkedList(struct NODE *head) { 
    while (head) {
        struct NODE *temp = head; 
        head = head->next;
        free(temp->line);
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value for n. Please provide a positive integer.\n");
        return 1;
    }

    struct NODE *tail = NULL; 

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        insert_NODE(&tail, strdup(buffer), n); 
    }

    struct NODE *current = tail; 
    while (current) {
        printf("%s", current->line);
        current = current->next;
    }

    freeLinkedList(tail);
    return 0;
}
