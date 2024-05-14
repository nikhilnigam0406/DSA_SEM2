#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    
};
void insertAtBeg(struct Node **head, int newData)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

    newNode-> data = newData;
    newNode-> next = *head;
    newNode->prev = NULL;

    if (*head != NULL){
    (*head)->prev = newNode;
    }
    *head = newNode;
}

void traverse(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void deleteAtBeg(struct Node **head)
{
    if (*head == NULL){
    return;
    }   
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}


int main(){
    struct Node *head = NULL;
    int choice, data, position, key;
    while(1){
        printf("\n\n1. InsertAtBeginning of the linked list");
        printf("\n2. InsertAtEnd of the linked list");
        printf("\n3. InsertAtPos of the linked list");
        printf("\n4. InsertionBeforePostion of the linked list");          
        printf("\n5. InsertionAfterPosition of the linked list");
        printf("\n6. Travese of the linked list");
        printf("\n7. Search of the linked list");
        printf("\n8. DeletionAtbeg of the linked list");
        printf("\n9. DeleteAtEnd of the linked list");
        printf("\n10.DeleteAtPos of the linked list");
        printf("\n11. Reverse of the linked list");

        // user choice
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("\nEnter the data to insert: ");
            scanf("%d", &data);
            insertAtBeg(&head, data);
            break;
            case 2: 
            printf("\nEnter data to insert: ");
            scanf("%d", &data);

            case 3:
            printf("\n Enter value to insert before position");
            scanf("%d", &data);

            case 4:
            printf("\n Enter value to insert after position");
            scanf("%d", &data);

            case 5: 
            printf("\n Traverese\n");
            printf("Linked List elements: ");
            traverse(head);
            break;

        }


    }
}