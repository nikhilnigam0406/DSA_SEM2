
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(Node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = *head;
    *head = (*head)->next;
    int poped = temp->data;
    free(temp);
    return poped;
}

int peek(Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return head->data;
}

Node* search(Node* head, int data) {
    Node* temp = head;
    int index = 0;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
        index++;
    }
    return NULL;
}

int isEmpty(Node* head) {
    return head == NULL;
}

int size(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printStack(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, popped;

    while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Search\n5. Print Stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                popped = pop(&head);
                if (popped != -1) {
                    printf("Popped data: %d\n", popped);
                }
                break;
            case 3:
                printf("The element at top of the stack is: %d\n", peek(head));
                break;
            case 4:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                Node* result = search(head, data);
                if (result != NULL) {
                    printf("Data found at index: %d\n", result - head);
                } else {
                    printf("Data not found\n");
                }
                break;
            case 5:
                printStack(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}