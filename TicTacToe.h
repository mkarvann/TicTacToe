#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


int MAX_DEPTH = 9;
int NUM_ROWS = 3;
int NUM_COLS = 3;

class TicTacToe {
    public:
        TicTacToe();
        void playGame();
    private:
        vector<char> board;

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
        void printTheGame(vector<char> gameState);

        char checkWinner();
        void makeMove(int row, int col);
        void moves(vector<char> gameState);
        //int minimax(bool isMaximizing);
        //findBestMove();
};


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
void printTheGame(vector<char> gameState);

