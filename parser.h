#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef struct Node {
    char value[20];
    struct Node *left, *right;
} Node;

Node* parseExpression();
Node* parseStatement();

#endif