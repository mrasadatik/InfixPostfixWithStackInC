#include "../include/helpers.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Check if a character is an operator
bool is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
