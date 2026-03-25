#ifndef LEXER_H
#define LEXER_H

#define MAX_TOKENS 100

typedef enum {
    TOKEN_ID, TOKEN_NUM,
    TOKEN_PLUS, TOKEN_MINUS,
    TOKEN_MUL, TOKEN_DIV,
    TOKEN_ASSIGN,
    TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    char value[20];
} Token;

extern Token tokens[MAX_TOKENS];
extern int tokenCount;
#define MAX_SYMBOLS 100

extern char symbolTable[MAX_SYMBOLS][20];
extern int symCount;

void tokenize(char *input);

#endif