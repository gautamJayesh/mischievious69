#include <stdio.h>

#define MAX_SIZE 5

// Structure for the circular queue using array
struct CircularQueue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function prototypes
void enqueue(struct CircularQueue* queue, int value);
int dequeue(struct CircularQueue* queue);
int isFull(struct CircularQueue* queue);
int isEmpty(struct CircularQueue* queue);
void display(struct CircularQueue* queue);

// Main function
int main() {
    int choice, value;
    struct CircularQueue queue;

    // Initialize the circular queue
    queue.front = queue.rear = -1;

    do {
        // Display menu
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Is Full\n");
        printf("4. Is Empty\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;

            case 2:
                value = dequeue(&queue);
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;

            case 3:
                if (isFull(&queue))
                    printf("The queue is full.\n");
                else
                    printf("The queue is not full.\n");
                break;

            case 4:
                if (isEmpty(&queue))
                    printf("The queue is empty.\n");
                else
                    printf("The queue is not empty.\n");
                break;

            case 5:
                display(&queue);
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

// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        // If the queue is empty, set front and rear to 0
        queue->front = queue->rear = 0;
    } else {
        // Increment rear and take the modulo to wrap around
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = value;
    printf("Enqueued value: %d\n", value);
}

// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue.\n");
        return -1;
    }

    int value = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        // If there is only one element in the queue
        queue->front = queue->rear = -1;
    } else {
        // Increment front and take the modulo to wrap around
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return value;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) ||
           (queue->front == queue->rear + 1);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

