#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int pos = 0;

Node* createNode(char *val) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->value, val);
    node->left = node->right = NULL;
    return node;
}

Token current() {
    return tokens[pos];
}

void advance() {
    pos++;
}

Node* parseFactor() {
    Token t = current();

    if (t.type == TOKEN_ID || t.type == TOKEN_NUM) {
        advance();
        return createNode(t.value);
    }

    if (t.type == TOKEN_LPAREN) {
        advance();
        Node* node = parseExpression();

        if (current().type == TOKEN_RPAREN) {
            advance();
        } else {
            printf("Error: Missing closing parenthesis\n");
            exit(1);
        }

        return node;
    }

    printf("Error: Invalid factor\n");
    exit(1);
}

Node* parseTerm() {
    Node* node = parseFactor();

    while (current().type == TOKEN_MUL || current().type == TOKEN_DIV) {
        Token op = current();
        advance();

        Node* right = parseFactor();
        Node* newNode = createNode(op.value);

        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }

    return node;
}

Node* parseExpression() {
    Node* node = parseTerm();

    while (current().type == TOKEN_PLUS || current().type == TOKEN_MINUS) {
        Token op = current();
        advance();

        Node* right = parseTerm();
        Node* newNode = createNode(op.value);

        newNode->left = node;
        newNode->right = right;
        node = newNode;
    }
    if (current().type != TOKEN_END && current().type != TOKEN_RPAREN) {
    printf("Error: Invalid syntax near '%s'\n", current().value);
    exit(1);
}
    return node;
}

Node* parseStatement() {
    Token t = current();

    if (t.type == TOKEN_ID && tokens[pos+1].type == TOKEN_ASSIGN) {
        Node* left = createNode(t.value);
        advance();
        advance();

        Node* right = parseExpression();

        Node* assignNode = createNode("=");
        assignNode->left = left;
        assignNode->right = right;

        return assignNode;
    }

    return parseExpression();
}
