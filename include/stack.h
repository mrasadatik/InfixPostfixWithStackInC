#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct StackNode {
    char data;
    struct StackNode *next;
};

bool is_empty(struct StackNode *top);
void push(struct StackNode **top, char data);
char pop(struct StackNode **top);
char peek(struct StackNode *top);

#endif // STACK_H
