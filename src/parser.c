#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "parser.h"

#define TYPE_INT 0
#define TYPE_OPR 1
#define TYPE_LIST 2

struct node {
    int type;
    char *val;
    struct node *left;
    struct node *right;
};

bool isOperator(char c);

/*
    Given an array of tokens (strings),
    Converts into a binary AST.
    Returns syntax errors.
*/
struct node *parse(char **tokens, int ntokens) {
    for (int i = 0; i < ntokens; ++i) {
        char *token = tokens[i];
        if (strlen(token) == 1 && isOperator(token[0])) {
            Node n = malloc(sizeof(*n));
            n->type = TYPE_OPR;
            n->val = token;
        }

    }
    return NULL;
}

// Check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}