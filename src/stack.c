#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../include/stack.h"

static struct StackNode *create_node(char data) {
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (!node) {
        errno = ENOMEM;
        perror("Error: Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

bool is_empty(struct StackNode *top) {
    return top == NULL;
}

void push(struct StackNode **top, char data) {
    struct StackNode *node = create_node(data);
    node->next = *top;
    *top = node;
}

char pop(struct StackNode **top) {
    if (is_empty(*top)) {
        errno = EINVAL;
        perror("Error: Stack underflow");
        exit(EXIT_FAILURE);
    }
    struct StackNode *temp = *top;
    char popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

char peek(struct StackNode *top) {
    if (is_empty(top)) {
        errno = EINVAL;
        perror("Error: Stack underflow during peek");
        exit(EXIT_FAILURE);
    }
    return top->data;
}
