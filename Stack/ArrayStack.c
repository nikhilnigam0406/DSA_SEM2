#include <stdio.h>
#include <stdlib.h>

#define NIL -1
#define MAX 10
typedef struct stacktype
{
    int a[MAX];
    int top;
} STACK;

void push(STACK *S, int val)
{
    S->top++;
    S->a[S->top] = val;
}

int pop(STACK *S)
{
    int val = S->a[S->top];
    S->top--;
    return val;
}

int isFull(STACK S)
{
    return S.top == MAX - 1;
}

int isEmpty(STACK S)
{
    return S.top == NIL;
}

int peek(STACK S)
{
    return S.a[S.top];
}

void traverse(STACK *S)
{
    printf("\n Stack elements: ");
    for (int i = S->top; i >= 0; i--)
    {
        printf("%d ", S->a[i]);
    }
    printf("\n");
}

int main()
{
    int opt, val;
    STACK S;
    S.top = -1;

    while (1)
    {
        printf("1. Push the element\n");
        printf("2. Pop the element\n");
        printf("3. Peek operation\n");
        printf("4. Travering\n");
        printf("5. Exit\n\n");
        printf("Enter option: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            if (isFull(S))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Enter the element to push: ");
                scanf("%d", &val);
                push(&S, val);
            }
            break;

        case 2:
            if (isEmpty(S))
            {
                printf("Stack is empty\n");
            }
            else
            {
                val = pop(&S);
                printf("Element popped: %d\n", val);
            }
            break;

        case 3:
            if (isEmpty(S))
            {
                printf("Stack is empty\n");
            }
            else
            {
                val = peek(S);
                printf("Top element: %d\n", val);
            }
            break;
        case 5:
            exit(0);
        case 4:
            if (isEmpty(S))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack elements:\n");
                traverse(&S);
            }
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
