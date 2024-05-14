
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {(*head)->prev = newNode;}
    *head = newNode;
}


void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void insertAtPosition(struct Node** head, int newData, int position) {
    if (position == 0) {
        insertAtBeginning(head, newData);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void insertBeforePosition(struct Node** head, int newData, int position) {
    if (position == 0) {
        printf("Invalid position to insert before.\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    temp->prev = newNode;
    if (temp == *head)
        *head = newNode;
}

void insertAfterPosition(struct Node** head, int newData, int position) {
    struct Node* temp = *head;
    for (int i = 0; i < position && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1; 
        head = head->next;
    }
    return 0; 
}


void reverseTraverse(struct Node* head) {
    struct Node* last = NULL;
    
    while (head != NULL) {
        last = head;
        head = head->next;
    }
    
    printf("Doubly linked list in reverse order: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL)
        return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL)
        return;
    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;
    if (last->prev != NULL)
        last->prev->next = NULL;
    if (last == *head)
        *head = NULL;
    free(last);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL)
        return;
    struct Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 0)
        return;
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;
    if (temp->prev != NULL) {
        struct Node* del = temp->prev;
        temp->prev = del->prev;
        if (del->prev != NULL)
            del->prev->next = temp;
        else
            *head = temp;
        free(del);
    }
}

void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position < 0)
        return;
    struct Node* temp = *head;
    for (int i = 0; i < position && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node* del = temp->next;
    temp->next = del->next;
    if (del->next != NULL)
        del->next->prev = temp;
    free(del);
}

void deleteWithValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Element is not present in List. No node to delete.\n");
        return;
    }
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    int choice, data, position, key;
    
    while (1) {
        printf("\n1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert Before Position\n");
        printf("5. Insert After Position\n");
        printf("6. Traverse\n");
        printf("7. Search\n");
        printf("8. Delete at Beginning\n");
        printf("9. Delete at End\n");
        printf("10. Delete at Position\n");
        printf("11. Delete Before Position\n");
        printf("12. Delete After Position\n");
        printf("13. Delete with Value\n");
        printf("14. Reverse String\n");
        printf("15. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
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
                printf("Enter data to insert Pos: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter data to insert Before Pos: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertBeforePosition(&head, data, position);
                break;
            case 5:
                printf("Enter data to insert After Pos: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAfterPosition(&head, data, position);
                break;
            case 6:
                printf("Linked List elements: ");
                traverse(head);
                break;
            case 7:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(head, key))
                    printf("%d found in the list.\n", key);
                else
                    printf("%d not found in the list.\n", key);
                break;
            case 8:
                deleteAtBeginning(&head);
                printf("Deleted first element.\n");
                break;
            case 9:
                deleteAtEnd(&head);
                printf("Deleted last element.\n");
                break;
            case 10:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 11:
                printf("Enter position to delete before: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 12:
                printf("Enter position to delete after: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 13:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteWithValue(&head, data);
                break;
            case 14:
                printf("Reverse traversing in linked list");
                reverseTraverse(head);
            case 15:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
