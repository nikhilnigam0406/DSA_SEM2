#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int coeff;
    int pow;
    struct polynomial *next;
} node;

void create_node(node **head, int coeff, int pow) {
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Unable to allocate memory\n");
        return;
    }
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = *head;
    *head = temp;
}

void show(node *head) {
    if (head == NULL) {
        printf("Empty polynomial\n");
        return;
    }
    while (head != NULL) {
        printf("%dX^%d ", head->coeff, head->pow);
        if (head->next != NULL) {
            printf("+ ");
        }
        head = head->next;
    }
}

void polyadd(node *poly1, node *poly2, node **poly) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            create_node(poly, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            create_node(poly, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                create_node(poly, sum, poly1->pow);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        create_node(poly, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        create_node(poly, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
}

int main() {
    node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    create_node(&poly1, 2, 0);
    create_node(&poly1, 4, 1);
    create_node(&poly1, 5, 2);

    create_node(&poly2, 5, 0);
    create_node(&poly2, -5, 1);
    create_node(&poly2, -3, 2);

    printf("1st polynomial: ");
    show(poly1);
    printf("\n2nd polynomial: ");
    show(poly2);

    polyadd(poly1, poly2, &poly);
    printf("\nAdded polynomial: ");
    show(poly);

    return 0;
}
