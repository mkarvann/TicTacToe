#include "TTT_AI.h"
#include <algorithm>

using std::find;


/* Constructor */
TTT_AI::TTT_AI(){
}


int TTT_AI::FindBestMove(vector<char> state, int depth, int & rating){
    /* for (each possible move or until you find a forced win) */
    vector<int> potentialMoves;
    GenerateMoveList(state, potentialMoves); 
        /* Make the move */


        /* Evaluate the resulting position, adding one to the depth indicator. */

        /* Keep track of the minimum rating so far, along with the corresponding move. */

        /* Retract the move to restore the original state. */
    
 
    /* Store the move rating into the reference parameter. */

    /* Return the best move. */


    /* NOTE: next line just a placeholder */
    return -1;
}  // end FindBestMove()



int TTT_AI::EvaluatePosition(vector<char> state, int depth, char player){
    int score = 0;
    /* all possible winning combinations */
    vector<vector<int>> winningBoards {{1,2,3}, {4,5,6}, {7,8,9},
                                        {1,4,7}, {2,5,8}, {3,6,9},
                                        {1,5,9}, {3,5,7}};
    vector<int> placesOpponentOwns;
    vector<int> placesPlayerOwns;
    char opponentToken;
    if(player == 'x'){
        opponentToken = 'o';
    } else {
        opponentToken = 'x';
    }

    /* find the squares we own */
    for(size_t i = 0; i < 9; i++){                /* it would be better to use NUM_ROWS, NUM_COLS*/
        if(state[i] == opponentToken){
            /* opponent owns this square */
            placesOpponentOwns.push_back(i+1);
        }
        if(state[i] == player){
            /* we own this square */
            placesPlayerOwns.push_back(i+1);
        }
    }

    /* check to see if either of us match a win, and set the score appropriately */
    bool computerMatch = true;
    bool PersonMatch = true;
    for(auto win : winningBoards){
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
        if(computerMatch){
            score += 1;
        } else if (PersonMatch){
            score -= 1;
        }

    }  // end for winningBoards

    return score;
}  // end EvaluatePosition


void TTT_AI::GenerateMoveList(vector<char> state, vector<int> &moveArray){
    for(size_t i = 1; i <= 9; i++){
        if(state[i-1] == ' '){
            /* this is a potential move, update moveArray, and keep going */
            moveArray.push_back(i);
        } 
    }
    return;
}