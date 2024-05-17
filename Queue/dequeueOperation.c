#include <stdio.h>

#define MAX 100

int deque_arr[MAX];
int left = -1;
int right = -1;

void insert_front() {
    int added_item;

    // Check for overflow
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    // Handle the case when the queue is initially empty
    if (left == -1) {
        left = 0;
        right = 0;
    } 
    // Adjust the left pointer
    else if (left == 0) {
        left = MAX - 1;
    } 
    else {
        left = left - 1;
    }

    // Read and insert the element
    printf("Input the element for adding in queue: ");
    scanf("%d", &added_item);
    deque_arr[left] = added_item;
}

void insert_rear() {
    int added_item;

    // Check for overflow
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("Queue Overflow\n");
        return;
    }

    // Handle the case when the queue is initially empty
    if (left == -1) {
        left = 0;
        right = 0;
    } 
    // Adjust the right pointer
    else if (right == MAX - 1) {
        right = 0;
    } 
    else {
        right = right + 1;
    }

    // Read and insert the element
    printf("Input the element for adding in queue: ");
    scanf("%d", &added_item);
    deque_arr[right] = added_item;
}

void delete_front() {
    // Check for underflow
    if (left == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Element deleted from front: %d\n", deque_arr[left]);

    // Handle the case when there's only one element in the queue
    if (left == right) {
        left = -1;
        right = -1;
    } 
    // Adjust the left pointer
    else if (left == MAX - 1) {
        left = 0;
    } 
    else {
        left = left + 1;
    }
}

void display() {
    if (left == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the deque are: ");
    int i = left;
    while (1) {
        printf("%d ", deque_arr[i]);
        if (i == right) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Display deque\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_front();
                break;
            case 2:
                insert_rear();
                break;
            case 3:
                delete_front();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
