#include <stdio.h>
#include <ctype.h>
#include <string.h>
// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
// Check if the expression is valid
int isValidExpression(char* expression) {
    int i = 0;
    // Check for identifier
    if (!isalpha(expression[i])) {
        printf("Syntax Error: Expected an identifier\n");
        return 0;
    }
    i++;
    // Check for assignment operator
    if (expression[i] != '=') {
        printf("Syntax Error: Expected '=' operator\n");
        return 0;
    }
    i++;
    // Check if the expression is valid (consisting of numbers or operators)
    while (expression[i] != '\0' && expression[i] != ';') {
        if (!isdigit(expression[i]) && !isOperator(expression[i])) {
            printf("Syntax Error: Invalid expression\n");
            return 0;
        }
        i++;
    }
    // Check for semicolon at the end
    if (expression[i] != ';') {
        printf("Syntax Error: Expected ';'\n");
        return 0;
    }
    printf("Syntax is valid.\n");
    return 1;
}
int main() {
    char statement[] = "x = 10 + 5;";
    isValidExpression(statement);
    return 0;
}