#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "intro.h"

// Define the size of the word and grid
#define SIZE 5 

// ANSI color codes
#define RESET "\033[0m" 
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Function for printing the current grid (5x5)
void printGrid(char grid[SIZE][SIZE], char* colorgrid[SIZE][SIZE]) {
    system("clear"); // Clear the terminal
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s%c " RESET, colorgrid[i][j], grid[i][j]);
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
void getGuess(char guess[SIZE+1]) {
    int valid = 0;
    while (valid != 1) {
        printf("Enter your guess: ");
        scanf(" %5s", guess);
        for (int i = 0; i < SIZE; i++) {
            guess[i] = toupper(guess[i]);
        }
        // Clear the input buffer
        while (getchar() != '\n');
        // Ensure the word is exactly 5 letters long
        if (strlen(guess) == SIZE) {
            valid = 1;
        } else {
            printf("Error: You must enter exactly 5 letters.\n");
        }
    }
}



// Function to update the colorgrid with the guess
void updateColorGrid(char* colorgrid[SIZE][SIZE], char* colors[SIZE], int row) {  
    for (int j = 0; j < SIZE; j++) {
        colorgrid[row][j] = colors[j];
    }
}

// Function to check if the user has won
void checkWin(char* colors[SIZE], int row, char grid[SIZE][SIZE], char* colorgrid[SIZE][SIZE]) {
    int win = 1;
    for (int i = 0; i < SIZE; i++) {
        if (colors[i] != GREEN) {
            win = 0;
        }
    }
    if (win == 1) {
        printGrid(grid, colorgrid); // add here some logic to print 1 guess or n guesses.
        printf("Congratulations! You have won the game in %d guesses.\n", row + 1);
        exit(0);
    }
}

void checkGuess(char guess[SIZE], char answer[SIZE], int row, char grid[SIZE][SIZE], char* colorgrid[SIZE][SIZE]) {
    // array to store colors of this guess
    char* colors[SIZE] = {WHITE, WHITE, WHITE, WHITE, WHITE};
    // Check if the guess is correct
    for (int i = 0; i < SIZE; i++) {
        // check if each letter is in the word and in the correct position
        if (guess[i] == answer[i]) {
            colors[i] = GREEN; // update the corresponding grid cell with the green color
        } else {
            // check if the letter is in the word but in the wrong position
            for (int j = 0; j < SIZE; j++) {
                if (guess[i] == answer[j]) {
                    colors[i] = YELLOW; // update the corresponding grid cell with the yellow color
                }
            }
        }
    }
    updateColorGrid(colorgrid, colors, row);
    checkWin(colors, row, grid, colorgrid);
}



// Function to update the grid with the guess
void updateGrid(char grid[SIZE][SIZE], char guess[SIZE], char answer[SIZE], int row, char* colorgrid[SIZE][SIZE]) {
    printf("Updating grid with guess: %s\n", guess);    
    for (int j = 0; j < SIZE; j++) {
        grid[row][j] = guess[j];
    }
    checkGuess(guess, answer, row, grid, colorgrid);
}



int main() {
    title();
    char answer[SIZE] = {'A', 'U', 'D', 'I', 'O'};

    // Placeholder grid for now
    char grid[SIZE][SIZE] = {
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '*'}
    };
    char* colorgrid[SIZE][SIZE] = {
        {WHITE, WHITE, WHITE, WHITE, WHITE},
        {WHITE, WHITE, WHITE, WHITE, WHITE},
        {WHITE, WHITE, WHITE, WHITE, WHITE},
        {WHITE, WHITE, WHITE, WHITE, WHITE},
        {WHITE, WHITE, WHITE, WHITE, WHITE}
    };

    // Placeholder word for now
    char word[SIZE] = {'A', 'U', 'D', 'I', 'O'};

    printGrid(grid, colorgrid);
    // printWord(word);

    char guess[SIZE + 1]; // Extra space for null terminator

    // Loop to get multiple guesses
    for (int i = 0; i < 5; i++) { // Assume maximum of 5 guesses
        getGuess(guess);
        updateGrid(grid, guess, answer, i, colorgrid);
        printGrid(grid, colorgrid); // Print the grid after each guess
    }

    return 0;
}

