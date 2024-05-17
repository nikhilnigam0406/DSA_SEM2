#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    } else {
        ptr->data = item;
        if (front == NULL) {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        } else {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}

int dequeue() {
    if (front == NULL) {
        printf("\nUNDERFLOW\n");
        return -1;
    } else {
        struct node *ptr = front;
        int item = front->data;
        front = front->next;
        free(ptr);
        return item;
    }
}

void display() {
    struct node *ptr = front;
    while (ptr!= NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("\n Queue using Linked List\n");
    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                printf("Remove element is :%d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong\n");
        }
    }
    return 0;
}
