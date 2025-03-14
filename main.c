#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
    int number, shift;
    char operation;

    // No need for Russian locale since we're using English
    setlocale(LC_CTYPE, "C");

    while (1) {
        // Get input
        printf("\nEnter a number (or 0 to exit): ");
        scanf("%d", &number);

        // Check exit condition
        if (number == 0) {
            printf("Program terminated.\n");
            break;
        }

        printf("Enter shift amount: ");
        scanf("%d", &shift);

        printf("Choose operation (l - left shift, r - right shift): ");
        scanf(" %c", &operation); // Space before %c to consume newline

        // Perform shift operation
        switch (operation) {
        case 'l':
        case 'L':
            printf("%d << %d = %d\n", number, shift, (number << shift));
            break;
        case 'r':
        case 'R':
            printf("%d >> %d = %d\n", number, shift, (number >> shift));
            break;
        default:
            printf("Invalid operation! Use 'l' or 'r'.\n");
            break;
        }

        // Show binary representation
        printf("Binary representation: ");
        for (int i = 31; i >= 0; i--) {
            printf("%d", (number >> i) & 1);
            if (i % 4 == 0) printf(" "); // Space for readability
        }
        printf("\n");
    }

    return 0;
}