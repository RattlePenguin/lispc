/*
This file converts string input from the user into a array of valid tokens.
    + 1 2 // allowed
    + 1 2 3 // not allowed
    (- (+ 1 2) 1) // allowed
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 128
#define MAX_TOKEN_SIZE 128

// Func Prototypes
char **tokenise(char *input);
void printTokens(char **tokens);
void freeTokens(char **tokens);
int isOperator(char *token);

int main(int argc, char *argv[]) {
    char input[1000];
    strcpy(input, "(+ 5 20)");
    printf("Input: %s\n", input);

    char **tokens = tokenise(input);
    printTokens(tokens);
    freeTokens(tokens);
    
    return 0;
}

// Converts a string into a array of valid tokens
char **tokenise(char *input) {
    char **tokens = calloc(sizeof(char *), MAX_TOKENS);
    int ntokens = 0;

    char buf[MAX_TOKEN_SIZE];
    int index = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (isspace(input[i])) {
            continue;
        } else {
            while (!isspace(input[i])) {
                buf[index++] = input[i++];
            }
            buf[index] = '\0';
            
            char *token = malloc(sizeof(char) * strlen(buf) + 1);
            strcpy(token, buf);
            tokens[ntokens++] = token;

            index = 0;
            --i;
        }
    }
    return tokens;
}

// Prints an array of tokens (strings)
void printTokens(char **tokens) {
    printf("[");
    for (int i = 0; tokens[i] != NULL; ++i) {
        printf("\"%s\"", tokens[i]);
        if (tokens[i + 1] != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Frees an array of tokens
void freeTokens(char **tokens) {
    for (int i = 0; tokens[i] != NULL; ++i) {
        free(tokens[i]);
    }
    free(tokens);
}

// Checks if a given token is a valid operator
int isOperator(char *token) {
    char *operators[4] = {"+", "-", "*", "/"};
    for (int i = 0; i < 4; ++i) {
        if (strcmp(token, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
