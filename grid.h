#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

typedef struct {
    int row;
    int column;
} TableSize;

TableSize *getTableSize();
int **createGrid(int row, int column);
char **createCharGrid(int row, int column, int **grid);
void displayGrid(int row, int column, int **grid);
void addPiece(int **grid, int column, int playerCross);
bool Win(int **grid, int row, int col, int playerDisc);

#endif // GRID_H