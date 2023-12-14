#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Node in the Linked List
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to enqueue an element
void enqueue(struct Node** rear_ref, int data) {
    // Create a new Node
    struct Node* new_node = newNode(data);

    // If the queue is empty, set the new Node as the rear
    if (*rear_ref == NULL) {
        *rear_ref = new_node;
        new_node->next = NULL;
    } else {
        // Otherwise, link the new Node to the rear
        struct Node* current = *rear_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = NULL;
    }
}

// Function to dequeue an element
int dequeue(struct Node** front_ref) {
    // If the queue is empty, return -1
    if (*front_ref == NULL) {
        return -1;
    }

    // Store the data from the front Node
    int data = (*front_ref)->data;

    // Remove the front Node
    struct Node* temp = *front_ref;
    *front_ref = temp->next;
    free(temp);

    // Update the rear pointer if necessary
    if (*front_ref == NULL) {
        *front_ref = NULL;
    }

    return data;
}

// Function to peek at the front element
int peek(struct Node* front) {
    return front->data;
}

// Function to check if the queue is full
int isFull(struct Node* front) {
    return (front == NULL);
}

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to display the contents of the queue
void display(struct Node* front) {
    printf("Queue Contents: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    // Initialize the rear pointer
    struct Node* rear = NULL;

    do {
        int choice;
        printf("Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Full\n");
        printf("5. Is Empty\n");
        printf("6. Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int data;
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(&rear, data);
                break;

            case 2:
                
                if (data != -1) {
                    printf("Element dequeued: %d\n", data);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            case 3:
                if (rear == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Front element: %d\n", peek(rear));
                }
                break;

            case 4:
                if (isFull(rear)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 5:
                if (isEmpty(rear)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 6:
                display(rear);
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}
