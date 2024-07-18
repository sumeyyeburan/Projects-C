#include <stdio.h>
#include <math.h>

void add(double x, double y) {
    printf("\n%.2lf + %.2lf = %.2lf\n\n", x, y, x + y);
}

void sub(double x, double y) {
    printf("\n%.2lf - %.2lf = %.2lf\n\n", x, y, x - y);
}

void mult(double x, double y) {
    printf("\n%.2lf * %.2lf = %.2lf\n\n", x, y, x * y);
}

void div(double x, double y) {
    if (y == 0)
        printf("\nInvalid operation, division by zero error!\n\n");
    else
        printf("\n%.2lf / %.2lf = %.2lf\n\n", x, y, x / y);
}

void power(double x, double y) {
    printf("\n%.2lf ^ %.2lf = %.2lf\n\n", x, y, pow(x, y));
}

void mod(double x, double y) {
    if (y == 0)
        printf("\nInvalid operation, division by zero error!\n\n");
    else {
        double result = fmod(x, y);
        printf("\n%.2lf %% %.2lf = %.2lf\n\n", x, y, result);
    }
}

int main(void) {
    int choice;
    double num1, num2;

    printf("\n****** READY TO CALCULATE ! *******\n");
    printf("\n\n\n");
    printf("First, choose the operation you want to perform...\n");
    while (1) {  // infinite loop

        printf("\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exponentiation\n");
        printf("6. Modulus\n");
        printf("7. Exit\n");
        printf("\nYour choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("\n\n****** CALCULATOR TERMINATED ! ******\n\n");
            break;
        }
        if (choice < 1 || choice > 7) {
            printf("\n\nInvalid choice, please try again!\n");
            continue;
        }

        printf("\nEnter the numbers you want to operate on...\n");
        printf("Number-1: ");
        scanf("%lf", &num1);
        printf("Number-2: ");
        scanf("%lf", &num2);

        switch (choice) {
        case 1:
            add(num1, num2);
            break;
        case 2:
            sub(num1, num2);
            break;
        case 3:
            mult(num1, num2);
            break;
        case 4:
            div(num1, num2);
            break;
        case 5:
            power(num1, num2);
            break;
        case 6:
            mod(num1, num2);
            break;
        }
    }
    return 0;
}

