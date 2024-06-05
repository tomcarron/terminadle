#include <stdio.h>
#include <string.h>
#include "intro.h"

// Define the size of the word and grid
#define SIZE 5 

// Function for printing the current grid (5x5)
void printGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function for printing a word
void printWord(char word[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%c", word[i]);
    }
    printf("\n");
}

// Function to get a guess from the user
void getGuess(char guess[SIZE + 1]) {
    int valid = 0;
    while (valid != 1) {
        printf("Enter your guess: ");
        scanf("%5s", guess);
        // Clear the input buffer
        while (getchar() != '\n');
        // Ensure the word is exactly 5 letters long
        printf("%ld\n",strlen(guess));
        if (strlen(guess) == SIZE) {
            printf("valid\n");
            valid = 1;
        } else {
            printf("Error: You must enter exactly 5 letters.\n");
        }
    }
}



int main() {
    title();
    // Placeholder grid for now
    char grid[SIZE][SIZE] = {
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'}
    };

    // Placeholder word for now
    char word[SIZE] = {'A', 'U', 'D', 'I', 'O'};

    printGrid(grid);
    printWord(word);

    char guess[SIZE + 1]; // Extra space for null terminator

    // Loop to get multiple guesses
    for (int i = 0; i < 6; i++) { // Assume maximum of 6 guesses
        getGuess(guess);
        // Further logic to compare the guess with the word and update the grid can be added here
    }

    return 0;
}


