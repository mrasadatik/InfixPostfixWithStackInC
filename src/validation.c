#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "../include/helpers.h"

void validate_input(const char *infix) {
    if (strlen(infix) == 0) {
        errno = EINVAL;
        perror("Error: Input expression is empty");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (!isalnum(ch) && !is_operator(ch) && ch != '(' && ch != ')' && !isspace(ch)) {
            errno = EINVAL;
            fprintf(stderr, "Error: Invalid character '%c' in expression\n", ch);
            exit(EXIT_FAILURE);
        }
    }
}

void check_parentheses(const char *infix) {
    int balance = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            balance++;
        } else if (infix[i] == ')') {
            balance--;
            if (balance < 0) {
                errno = EINVAL;
                perror("Error: Mismatched parentheses (extra closing parenthesis)");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (balance != 0) {
        errno = EINVAL;
        perror("Error: Mismatched parentheses (unclosed opening parenthesis)");
        exit(EXIT_FAILURE);
    }
}
