#include <stdio.h>
#include <ctype.h>
#include <string.h>
// Function to check if a string is a keyword
int isKeyword(char* str) {
    if (strcmp(str, "int") == 0 || strcmp(str, "return") == 0 || strcmp(str, "if") == 0) {
        return 1;
    }
    return 0;
}
// Lexer function to tokenize the input
void lexer(char* code) {
    char token[100];
    int index = 0;
    for (int i = 0; code[i] != '\0'; i++) {
        if (isspace(code[i])) continue;
        // Check for identifiers or keywords
        if (isalpha(code[i])) {
            while (isalpha(code[i])) {
                token[index++] = code[i++];
            }
            token[index] = '\0';
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            index = 0;
            i--;
        }
        // Check for numbers
        else if (isdigit(code[i])) {
            while (isdigit(code[i])) {
                token[index++] = code[i++];
            }
            token[index] = '\0';
            printf("Number: %s\n", token);
            index = 0;
            i--;
        }
        // Check for operators
        else if (code[i] == '+' || code[i] == '-') {
            printf("Operator: %c\n", code[i]);
        }
    }
}
int main() {
    char code[] = "int x = (10 + 20) + 30;";
    lexer(code);
    return 0;
}
