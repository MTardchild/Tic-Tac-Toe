#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main() {
    //  Declare important shit
    int** GameField; // Gamefield itself
    int InputGameFieldHorizontal = 0; // Size of the GameField, horizontal
    int InputGameFieldVertical = 0; // Size of the GameField, vertical
    int *PointerInputGameFieldHorizontal = &InputGameFieldHorizontal;
    int *PointerInputGameFieldVertical = &InputGameFieldVertical;
    int RoundCounter = 0; // Used to determine whos turn it is
    bool finished = false; // Stores if TicTacToe is done (won/lost/remis)

    // Get User Input for GameField Size
    printf("Enter matrix length: ");
    scanf("%d", PointerInputGameFieldHorizontal);

    printf("Enter matrix width: ");
    scanf("%d", PointerInputGameFieldVertical);

    // Check said Input if true initialize else abort
    if (InputGameFieldHorizontal > 0 && InputGameFieldVertical > 0) {
        // Dynamically allocate memory for GameField
        int i = 0;
        GameField = malloc(InputGameFieldHorizontal * sizeof(int*));
        for (i = 0; i < InputGameFieldHorizontal; i++) {
            GameField[i] = malloc(InputGameFieldVertical * sizeof(int));
        }
    } else {
        printf("Incorrect initialization values. Aborting...");
        exit(0);
    }

    // DrawFieldPlayer returns true if the array is initialized successfully, else abort
    if(!DrawFieldPlayer(GameField, InputGameFieldHorizontal, InputGameFieldVertical)) {
        printf("Incorrect initialization values. Aborting...");
        exit(0);
    }

    // Play Tic Tac Toe
    int i = 0;
    int j = 0;

    while(!finished) {

        int x = -1;
        int y = -1;
        int *xPointer = &x;
        int *yPointer = &y;

        printf("Enter y value: ");
        scanf("%d", xPointer);
        printf("Enter x value: ");
        scanf("%d", yPointer);

        if ((RoundCounter % 2) != 0) {
            GameField[y][x] = 1; // O
        } else {
            GameField[y][x] = 2; // X
        }

        DrawFieldPlayer(GameField, InputGameFieldHorizontal,InputGameFieldVertical);

        if (i == (InputGameFieldHorizontal*InputGameFieldVertical)) {
            finished = true;
        }
        RoundCounter++;

        for (i = 0; i < InputGameFieldVertical; i++) {
            for (j = 0; j < InputGameFieldHorizontal; j++) {

                // Check Horizontal
                if (j < InputGameFieldHorizontal-2) {
                    if (GameField[i][j] == 1 && GameField[i][j+1] == 1 && GameField[i][j+2] == 1) {
                        printf("\n Player O wins \n\n");
                        exit(0);
                    } else if (GameField[i][j] == 2 && GameField[i][j+1] == 2 && GameField[i][j+2] == 2) {
                        printf("\n Player X wins \n\n");
                        exit(0);
                    }
                }

                // Check Vertical
                if (i < InputGameFieldVertical-2) {
                    if (GameField[i][j] == 1 && GameField[i+1][j] == 1 && GameField[i+2][j] == 1) {
                        printf("\n Player O wins \n\n");
                        exit(0);
                    } else if (GameField[i][j] == 2 && GameField[i+1][j] == 2 && GameField[i+2][j] == 2) {
                        printf("\n Player X wins \n\n");
                        exit(0);
                    }
                }

                // Check Diag
                if (i < InputGameFieldVertical-2 && j < InputGameFieldHorizontal-2) {
                    if (GameField[i][j] == 1 && GameField[i+1][j+1] == 1 && GameField[i+2][j+2] == 1) {
                        printf("\n Player O wins \n\n");
                        exit(0);
                    } else if (GameField[i][j] == 2 && GameField[i+1][j+1] == 2 && GameField[i+2][j+2] == 2) {
                        printf("\n Player X wins \n\n");
                        exit(0);
                    }
                }

                // Check ConDiag
                if (i < InputGameFieldVertical-2 && j < InputGameFieldHorizontal-2) {
                    if (    GameField[i][InputGameFieldHorizontal-1-j]     == 1
                        &&  GameField[i+1][InputGameFieldHorizontal-1-j-1] == 1
                        &&  GameField[i+2][InputGameFieldHorizontal-1-j-2] == 1) {

                        printf("\n Player O wins \n\n");
                        exit(0);
                    } else if (     GameField[i][InputGameFieldHorizontal-1-j]     == 2
                               &&   GameField[i+1][InputGameFieldHorizontal-1-j-1] == 2
                               &&   GameField[i+2][InputGameFieldHorizontal-1-j-2] == 2) {

                        printf("\n Player X wins \n\n");
                        exit(0);
                    }
                }
            }
        }
    }
    return 0;
}

bool DrawFieldPlayer (int **GameField, int x, int y) {
    int i = 0;
    int j = 0;

    printf(" ..[y][x].. \n\n");

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            switch (GameField[j][i]) {
                case 1 : printf(" .    O   . "); break;
                case 2 : printf(" .    X   . "); break;
                default: printf(" . [%d][%d] . ", i, j); break;
            }
        }
        printf("\n");
    }
    printf("\n");
    return true;
}
