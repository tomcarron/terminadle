#include <stdio.h>
#include "intro.h"

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int title() {
    printf("\n\n");
    printf(RED "TTTTT EEEEE RRRR  M   M IIIII N   N   A   DDDD  L     EEEEE\n" RESET);
    printf(YELLOW "  T   E     R   R MM MM   I   NN  N  A A  D   D L     E   \n" RESET);
    printf(GREEN "  T   EEEEE RRRR  M M M   I   N N N AAAAA D   D L     EEEEE\n" RESET);
    printf(BLUE "  T   E     R R   M   M   I   N  NN A   A D   D L     E   \n" RESET);
    printf(MAGENTA "  T   EEEEE R  RR M   M IIIII N   N A   A DDDD  LLLLL EEEEE\n" RESET);
    printf(CYAN "\n\n Welcome to Terminadle - Wordle in the terminal! Credit: Tom Carron\n\n"RESET);
    return 0;
}