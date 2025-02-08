#include <stdio.h>
#include <stdlib.h>

#define TYPE_INT 0
#define TYPE_OPR 1
#define TYPE_LIST 2

struct node {
    int type;
    char *val;
    struct node *left;
    struct node *right;
};

/*
    Given an array of tokens (strings),
    Converts into a binary AST.
    Returns syntax errors.
*/
struct node *parse(char **tokens, int ntokens) {
    for (int i = 0; i < ntokens; ++i) {
                
    }
    return root;
}

