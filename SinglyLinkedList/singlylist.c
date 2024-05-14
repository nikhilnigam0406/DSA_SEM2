

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

// Function to insert a new node at the desired position in the linked list
void insertAtPosition(struct Node **head, int newData, int position)
{
    if (position == 0)
    {
        insertAtBeginning(head, newData);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to traverse the linked list and print its elements
void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to search for an element in the linked list
int search(struct Node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return 1; // Element found
        head = head->next;
    }
    return 0; // Element not found
}

// Function to delete the first node of the linked list
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *second_last = *head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    free(second_last->next);
    second_last->next = NULL;
}

// Function to delete a node at the desired position in the linked list
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to delete a node with a given value if it exists in the linked list
void deleteWithValue(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("Element is not present in List. No node to delete.\n");
        return;
    }
    if ((*head)->data == value)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position, key;

    while (1)
    {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Traverse\n");
        printf("5. Search\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("9. Delete with Value\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            printf("Linked List elements: ");
            traverse(head);
            break;
        case 5:
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (search(head, key))
                printf("%d found in the list.\n", key);
            else
                printf("%d not found in the list.\n", key);
            break;
        case 6:
            deleteAtBeginning(&head);
            printf("Deleted first element.\n");
            break;
        case 7:
            deleteAtEnd(&head);
            printf("Delete last element.\n");
            break;
        case 8:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 9:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteWithValue(&head, data);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
