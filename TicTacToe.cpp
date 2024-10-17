#include<vector>
#include "TicTacToe.h"
//#include "TTT_AI.h"

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
    cout << "------------------------" << endl;
    cout << "The board now looks like:" << endl << endl;
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

void TicTacToe::printGameInstructions(){
    cout << endl << endl;
    cout << "===========================" << endl;
    cout << "======= Tic Tac Toe =======" << endl;
    cout << "===========================" << endl;
    cout << "Welcome to Tic_Tac-Toe !" << endl;
    cout << "You know how to play." << endl;
    cout << "The cells are referred to by" << endl;
    cout << "a numbering scheme as follows:" << endl;
    cout << "        1 | 2 | 3" << endl;
    cout << "       ---+---+---" << endl;
    cout << "        4 | 5 | 6 " << endl;
    cout << "       ---+---+---" << endl;
    cout << "        7 | 8 | 9" << endl;
    cout << "To make a move, select the " << endl;
    cout << "number of the cell you want" << endl;
    cout << "to mark." << endl << endl;

}


void TicTacToe::playGame(){
    bool gameIsOver = false;
    //TTT_AI theAI;

    printGameInstructions();
    /* game loop */
    while(!gameIsOver){

        /* print instructions */

        /* print current game board / state */
        printTheGame(this->board);

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


