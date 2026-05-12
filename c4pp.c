#include <stdio.h>

int main() {
    double a, b, result;
    char op;
    char again;
    
    do {
        printf("\n=== C4pp - simple calc on C ===\n");
        printf("==============================\n");
        printf("Enter first number: ");
        while (scanf("%lf", &a) != 1) {
            printf("Invalid! Enter a number: ");
            while (getchar() != '\n');  
        }
        
        int valid_op = 0;
        while (!valid_op) {
            printf("Enter operator (+, -, *, /): ");
            scanf(" %c", &op);
            
            switch (op) {
                case '+':
                case '-':
                case '*':
                case '/':
                    valid_op = 1;
                    break;
                default:
                    printf("INVALID OPERATOR! Use +, -, *, /\n");
            }
        }
        
        
        printf("Enter second number: ");
        while (scanf("%lf", &b) != 1) {
            printf("Invalid! Enter a number: ");
            while (getchar() != '\n');
        }
        
        // Вычисление
        switch (op) {
            case '+':
                result = a + b;
                printf("%.2lf + %.2lf = %.2lf\n", a, b, result);
                break;
            case '-':
                result = a - b;
                printf("%.2lf - %.2lf = %.2lf\n", a, b, result);
                break;
            case '*':
                result = a * b;
                printf("%.2lf * %.2lf = %.2lf\n", a, b, result);
                break;
            case '/':
                if (b != 0) {
                    result = a / b;
                    printf("%.2lf / %.2lf = %.2lf\n", a, b, result);
                } else {
                    printf("ERROR: Division by zero!\n");
                }
                break;
        }
        
        printf("\nContinue? (y/n): ");
        scanf(" %c", &again);
        
    } while (again == 'y' || again == 'Y');
    
    printf("Goodbye!\n");
    return 0;
}