#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

Node newNode(int type, void *value) {
    Node new = malloc(sizeof(new));
    new->type = type;
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node 