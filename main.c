#include <stdio.h>
#include <stdlib.h>
#include "demo.h"
#include "grid.c"
#include "player.c"

int main(void) {
    int playerCross = 1;
    int **grid = createGrid(ROW, COLUMN);

    while (1)
    {
        displayGrid(ROW, COLUMN, grid);
        int pieceCol = playerPlay(playerCross);
        addPiece(grid, pieceCol - 1, playerCross);

        if (playerCross == 1)
        {
            playerCross = 2;
        }
        else {
            playerCross = 1;
        }
        
        system("cls");
    }
    
    return 0;
}
