#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "codegen.h"

int tempCount = 1;

char* generate(Node* node) {
    if (!node->left && !node->right) {
        return node->value;
    }

    // Handle assignment (=)
    if (strcmp(node->value, "=") == 0) {
        char* right = generate(node->right);
        printf("%s = %s\n", node->left->value, right);
        return node->left->value;
    }

    char* left = generate(node->left);
    char* right = generate(node->right);

    // 🔥 CONSTANT FOLDING (Optimization)
    if (isdigit(left[0]) && isdigit(right[0])) {
        int l = atoi(left);
        int r = atoi(right);
        int result;

        if (strcmp(node->value, "+") == 0) result = l + r;
        else if (strcmp(node->value, "-") == 0) result = l - r;
        else if (strcmp(node->value, "*") == 0) result = l * r;
        else if (strcmp(node->value, "/") == 0) result = l / r;

        char* resStr = (char*)malloc(10);
        sprintf(resStr, "%d", result);

        return resStr;
    }

    char* temp = (char*)malloc(10);
    sprintf(temp, "t%d", tempCount++);

    printf("%s = %s %s %s\n", temp, left, node->value, right);

    return temp;
}

void generateCode(Node* root) {
    generate(root);
}