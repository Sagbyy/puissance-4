#include <stdio.h>
#include <stdlib.h>
#include "grid.c"
#include "player.c"

int main(void) {
    int playerCross = 1;  // Le joueur 1 commence
    int **grid = createGrid(ROW, COLUMN);

    while (1) {
        displayGrid(ROW, COLUMN, grid);
        int pieceCol = playerPlay(playerCross);
        addPiece(grid, pieceCol - 1, playerCross);


        for (int row = 0; row < ROW; row++) {
            if (grid[row][pieceCol - 1] == playerCross) {
                if (checkWin(grid, row, pieceCol - 1, playerCross)) {
                    system("clear");
                    displayGrid(ROW, COLUMN, grid);
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

        system("clear");

    }

    return 0;
}
