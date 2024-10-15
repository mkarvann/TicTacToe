#include "TTT_AI.h"


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
    /* all possible winning combinations */
    vector<int> winningBoards {123, 456, 789,
                                147, 258, 369,
                                159, 357};
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