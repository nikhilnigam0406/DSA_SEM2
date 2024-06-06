#include <stdio.h>
#include <stdlib.h>

// Node to represent each non-zero element in the sparse matrix
typedef struct Node {
    int row;
    int col;
    int val;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a linked list
void insertNode(Node** head, int row, int col, int val) {
    Node* newNode = createNode(row, col, val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix
// Function to display the sparse matrix
void display(Node* head, int rows, int cols) {
    printf("Row Column Value\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (head != NULL && head->row == i && head->col == j) {
                printf("%d    %d    %d\n", head->row, head->col, head->val);
                head = head->next;
            }
        }
    }
}


int main() {
    // Assume a 3x3 sparse matrix
    int sparseMatrix[3][3] = {
        {0, 0, 3},
        {0, 0, 5},
        {0, 7, 0}
    };

    Node* head = NULL; // Head of the linked list
    int size = 0; // Number of non-zero elements

    // Create linked list representation of the sparse matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != 0) {
                insertNode(&head, i, j, sparseMatrix[i][j]);
                size++;
            }
        }
    }

    // Display the sparse matrix
    display(head, 3, 3);

    // Free the memory allocated for the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
