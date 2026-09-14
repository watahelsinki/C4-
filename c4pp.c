#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

// Функция для вычисления факториала
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Функция для безопасного ввода вещественного числа
double get_double(const char* prompt) {
    double val;
    printf("%s", prompt);
    while (scanf("%lf", &val) != 1) {
        printf("Invalid input! Enter a valid number: ");
        while (getchar() != '\n'); // Очистка буфера
    }
    return val;
}

int main() {
    double a = 0, b = 0, result = 0;
    int group_choice;
    char op;
    char again;

    do {
        printf("\n====================================\n");
        printf("===  C4pp - UltraMegaSuper Calc  ===\n");
        printf("====================================\n");

        // 1. Выбор группы функций
        int valid_group = 0;
        while (!valid_group) {
            printf("Select function group:\n");
            printf(" 1 -> Basic math (+, -, *, /)\n");
            printf(" 2 -> Trigonometry (sin, cos, tan, cot, arcsin...)\n");
            printf(" 3 -> Advanced math (pow, sqrt, factorial)\n");
            printf(" 4 -> Math Constants (Pi, e)\n");
            printf(" 5 -> Programmer Mode (Bitwise & Base converters)\n");
            printf("Your choice (1-5): ");

            if (scanf("%d", &group_choice) == 1 && group_choice >= 1 && group_choice <= 5) {
                valid_group = 1;
            } else {
                printf("INVALID CHOICE! Please enter a number from 1 to 5.\n\n");
                while (getchar() != '\n');
            }
        }


        if (group_choice != 4) {
            a = get_double("\nEnter first number (for Base conversion enter an integer): ");
        }


        while (getchar() != '\n');


        int valid_op = 0;
        int is_unary = 0;

        while (!valid_op) {
            switch (group_choice) {
                case 1:
                    printf("Select basic operator (+, -, *, /): ");
                    scanf(" %c", &op);
                    if (op == '+' || op == '-' || op == '*' || op == '/') {
                        valid_op = 1;
                        is_unary = 0;
                    }
                    break;

                case 2:
                    printf("Select trig function:\n");
                    printf(" S -> sin(x)      C -> cos(x)      T -> tan(x)      O -> cot(x)\n");
                    printf(" I -> arcsin(x)   U -> arccos(x)   G -> arctan(x)\n");
                    printf("Your choice: ");
                    scanf(" %c", &op);
                    if (op == 'S' || op == 'C' || op == 'T' || op == 'O' || op == 'I' || op == 'U' || op == 'G') {
                        valid_op = 1;
                        is_unary = 1;
                    }
                    break;

                case 3:
                    printf("Select advanced operator (^, s for sqrt, ! for fact): ");
                    scanf(" %c", &op);
                    if (op == '^' || op == 's' || op == '!') {
                        valid_op = 1;
                        is_unary = (op == 's' || op == '!');
                    }
                    break;

                case 4:
                    printf("Select constant (p for Pi, e for Euler number): ");
                    scanf(" %c", &op);
                    if (op == 'p' || op == 'e') {
                        valid_op = 1;
                        is_unary = 1;
                    }
                    break;

                case 5:
                    printf("Select programmer operator:\n");
                    printf(" & -> Bitwise AND    | -> Bitwise OR     X -> Bitwise XOR\n");
                    printf(" H -> Convert to HEX  o -> Convert to OCT\n");
                    printf("Your choice: ");
                    scanf(" %c", &op);
                    if (op == '&' || op == '|' || op == 'X' || op == 'H' || op == 'o') {
                        valid_op = 1;
                        is_unary = (op == 'H' || op == 'o');
                    }
                    break;
            }

            if (!valid_op) {
                printf("INVALID OPERATOR for this group! Try again.\n");
                while (getchar() != '\n');
            }
        }

        // 3. Ввод второго числа (только если операция бинарная)
        if (!is_unary) {
            b = get_double("Enter second number: ");
        }

        // 4. Вычисление и вывод результата
        printf("\nResult: ");
        switch (op) {

            case '+': result = a + b; printf("%.2lf + %.2lf = %.2lf\n", a, b, result); break;
            case '-': result = a - b; printf("%.2lf - %.2lf = %.2lf\n", a, b, result); break;
            case '*': result = a * b; printf("%.2lf * %.2lf = %.2lf\n", a, b, result); break;
            case '/':
                if (b != 0) {
                    result = a / b;
                    printf("%.2lf / %.2lf = %.2lf\n", a, b, result);
                } else {
                    printf("ERROR: Division by zero!\n");
                }
                break;


            case 'S':
                result = sin(a * M_PI / 180.0);
                printf("sin(%.2lf°) = %.4lf\n", a, result);
                break;
            case 'C':
                result = cos(a * M_PI / 180.0);
                printf("cos(%.2lf°) = %.4lf\n", a, result);
                break;
            case 'T':
                if (fmod(a - 90.0, 180.0) == 0.0) {
                    printf("ERROR: Tangent is undefined for %.2lf°!\n", a);
                } else {
                    result = tan(a * M_PI / 180.0);
                    printf("tan(%.2lf°) = %.4lf\n", a, result);
                }
                break;
            case 'O': // Котангенс
                if (fmod(a, 180.0) == 0.0) {
                    printf("ERROR: Cotangent is undefined for %.2lf°!\n", a);
                } else {
                    result = 1.0 / tan(a * M_PI / 180.0);
                    printf("cot(%.2lf°) = %.4lf\n", a, result);
                }
                break;
            case 'I': // Арксинус
                if (a >= -1.0 && a <= 1.0) {
                    result = asin(a) * 180.0 / M_PI; // Конвертируем радианы в градусы
                    printf("arcsin(%.2lf) = %.2lf°\n", a, result);
                } else {
                    printf("ERROR: Input must be between -1 and 1 for arcsin!\n");
                }
                break;
            case 'U': // Арккосинус
                if (a >= -1.0 && a <= 1.0) {
                    result = acos(a) * 180.0 / M_PI;
                    printf("arccos(%.2lf) = %.2lf°\n", a, result);
                } else {
                    printf("ERROR: Input must be between -1 and 1 for arccos!\n");
                }
                break;
            case 'G': // Арктангенс
                result = atan(a) * 180.0 / M_PI;
                printf("arctan(%.2lf) = %.2lf°\n", a, result);
                break;


            case '^': result = pow(a, b); printf("%.2lf ^ %.2lf = %.2lf\n", a, b, result); break;
            case 's':
                if (a >= 0) {
                    result = sqrt(a);
                    printf("sqrt(%.2lf) = %.2lf\n", a, result);
                } else {
                    printf("ERROR: Square root of a negative number!\n");
                }
                break;
            case '!':
                if (a >= 0 && a == (int)a) {
                    unsigned long long fact_res = factorial((int)a);
                    printf("(%.0lf)! = %llu\n", a, fact_res);
                } else {
                    printf("ERROR: Factorial requires a non-negative integer!\n");
                }
                break;


            case 'p': result = M_PI; printf("Pi = %.15lf\n", result); break;
            case 'e': result = M_E; printf("e = %.15lf\n", result); break;


            case '&':
                result = (int)a & (int)b;
                printf("%d & %d = %d\n", (int)a, (int)b, (int)result);
                break;
            case '|':
                result = (int)a | (int)b;
                printf("%d | %d = %d\n", (int)a, (int)b, (int)result);
                break;
            case 'X':
                result = (int)a ^ (int)b;
                printf("%d XOR %d = %d\n", (int)a, (int)b, (int)result);
                break;
            case 'H':
                printf("DEC %d = HEX %X\n", (int)a, (int)a);
                break;
            case 'o':
                printf("DEC %d = OCT %o\n", (int)a, (int)a);
                break;
        }

        printf("\nContinue? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("Goodbye!\n");
    return 0;
}
