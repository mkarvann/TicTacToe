#include <vector>
#include <iostream>
#include <algorithm>   /* for find() */
#include "TicTacToe.h"
#include "TTT_AI.h"

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::find;


/* Constructor */
TicTacToe::TicTacToe(){
   this->board = {' ',' ',' ',
                ' ',' ',' ',
                ' ',' ',' '};

    // board = vector<vector<char>>(3, vector<char>(3, EMPTY));
    // Can we use this? [MK]
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
    TTT_AI theAI(MAX_DEPTH);

    /* print instructions */
    printGameInstructions();

    /* game loop */
    while(!gameIsOver){

        /* print current game board / state */
        printTheGame(this->board);

        /* take User input */
        int userChoice = getUserMenuInput("Please enter a number from 1-9:\n");

        /* make the move */
        if(validMove(userChoice, this->board)){
            updateGame(this->board, userChoice, 'x');           /* <=== NOTE: Perhaps the player can choose at the beginning whether to play x or o */
        } else {
            cout << "I'm sorry, that is not a valid move. You lost a turn\n";
            /* next line just for testing */
            gameIsOver = true;
        }

        /* print current game board / state */
        printTheGame(this->board);

        /* check if winner, or game over */
        if(checkWinner('x')){
            gameIsOver = true;
            cout << " ***** YOU WIN ***** !!!!!\n";
            return;
        }



        /* allow Computer move (if there are moves left ) */
        // theAI.move();

        /* check if winner, or game over */
        if(checkWinner('0')){
            gameIsOver = true;
            cout << " ***** COMPUTER WINS ***** !!!!!\n";
            return;
        }

        /* next line is just a placeholder for testing*/
        //gameIsOver = true;

    } // end game loop

}



void TicTacToe::moves(vector<char> gameState){
    
}


bool TicTacToe::checkWinner(char player){
    /* all possible winning combinations */
    vector<vector<int>> winningBoards {{1,2,3}, {4,5,6}, {7,8,9},
                                        {1,4,7}, {2,5,8}, {3,6,9},
                                        {1,5,9}, {3,5,7}};
    vector<int> placesOpponentOwns;
    vector<int> placesPlayerOwns;
    char opponentToken = 'x';
    if(player == 'x'){
        opponentToken = 'o';
    }

    /* find the squares we own */
    for(size_t i = 0; i < 9; i++){                /* it would be better to use NUM_ROWS, NUM_COLS*/
        if(this->board[i] == opponentToken){
            /* opponent owns this square */
            placesOpponentOwns.push_back(i+1);
        }
        if(this->board[i] == player){
            /* we own this square */
            placesPlayerOwns.push_back(i+1);
        }
    }
    cout << "Paces player owns: ";
    for(auto item : placesPlayerOwns){
        cout << item << ", ";
    }
    cout << endl;

    /* check to see if either of us match a win, and set the score appropriately */

    for(auto win : winningBoards){
        bool computerMatch = true;
        bool PersonMatch = true;
        for(auto square : win){
            if(std::find(placesOpponentOwns.begin(), placesOpponentOwns.end(), square) != placesOpponentOwns.end() ){
                computerMatch = computerMatch && true;
            } else {
                computerMatch = computerMatch && false;
            }
            if(std::find(placesPlayerOwns.begin(), placesPlayerOwns.end(), square) != placesPlayerOwns.end() ){
                PersonMatch = PersonMatch && true;
            } else {
                PersonMatch = PersonMatch && false;
            }
        }
        /* this is for scoring, just left this in */
        /*
        if(computerMatch){
            score += 1;
        } else if (PersonMatch){
            score -= 1;
        }
        */
        if(PersonMatch){
            return true;
        }

    }  // end for winningBoards
    return false;
}  // end checkWinner()

void TicTacToe::makeMove(int row, int col){

}



/* get user input as an int, used for menu selection
  Usage:  int userInput = getUserMenuInput("What would you like to do?");
  -----------------------------------------------------------------------
  Takes a string that will be printed to the user as a prompt.
  Takes user input as an int, and returns the int
*/
int TicTacToe::getUserMenuInput(string prompt){
    int input = 0;
    cout << prompt << endl;
    if(!(cin >> input)){
        cout << '\n' << "I'm sorry I don't understand that, Please enter a number." << endl;
        input = -1;
    }
    /* consume the newline at the end (so it doesn't mess up future user input) */
    string ending;
    getline(cin, ending);

    return input;
}

bool TicTacToe::validMove(int move, vector<char> gameState){
    int thisI = move - 1;
    if (move < 1 || move > 9){
        return false;
    } else if (gameState[thisI] == 'x' || gameState[thisI] == 'o'){
        return false;
    } else {
        return true;
    }
}


void TicTacToe::updateGame(vector<char> &gameState, int move, char player){
    int thisI = move - 1;
    gameState[thisI] = player;
    return;
}


