#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printWelcome();
int getRandomNumber(int min, int max);
int getUserGuess();
void printResult(int guess, int secret);
char playAgain();

// Main function
int main() {

    // Seed the random number generator
    srand(time(NULL));
    char keepPlaying = 'y';

    while (keepPlaying == 'y' || keepPlaying == 'Y') {
    // Generate a random number between 1 and 100
    int secret = (rand() % 100) + 1;
    int guess;
    int attempts = 0;
    
    // Print the welcome message
    printWelcome();
    
    // Loop until the user guesses the correct number
    do {
        guess = getUserGuess();
        attempts++;
        printResult(guess, secret);
    } while (guess != secret);

    printf("you guessed the number in %d attempts!\n", attempts);
    keepPlaying = playAgain();
    }

    return 0;
}

// Function to print the welcome message
void printWelcome() {
    printf("welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
}
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to get user guess
int getUserGuess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

// Function to print user guess result 
void printResult(int guess, int secret) {
    if (guess > secret) {
        printf("Too high! Try again.\n");
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
           } else {
                printf("That's correct!\n");
            }
}

// Function to ask to play again 
char playAgain() {
    char response;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &response);
    return response;
}
    