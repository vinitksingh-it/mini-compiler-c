#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"

int main() {
    char input[100];

    printf("Enter expression: ");
    fgets(input, sizeof(input), stdin);

    tokenize(input);

    printf("\nTokens:\n");
    for (int i = 0; i < tokenCount; i++) {
        printf("%s ", tokens[i].value);
    }

    printf("\nSymbol Table:\n");
    for (int i = 0; i < symCount; i++) {
    printf("%s\n", symbolTable[i]);
}
    Node* root = parseStatement();
    if (root == NULL) {
    printf("Error: Parsing failed\n");
    return 1;
}

    printf("\n\nThree Address Code:\n");
    generateCode(root);

    return 0;
}