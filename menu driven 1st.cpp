#include <stdio.h>
#include <stdlib.h>

// Stack structure for array implementation
#define MAX_SIZE 10

struct ArrayStack {
    int arr[MAX_SIZE];
    int top;
};

// Node structure for linked list implementation
struct Node {
    int data;
    struct Node* next;
};

// Stack structure for linked list implementation
struct LinkedListStack {
    struct Node* top;
};

// Function prototypes
void initArrayStack(struct ArrayStack* stack);
void pushArray(struct ArrayStack* stack, int value);
int popArray(struct ArrayStack* stack);
int peekArray(struct ArrayStack* stack);
int isFullArray(struct ArrayStack* stack);
int isEmptyArray(struct ArrayStack* stack);
void displayArray(struct ArrayStack* stack);

void initLinkedListStack(struct LinkedListStack* stack);
void pushLinkedList(struct LinkedListStack* stack, int value);
int popLinkedList(struct LinkedListStack* stack);
int peekLinkedList(struct LinkedListStack* stack);
int isEmptyLinkedList(struct LinkedListStack* stack);
void displayLinkedList(struct LinkedListStack* stack);

// Main function
int main() {
    int choice, value;
    struct ArrayStack arrayStack;
    struct LinkedListStack linkedListStack;

    initArrayStack(&arrayStack);
    initLinkedListStack(&linkedListStack);

    do {
        // Display menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push (Array)\n");
        printf("2. Pop (Array)\n");
        printf("3. Peek (Array)\n");
        printf("4. Is Full (Array)\n");
        printf("5. Is Empty (Array)\n");
        printf("6. Display (Array)\n");
        printf("7. Push (Linked List)\n");
        printf("8. Pop (Linked List)\n");
        printf("9. Peek (Linked List)\n");
        printf("10. Is Empty (Linked List)\n");
        printf("11. Display (Linked List)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushArray(&arrayStack, value);
                break;

            case 2:
                value = popArray(&arrayStack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peekArray(&arrayStack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                if (isFullArray(&arrayStack))
                    printf("The stack is full.\n");
                else
                    printf("The stack is not full.\n");
                break;

            case 5:
                if (isEmptyArray(&arrayStack))
                    printf("The stack is empty.\n");
                else
                    printf("The stack is not empty.\n");
                break;

            case 6:
                displayArray(&arrayStack);
                break;

            case 7:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushLinkedList(&linkedListStack, value);
                break;

            case 8:
                value = popLinkedList(&linkedListStack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 9:
                value = peekLinkedList(&linkedListStack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 10:
                if (isEmptyLinkedList(&linkedListStack))
                    printf("The stack is empty.\n");
                else
                    printf("The stack is not empty.\n");
                break;

            case 11:
                displayLinkedList(&linkedListStack);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

// Array implementation functions
void initArrayStack(struct ArrayStack* stack) {
    stack->top = -1;
}

void pushArray(struct ArrayStack* stack, int value) {
    if (!isFullArray(stack)) {
        stack->arr[++stack->top] = value;
        printf("%d pushed into the stack.\n", value);
    } else {
        printf("Stack overflow. Cannot push %d.\n", value);
    }
}

int popArray(struct ArrayStack* stack) {
    if (!isEmptyArray(stack)) {
        return stack->arr[stack->top--];
    } else {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
}

int peekArray(struct ArrayStack* stack) {
    if (!isEmptyArray(stack)) {
        return stack->arr[stack->top];
    } else {
        printf("Cannot peek from an empty stack.\n");
        return -1;
    }
}

int isFullArray(struct ArrayStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmptyArray(struct ArrayStack* stack) {
    return stack->top == -1;
}

void displayArray(struct ArrayStack* stack) {
    if (!isEmptyArray(stack)) {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    } else {
        printf("The stack is empty.\n");
    }
}

// Linked list implementation functions
void initLinkedListStack(struct LinkedListStack* stack) {
    stack->top = NULL;
}

void pushLinkedList(struct LinkedListStack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into the stack.\n", value);
}

int popLinkedList(struct LinkedListStack* stack) {
    if (!isEmptyLinkedList(stack)) {
        struct Node* temp = stack->top;
        int value = temp->data;
        stack->top = temp->next;
        free(temp);
        return value;
    } else {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
}

int peekLinkedList(struct LinkedListStack* stack) {
    if (!isEmptyLinkedList(stack)) {
        return stack->top->data;
    } else {
        printf("Cannot peek from an empty stack.\n");
        return -1;
    }
}

int isEmptyLinkedList(struct LinkedListStack* stack) {
    return stack->top == NULL;
}

void displayLinkedList(struct LinkedListStack* stack) {
    if (!isEmptyLinkedList(stack)) {
        printf("Stack elements: ");
        struct Node* current = stack->top;
        while (current != NULL) 
		{
            printf("%d ", current->data);
            current = current->next;
        
		}
	}
}

       

