#include <stdio.h>
#include <stdlib.h>
#include "grid.c"
#include "player.c"

int main(void) {
    int playerCross = 1;  // Le joueur 1 commence
    TableSize *tableSize = getTableSize();
    int **grid = createGrid(tableSize->row, tableSize->column);

    while (1) {
        displayGrid(tableSize->row, tableSize->column, grid);
        int pieceCol = playerPlay(playerCross, tableSize);
        addPiece(grid, pieceCol - 1, playerCross);


        for (int row = 0; row < tableSize->row; row++) {
            if (grid[row][pieceCol - 1] == playerCross) {
                if (checkWin(grid, row, pieceCol - 1, playerCross)) {
                    system("cls");
                    displayGrid(tableSize->row, tableSize->column, grid);
                    printf("Le joueur %d a gagné !\n", playerCross);
                    return 0;
                }
                break;
            }
        }

        if (playerCross == 1) {
            playerCross = 2;
        } else {
            playerCross = 1;
        }

        system("cls");

    }

    return 0;
}
