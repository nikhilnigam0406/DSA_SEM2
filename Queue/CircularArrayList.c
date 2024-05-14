#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure to represent a circular queue
typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function to initialize a circular queue
CircularQueue* createCircularQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

// Function to check if the circular queue is full
int isFull(CircularQueue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the rear of the circular queue
void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
}

// Function to remove an element from the front of the circular queue
int dequeue(CircularQueue* queue) {
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
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

// Function to display the circular queue
void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = queue->front;
    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    CircularQueue* queue = createCircularQueue();
    int choice, item;

    while (choice != 4){
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } 

    return 0;
}
