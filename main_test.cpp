#include<iostream>
#include<vector>
#include "TTT_AI.h"


using std::cout;
using std::endl;
using std::vector;


int MAX_DEPTH = 9;
int NUM_ROWS = 3;
int NUM_COLS = 3;


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
void printTheGame(vector<char> gameState){
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




int main(){
    TTT_AI game(MAX_DEPTH);
    vector<char> gameState {' ',' ',' ',
                            ' ','x',' ',
                            ' ',' ',' '};


    vector<char> gameState2 {'x',' ','o',
                            ' ',' ','x',
                            'o','x','o'};

    printTheGame(gameState);

    vector<moveT> allTheMoves;
    game.GenerateMoveList(gameState, allTheMoves);
    cout << "These are the moves: ";
    for(auto item : allTheMoves){
        cout << item;
    }
    cout << endl;





}