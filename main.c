#include <stdio.h>
#include <stdlib.h>
#include "demo.h"
#include "player.c"

#define ROW 12
#define COLUMN 15

int **createGrid(int row, int column) {
    int **grid = malloc(sizeof(int*)*row);
    for (int i = 0; i < row; i++) {
        grid[i] = calloc(column,sizeof(int));
    }
    return grid;
}

char **createCharGrid(int row, int column, int **grid) {
    grid[0][1] = 1;

    char **displayGrid = malloc(sizeof(char*)*row);

    for (int i = 0; i < row; i++) {
        displayGrid[i] = calloc(column,sizeof(char));
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == 0) {
                displayGrid[i][j] = ' ';
            } else if (grid[i][j] == 1) {
                displayGrid[i][j] = 'X';
            } else {
                displayGrid[i][j] = 'O';
            }
        }
    }
    return displayGrid;
}

void displayGrid(int row, int column, char **grid) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }

    // Yellow color
    printf("\033[0;33m");
    for (int i = 0; i < column; i++) {
        printf(" %03d", i + 1);
    }
    printf("\033[0m\n");
}

// AJouter un jeton tout en bas de la colonne choisie et mettre de la colision entre les jetons
void addPiece(int **grid, int column, int playerCross) {
    int row = 0;
    while (grid[row][column] != 0) {
        row++;
    }
    grid[row][column] = playerCross;
}

int main(void) {
    // int playerCross = 1;

    // while (1)
    // {
    //     playerPlay(playerCross);
    //     playerCross = !playerCross;
    // }
    
    int **grid = createGrid(ROW, COLUMN);
    char **charGrid = createCharGrid(ROW, COLUMN, grid);

    addPiece(grid, 1, 1);

    displayGrid(ROW, COLUMN, charGrid);

    // Affiche le grid
    for(int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
