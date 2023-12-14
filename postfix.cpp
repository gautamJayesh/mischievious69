#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function prototypes
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int evaluatePostfix(char postfix[]);

int main() {
    char postfix[MAX_SIZE];

    // Input postfix expression
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    // Evaluate postfix expression
    int result = evaluatePostfix(postfix);

    // Display the result
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack operandStack;
    operandStack.top = -1;

    int postfixLength = strlen(postfix);

    for (int i = 0; i < postfixLength; i++) {
        char currentChar = postfix[i];

        if (isdigit(currentChar)) {
            // If the character is a digit, convert it to an integer and push onto the stack
            push(&operandStack, currentChar - '0');
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            // If the character is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);

            switch (currentChar) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&operandStack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", currentChar);
                    exit(EXIT_FAILURE);
            }
        }
    }

    // The final result should be on top of the stack
    return pop(&operandStack);
}

