#include <stdio.h>
#include <stdlib.h> // Needed for the exit function

void armstrong_number();
void fibonacci_number();
void palindrome_number();
void info();

int main(){
    int op;
    
    // Infinite loop
    while(1){
        
        printf("\n-----------------------------------------------------\n");
        printf("\n1. Armstrong Number\n2. Fibonacci Series\n3. Palindrome Number\n4. Information\n5. Exit\n\nEnter the number of the operation you want to perform: ");
        scanf("%d",&op);
        
        switch(op){
            case 1:
                armstrong_number();
                break;
            case 2:
                fibonacci_number();
                break;
            case 3:
                palindrome_number();
                break;
            case 4:
                info();
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
                break; // Technically not necessary, but improves readability.
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }   
    }
    return 0;
}

void armstrong_number(){
    printf("\n\n**** Armstrong Number Program ****\n");
    printf("=======================================\n\n");
    
    int number, temp, digit = 0, remainder, result = 0;
    int i;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    temp = number; // To preserve the original number
    // Finding the number of digits in the number
    while(temp != 0){
        temp = temp / 10;
        digit++;
    }
    
    temp = number;
    while(temp != 0){
        remainder = temp % 10;
        int sum = 1;
        for(i = 0; i < digit; i++){
            sum = sum * remainder;
        }
        result = result + sum;
        temp = temp / 10;
    }
    
    if(result == number){
        printf("\n%d is an Armstrong number.\n\n", number);
    }
    else{
        printf("\n%d is not an Armstrong number.\n\n", number);
    }
    
}

void fibonacci_number(){
    printf("\n\n**** Fibonacci Series ****\n");
    printf("=======================================\n\n");
    
    int choice;
    int number, i, f1 = 1, f2 = 1, f3 = 0;
    
    printf("First, choose the operation you want to perform...\n\n1. Display Fibonacci series up to a given number\n2. Find the Fibonacci number at a given position\n\nYour choice: ");
    scanf("%d", &choice);
    
    if(choice == 1){
        printf("\nEnter a number: ");
        scanf("%d", &number);
        
        printf("\n%d\t%d\t", f1, f2);
        for(i = 0; i < number - 2; i++){
            f3 = f1 + f2;
            printf("%d\t", f3);
            f1 = f2;
            f2 = f3;
        }
    }
    else if(choice == 2){
        printf("\nEnter a position: ");
        scanf("%d", &number);
        
        for(i = 0; i < number - 2; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        
        if(number == 1 || number == 2){
            f3 = 1;
        }
        
        printf("\nThe Fibonacci number at position %d: %d", number, f3);
    }
    else{
        printf("\nInvalid input!\n");
    }
    printf("\n");
}

void palindrome_number(){
    printf("\n\n**** Palindrome Number Program ****\n");
    printf("=======================================\n\n");
    
    int number, reversedNumber = 0, remainder, temp;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    temp = number;
    while(temp != 0){
        remainder = temp % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        temp = temp / 10;
    }
    
    if(reversedNumber == number){
        printf("\n%d is a palindrome number.\n\n", number);
    }
    else{
        printf("\n%d is not a palindrome number.\n\n", number);
    }
}

void info(){
    printf("\n\n**** Information ****\n");
    printf("=======================================\n\n");
    
    printf("1. Armstrong Number\n   An n-digit number that is equal to the sum of nth powers of its digits.\n   Example: 153 -> 1^3 + 5^3 + 3^3 = 153\n");
    printf("\n2. Fibonacci Series\n   A series of numbers in which each number (Fibonacci number) is the sum of the two preceding ones, starting from 1 and 1.\n");
    printf("\n3. Palindrome Number\n   Numbers that read the same backward as forward.\n   Example: 121 -> 121\n");
}

