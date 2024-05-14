#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
Node* insertAtBeginning(Node* last, int data) {
    Node* newNode = createNode(data);
    if (last == NULL) {
        // If the list is empty, make the new node as the last node
        last = newNode;
        last->next = last; // Point to itself
    } else {
        // Otherwise, insert the new node at the beginning
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

// Function to insert a node at the end of the circular linked list
Node* insertAtEnd(Node* last, int data) {
    if (last == NULL) {
        return insertAtBeginning(last, data);
    }
    Node* newNode = createNode(data);
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

// Function to display the circular linked list
void display(Node* last) {
    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }
    Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    Node* last = NULL;
    int choice, data;

    while (choice != 4) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                last = insertAtBeginning(last, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                last = insertAtEnd(last, data);
                break;
            case 3:
                display(last);
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
