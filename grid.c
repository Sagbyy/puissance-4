#include <stdio.h>
#include "grid.h"
#include "color.c"

TableSize *tableSize = NULL;

TableSize *getTableSize() {
    FILE *file = fopen("settings.conf", "r");

    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier settings.conf\n");
        exit(1);
    }

    tableSize = malloc(sizeof(TableSize));

    fscanf(file, "ROWS=%d\n", &tableSize->row);
    fscanf(file, "COLUMNS=%d\n", &tableSize->column);

    fclose(file);

    return tableSize;
}

int **createGrid(int row, int column) {
    int **grid = malloc(sizeof(int *) * row);
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
            if (displayGrid[i][j] == 'X') {
              printf("| ");
              red();
              printf("%c ", displayGrid[i][j]);
              resetColor();
            } else if (displayGrid[i][j] == 'O')
            {
              printf("| ");
              green();
              printf("%c ", displayGrid[i][j]);
              resetColor();
            }
            else {
              printf("| %c ", displayGrid[i][j]);
            }
        }
        printf("|\n");
    }

    // Yellow color
    yellow();
    for (int i = 0; i < column; i++) {
        printf(" %03d", i + 1);
    }
    printf("\n");
    resetColor();
}

void addPiece(int **grid, int column, int playerCross) {
    //02system("clear");
    for (int i = tableSize->row - 1; i >= 0; i--) {
        if (grid[i][column] == 0) {
            grid[i][column] = playerCross;
            break;
        }
    }
}

bool checkWin(int **grid, int row, int col, int playerDisc) {
    int count;

    //verticalement
    count = 0;
    for (int i = 0; i < tableSize->row; i++) {
        count = (grid[i][col] == playerDisc) ? count + 1 : 0;
        if (count == 4) return true;
    }

    //horizontalement
    count = 0;
    for (int j = 0; j < tableSize->column; j++) {
        count = (grid[row][j] == playerDisc) ? count + 1 : 0;
        if (count == 4) return true;
    }

    //diagonale /
    count = 0;
    for (int i = -3; i <= 3; i++) {
        int r = row + i, c = col + i;
        if (r >= 0 && r < tableSize->row && c >= 0 && c < tableSize->column && grid[r][c] == playerDisc) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
    }

    // Vérifier diagonale \
    count = 0;
    for (int i = -3; i <= 3; i++) {
        int r = row + i, c = col - i;
        if (r >= 0 && r < tableSize->row && c >= 0 && c < tableSize->column && grid[r][c] == playerDisc) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
    }

    return false;
}