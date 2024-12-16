#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "../include/stack.h"
#include "../include/helpers.h"
#include "../include/validation.h"

void infix_to_postfix(const char *infix, char *postfix) {
    struct StackNode *stack = NULL;
    int i = 0, j = 0;

    validate_input(infix);
    check_parentheses(infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isspace(ch)) {
            i++;
            continue;
        }

        if (isalnum(ch)) {
            postfix[j++] = ch;
            postfix[j++] = ' ';
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!is_empty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            if (!is_empty(stack) && peek(stack) == '(') {
                pop(&stack);
            } else {
                errno = EINVAL;
                perror("Error: Mismatched parentheses");
                exit(EXIT_FAILURE);
            }
        } else if (is_operator(ch)) {
            while (!is_empty(stack) && precedence(peek(stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, ch);
        }
        i++;
    }

    while (!is_empty(stack)) {
        char top = pop(&stack);
        if (top == '(') {
            errno = EINVAL;
            perror("Error: Mismatched parentheses");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = top;
        postfix[j++] = ' ';
    }

    if (j > 0 && postfix[j - 1] == ' ') j--;

    postfix[j] = '\0';
}
