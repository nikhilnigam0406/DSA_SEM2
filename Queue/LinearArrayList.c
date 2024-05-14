#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        // Reset queue
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Function to peek at the element at the front of the queue without removing it
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No element to peek.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Function to display the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice, item;

    while (choice != 5) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                item = peek(queue);
                if (item != -1)
                    printf("Peeked item: %d\n", item);
                break;
            case 4:
                display(queue);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } 

    return 0;
}
