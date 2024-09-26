#include "grid.h"

int **createGrid(int row, int column) {
    int **grid = malloc(sizeof(int*)*row);
    for (int i = 0; i < row; i++) {
        grid[i] = calloc(column,sizeof(int));
    }
    return grid;
}

char **createCharGrid(int row, int column, int **grid) {

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

void displayGrid(int row, int column, int **grid) {
    char **displayGrid = createCharGrid(row, column, grid);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("| %c ", displayGrid[i][j]);
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

void addPiece(int **grid, int column, int playerCross) {
    for (int i = ROW - 1; i >= 0; i--) {
        if (grid[i][column] == 0) {
            grid[i][column] = playerCross;
            break;
        }
    }
}