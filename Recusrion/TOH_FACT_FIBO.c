#include <stdio.h>

unsigned long long factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

void towerOfHanoi(int n, char s, char i, char d) {
    if (n == 1) {
        printf("Rod %c to rod %c\n", s, d);
        return;
    }
    towerOfHanoi(n - 1, s, d, i);
    printf("Rod %c to rod %c\n", s, d);
    towerOfHanoi(n - 1, i, s, d);
}

unsigned long long fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int choice, num;
    unsigned long long result;

    while (choice != 4) {
        printf("\nRecursive Operations Menu:\n"
               "1. Factorial\n"
               "2. Tower of Hanoi\n"
               "3. Fibonacci Series\n"
               "4. Exit\n"
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
                    towerOfHanoi(num, 'A', 'B', 'C');
                }
                break;
            case 3:
                printf("Enter the number of terms: ");
                scanf("%d", &num);
                printf("Fibonacci Series with %d terms:\n", num);
                for (int i = 0; i < num; i++) {
                    printf("%llu ", fibonacci(i));
                }
                printf("\n");
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } 

    return 0;
}


