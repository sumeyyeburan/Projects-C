#include <stdio.h>
#include <string.h>

#define USERNAME "student"
#define PASSWORD "1234"
#define MAX_TRIES 5

int main(void){
    char username[30], password[15];
    int again, lesson[10], lesson_number;
    int tries = MAX_TRIES;
    double result = 0.0, notes[10];
    int i;
    
    while (tries > 0) {
    
        printf("Enter your username:");
        scanf("%29s", username);
        printf("Enter your password:");
        scanf("%14s", password);
    
        if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
            printf("\nLogin successful. Welcome, %s\n", username);
            
            cont:
            printf("\n\nHow many lessons do you want to calculate?: ");
            scanf("%d", &lesson_number);
            
            if (lesson_number <= 0 || lesson_number > 10) {
                printf("\nEnter a valid number (0 < x <= 10) :");
                goto cont;
            }
            printf("\n");
            for (i = 0; i < lesson_number; i++) {
                printf("Enter the ID of lesson %d: ", i + 1);
                scanf("%d", &lesson[i]);
            }
            printf("\n------------------------------------\n");
            for (i = 0; i < lesson_number; i++) {
                if (i % 2 == 0) {
                    printf("lesson[%d]: %d\t", i, lesson[i]);
                }
                else {
                    printf("lesson[%d]: %d\n", i, lesson[i]);
                }
            }
            
            printf("\n\nEnter the grades for the lessons based on the index numbers listed above...\n\n");
            
            for (i = 0; i < lesson_number; i++) {
                printf("notes[%d]: ", i);
                scanf("%lf", &notes[i]);
                
                result = result + notes[i];
            }
            
            result = result / lesson_number;
            
            printf("\nYour average grade: %.2lf\n", result);
            
            
            printf("\n\nAverage calculation completed. Exiting the program!\n\n");
            
            break;
        }
        
        else {
            printf("\nIncorrect username or password. Press 1 to try again.\n");
            scanf("%d", &again);
        
            if (again == 1) {
                tries--;
                printf("\nRemaining tries: %d\n\n\n", tries);
            }
            else {
                printf("\nLogin attempt cancelled...\n");
                break;
            }
        }
    }
    
    if (tries == 0) {
        printf("\nYou have exhausted your login attempts. Exiting the program.\n");
    }
    
    return 0;
}

