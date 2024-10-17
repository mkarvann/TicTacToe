#include<vector>
#include "TicTacToe.h"
using std::vector;

/*
class TicTacToe
{
public:
    TicTacToe();
    void playGame();
private:
    vector<char> board;
    void printBoard();
    char checkWinner();
    void makeMove(int row, int col);
    int minimax(bool isMaximizing);
    findBestMove();
};
*/





/* Constructor */
TicTacToe::TicTacToe(){
   this->board {' ',' ',' ',
                ' ',' ',' ',
                ' ',' ',' '};
}



/* printTheGame
  Usage: printTheGame(gameState);
  ------------------------------
  Takes a Tic-Tac-Toe board represented as
  a vector<char> and prints it
  Returns: nothing
  Assumes:
  - There are global variables defined for NUM_ROWS
  and NUM_COLS, which define the number for each (in 
  case we want to play a board bigger than 3x3)
*/
void TicTacToe::printTheGame(vector<char> gameState){
    for(size_t row = 0; row < NUM_ROWS; row++){
        cout << "   ";
        for(size_t col = 0; col < NUM_COLS; col++){
            cout << gameState[row * NUM_COLS + col];
            if(col < NUM_COLS - 1){
                cout << " | ";
            }
        }
        cout << endl;
        if(row < NUM_ROWS -1){
            cout << "  ---+---+--- " << endl;
        }
        
    }
}  // end printTheGame
