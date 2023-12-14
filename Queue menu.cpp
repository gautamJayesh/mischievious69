#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
}Queue;

Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->arr = (int *)malloc(sizeof(int) * size);
    return queue;
}

int isFull(Queue *queue)
{
    if (queue->rear == queue->size - 1)
        return 1;
    return 0;
}

int isEmpty(Queue *queue)
{
    if (queue->rear == -1)
        return 1;
    return 0;
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear++;
    queue->arr[queue->rear] = value;
    printf("%d enqueued to queue\n", value);
}

int dequeue(Queue *queue)
{
    int value = -1;
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return value;
    }
    value = queue->arr[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    printf("%d dequeued from queue\n", value);
    return value;
}

int peek(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

void display(Queue *queue)
{
    int i;
    printf("Queue: ");
    for (i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->arr[i]);
    printf("\n");
}

int main()
{
    Queue *queue = createQueue(5);
    int choice, value;
    while (1)
    {
        printf("\n\nMenu:\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. peek\n");
        printf("4. isfull\n");
        printf("5. isempty\n");
        printf("6. display\n");
        printf("7. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            break;
        case 2:
            value = dequeue(queue);
            break;
        case 3:
            value = peek(queue);
            if (value != -1)
                printf("%d is at the front of the queue\n", value);
            break;
        case 4:
            if (isFull(queue))
                printf("Queue is Full\n");
            else
                printf("Queue is not Full\n");
            break;
        case 5:
            if (isEmpty(queue))
                printf("Queue is Empty\n");
            else
                printf("Queue is not Empty\n");
            break;
        case 6:
            display(queue);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
