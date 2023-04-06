#include <stdio.h>

void displayGrid(char grid[3][3]);
int checkWin(char grid[3][3], char symbol);

int main() {
   char grid[3][3] = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}
   };
   int currentPlayer = 1; // player 1 starts the game
   char playerSymbol; // X or O
   int row, col; // coordinates of the cell to be filled

   printf("Welcome to Tic Tac Toe!\n");
   displayGrid(grid);

   while (1) { // game loop
      if (currentPlayer == 1) {
         playerSymbol = 'X';
      } else {
         playerSymbol = 'O';
      }
      printf("Player %d (%c), enter row and column: ", currentPlayer, playerSymbol);
      scanf("%d %d", &row, &col);

      if (row < 1 || row > 3 || col < 1 || col > 3) {
         printf("Invalid input. Row and column must be between 1 and 3.\n");
         continue;
      }
      if (grid[row-1][col-1] != ' ') {
         printf("Invalid input. Cell already occupied.\n");
         continue;
      }

      grid[row-1][col-1] = playerSymbol;
      displayGrid(grid);

      if (checkWin(grid, playerSymbol)) {
         printf("Player %d wins!\n", currentPlayer);
         break;
      }
      if (currentPlayer == 1) {
         currentPlayer = 2;
      } else {
         currentPlayer = 1;
      }
   }

   return 0;
}

void displayGrid(char grid[3][3]) {
   printf("    1   2   3  \n");
   printf("  +---+---+---+\n");
   for (int i = 0; i < 3; i++) {
      printf("%d ", i + 1);
      for (int j = 0; j < 3; j++) {
         printf("| %c ", grid[i][j]);
      }
      printf("|\n");
      printf("  +---+---+---+\n");
   }
}

int checkWin(char grid[3][3], char symbol) {
   // check rows
   for (int i = 0; i < 3; i++) {
      if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
         return 1;
      }
   }
   // check columns
   for (int j = 0; j < 3; j++) {
      if (grid[0][j] == symbol && grid[1][j] == symbol && grid[2][j] == symbol) {
         return 1;
      }
   }
   // check diagonals
   if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
      return 1;
   }
   if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
      return 1;
   }
   // no winner yet
   return 0;
}
