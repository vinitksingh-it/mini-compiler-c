#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

Token tokens[MAX_TOKENS];
int tokenCount = 0;
char symbolTable[MAX_SYMBOLS][20];
int symCount = 0;

void addToken(TokenType type, char *value) {
    tokens[tokenCount].type = type;
    strcpy(tokens[tokenCount].value, value);
    tokenCount++;
}

void tokenize(char *input) {
    int i = 0;
    char buffer[20];

    while (input[i]) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier
        if (isalpha(input[i])) {
            int j = 0;
            while (isalnum(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            addToken(TOKEN_ID, buffer);

            // Add to symbol table if not already present
            int found = 0;
            for (int k = 0; k < symCount; k++) {
                if (strcmp(symbolTable[k], buffer) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(symbolTable[symCount++], buffer);
            }
        }

        // Number
        else if (isdigit(input[i])) {
            int j = 0;
            while (isdigit(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            addToken(TOKEN_NUM, buffer);
        }

        else {
            switch (input[i]) {
                case '+': addToken(TOKEN_PLUS, "+"); break;
                case '-': addToken(TOKEN_MINUS, "-"); break;
                case '*': addToken(TOKEN_MUL, "*"); break;
                case '/': addToken(TOKEN_DIV, "/"); break;
                case '=': addToken(TOKEN_ASSIGN, "="); break;
                case '(': addToken(TOKEN_LPAREN, "("); break;
                case ')': addToken(TOKEN_RPAREN, ")"); break;
            }
            i++;
        }
    }

    addToken(TOKEN_END, "END");
}