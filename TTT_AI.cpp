#include "TTT_AI.h"
#include <algorithm>

using std::find;


/* Constructor */
TTT_AI::TTT_AI(int MAX_DEPTH){
    this->MAX_DEPTH = MAX_DEPTH;
}


moveT TTT_AI::FindBestMove(vector<char> state, int depth, int & rating){
    /* for (each possible move or until you find a forced win) */
    vector<moveT> potentialMoves;
    GenerateMoveList(state, potentialMoves); 
        /* Make the move */


        /* Evaluate the resulting position, adding one to the depth indicator. */

        /* Keep track of the minimum rating so far, along with the corresponding move. */

        /* Retract the move to restore the original state. */
    
 
    /* Store the move rating into the reference parameter. */

    /* Return the best move. */

}  // end FindBestMove()



int TTT_AI::EvaluatePosition(vector<char> state, int depth){
    int score = 0;
    /* all possible winning combinations */
    vector<vector<int>> winningBoards {{1,2,3}, {4,5,6}, {7,8,9},
                                        {1,4,7}, {2,5,8}, {3,6,9},
                                        {1,5,9}, {3,5,7}};
    vector<int> placesComputerOwns;
    vector<int> placesPlayerOwns;

    /* find the squares we own */
    for(size_t i = 0; i < 9; i++){                /* it would be better to use NUM_ROWS, NUM_COLS*/
        if(state[i] == COMPUTER_TOKEN){
            /* we own this square */
            placesComputerOwns.push_back(i+1);
        }
        if(state[i] == PLAYER_TOKEN){
            /* we own this square */
            placesPlayerOwns.push_back(i+1);
        }
    }

    /* check to see if either of us match a win, and set the score appropriately */
    bool computerMatch = true;
    bool PersonMatch = true;
    for(auto win : winningBoards){
        for(auto square : win){
            if(std::find(placesComputerOwns.begin(), placesComputerOwns.end(), square) != placesComputerOwns.end() ){
                computerMatch && true;
            } else {
                computerMatch && false;
            }
            if(std::find(placesPlayerOwns.begin(), placesPlayerOwns.end(), square) != placesPlayerOwns.end() ){
                PersonMatch && true;
            } else {
                PersonMatch && false;
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


void TTT_AI::GenerateMoveList(vector<char> state, vector<moveT> &moveArray){
    for(size_t i = 1; i <= 9; i++){
        if(state[i-1] == ' '){
            /* this is a potential move, update moveArray, and keep going */
            moveArray.push_back(i);
        } 
    }
    return;
}