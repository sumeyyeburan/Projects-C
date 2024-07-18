#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int options;

void gameInfo();
void startGame();

int main(){

    // Initialize the random number generator with time
    srand(time(NULL));

    printf("\n**** WELCOME TO THE NUMBER GUESSING GAME ! ****\n\n\n");
    printf("Press 1 for game information\nPress 2 to start the game\nEnter your choice: ");
    scanf("%d", &options);

    switch (options) {
        case 1:
            gameInfo();
            break;
        case 2:
            startGame();
            break;
        default:
            printf("Invalid choice. Exiting the program.\n");
            break;
    }

    return 0;
}

void gameInfo() {
    printf("\n----------------------------------------------------------\n");
    printf("\nOur game is a number guessing game.\nA random number is chosen and you try to guess it.\n");
    printf("You have 5 attempts.\nThe number is between 0 and 100.\nHints will be given to help you.\nHave fun :)\n");
    printf("\n\nPress 2 to start the game, or 0 to exit: ");
    scanf("%d", &options);

    if (options != 2) {
        printf("\n---- Exiting the game... ----\n\n");
        exit(0); // Terminate the program
    } else {
        startGame();
    }
}

void startGame() {
    int guess_number, random_number;
    int RIGHT = 5;

    random_number = rand() % 101; // Generate random number between 0 and 100

    printf("\n----------------------------------------------------------\n");
    printf("\n~~~~ Game Starting... ~~~~\n\n");

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess_number);

        // Correct guess
        if (guess_number == random_number) {
            printf("\nCongratulations, you won the game!!\n");
            printf("\n---- Exiting the game... ----\n\n");
            return;
        }
        // Guess is too high
        else if (guess_number > random_number) {
            printf("\nYour guess is higher than the random number. Please enter a smaller number.");
        }
        // Guess is too low
        else {
            printf("\nYour guess is lower than the random number. Please enter a larger number.");
        }

        RIGHT--;
        printf("\nRemaining attempts: %d\n", RIGHT);

    } while (RIGHT > 0);

    printf("\n\nYou ran out of attempts.\n\nRandom number: %d\nYou lost the game :(\n", random_number);
    printf("\n---- Exiting the game... ----\n\n");
}

