#include <stdio.h>

int factorial(int f){
    if(f == 0 || f == 1)
        return 1;
    
    return f * factorial(f - 1);
}

int main(void){
    int fac;
    
    again:
    printf("\nEnter the number for which you want to calculate the factorial:\n");
    scanf("%d", &fac);
    
    if(fac < 0){
        printf("\nThe factorial of %d cannot be calculated, please try again!\n\n", fac);
        goto again;
    }
    
    printf("\n%d! = %d\n", fac, factorial(fac));
    
    return 0;
}

