#include <stdio.h>
#include<string.h>
unsigned long long factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

void TOH(int n, char s, char i, char d) {
    if (n == 1) {
        printf("Tower %c to Tower %c\n", s, d);
        return;
    }
    TOH(n - 1, s, d, i);
    printf("Tower %c to Tower %c\n", s, d);
    TOH(n - 1, i, s, d);
}

unsigned long long fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

void reverseString(char str[], int start, int end) {
    if (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        reverseString(str, start + 1, end - 1);
    }
}


int main() {
    int choice, num;
    unsigned long long result;

    while (choice != 5) {
        printf("Recursive Operations Menu:\n"
               "1. Factorial\n"
               "2. Tower of Hanoi\n"
               "3. Fibonacci Series\n"
               "4. Reverse String\n"
               "5. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a non-negative integer: ");
                scanf("%d", &num);
                result = (num < 0) ? printf("Factorial not possible.\n") : factorial(num);
                printf("Factorial of %d = %llu\n", num, result);
                break;
            case 2:
                printf("Enter the number of disks: ");
                scanf("%d", &num);
                if (num <= 0) {
                    printf("Number of disks must be a positive integer.\n");
                } else {
                    printf("Tower of Hanoi with %d disks:\n", num);
                    TOH(num, 'A', 'B', 'C');
                }
                break;
            case 3:
                printf("Enter the number of terms: ");
                scanf("%d", &num);
                printf("Fibonacci %d terms:\n", num);
                for (int i = 0; i < num; i++) {
                    printf("%llu ", fibonacci(i));
                }
                printf("\n");
                break;
            case 4:
                {
                    char str[100];
                    printf("Enter a string to reverse: ");
                    scanf("%s", str);
                    reverseString(str, 0, strlen(str) - 1);
                    printf("Reversed string: %s\n", str);
                }
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } 

    return 0;
}
