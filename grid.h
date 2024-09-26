#define ROW 12
#define COLUMN 15

int **createGrid(int row, int column);
char **createCharGrid(int row, int column, int **grid);
void displayGrid(int row, int column, int **grid);
void addPiece(int **grid, int column, int playerCross);