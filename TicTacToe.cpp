#include<vector>
#include "TicTacToe.h"
#include "TTT_AI.h"

using std::vector;


/* Constructor */
TicTacToe::TicTacToe(){
   this->board = {' ',' ',' ',
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
    for(int row = 0; row < NUM_ROWS; row++){
        cout << "   ";
        for(int col = 0; col < NUM_COLS; col++){
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


void TicTacToe::playGame(){
    bool gameIsOver = false;
    TTT_AI theAI;

    /* game loop */
    while(!gameIsOver){

        /* print instructions */

        /* print current game board / state */

        /* take User input */

        /* check if winner, or game over */

        /* print current game board / state */

        /* allow Computer move (if there are moves left ) */
        // theAI.move();

        /* check if winner, or game over */


        /* next line is just a placeholder for testing*/
        gameIsOver = true;

    } // end game loop

}



void TicTacToe::moves(vector<char> gameState){
    
}


char TicTacToe::checkWinner(){

    /* NOTE: next line just for placeholder */
    return -1;
}

void TicTacToe::makeMove(int row, int col){

}


