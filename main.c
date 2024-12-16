#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/conversion.h"

int main() {
    char *infix = (char *)malloc(1024 * sizeof(char));
    char *postfix = NULL;

    if (!infix) {
        perror("Error: Memory allocation failed");
        return EXIT_FAILURE;
    }

    printf("Enter a valid infix expression: ");
    if (!fgets(infix, 1024, stdin)) {
        perror("Error: Unable to read input");
        free(infix);
        return EXIT_FAILURE;
    }

    infix[strcspn(infix, "\n")] = '\0';

    size_t postfix_size = strlen(infix) * 2 + 1;
    postfix = (char *)malloc(postfix_size);
    if (!postfix) {
        perror("Error: Memory allocation failed");
        free(infix);
        return EXIT_FAILURE;
    }

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    free(infix);
    free(postfix);

    return 0;
}
