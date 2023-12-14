#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
int isOperator(char ch);
int getPrecedence(char ch);
void infixToPrefix(char infix[], char prefix[]);

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infixToPrefix(infix, prefix);

    // Display the resulting prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operandStack;
    struct Stack operatorStack;
    operandStack.top = -1;
    operatorStack.top = -1;

    int infixLength = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    for (int i = infixLength - 1; i >= 0; i--) {
        char currentChar = infix[i];

        if (isOperator(currentChar)) {
            // Pop operators from the stack until an operator with lower precedence is encountered
            while (operatorStack.top != -1 && getPrecedence(operatorStack.items[operatorStack.top]) > getPrecedence(currentChar)) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, currentChar);
        } else if (currentChar == ')' || currentChar == '(') {
            push(&operatorStack, currentChar);
        } else {
            // If the character is an operand, copy it to the result
            prefix[prefixIndex++] = currentChar;
        }
    }

    // Pop any remaining operators from the stack
    while (operatorStack.top != -1) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';

    // Reverse the result to get the final prefix expression
    strrev(prefix);
}

