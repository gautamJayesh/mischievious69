#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
char peek(struct Stack* stack);
int isOperator(char ch);
int getPrecedence(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Display the resulting postfix expression
    printf("Postfix expression: %s\n", postfix);

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

// Function to peek the top item of the stack
char peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
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

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    operatorStack.top = -1;

    int infixLength = strlen(infix);
    int postfixIndex = 0;

    for (int i = 0; i < infixLength; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            // If the character is an operand, copy it to the result
            postfix[postfixIndex++] = currentChar;
        } else if (currentChar == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            push(&operatorStack, currentChar);
        } else if (currentChar == ')') {
            // If the character is a closing parenthesis, pop and append operators from the stack
            // until an opening parenthesis is encountered
            while (operatorStack.top != -1 && peek(&operatorStack) != '(') {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            // Pop the opening parenthesis from the stack
            pop(&operatorStack);
        } else if (isOperator(currentChar)) {
            // If the character is an operator, pop and append operators from the stack
            // until an operator with lower precedence is encountered or the stack is empty
            while (operatorStack.top != -1 && peek(&operatorStack) != '(' &&
                   getPrecedence(peek(&operatorStack)) >= getPrecedence(currentChar)) {
                postfix[postfixIndex++] = pop(&operatorStack);
            }
            // Push the current operator onto the stack
            push(&operatorStack, currentChar);
        }
    }

    // Pop any remaining operators from the stack and append them to the result
    while (operatorStack.top != -1) {
        postfix[postfixIndex++] = pop(&operatorStack);
    }

    // Null-terminate the postfix expression
    postfix[postfixIndex] = '\0';
}

