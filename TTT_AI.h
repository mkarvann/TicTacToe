#ifndef __TTT_AI__
#define __TTT_AI__

#include<vector>
#include "TicTacToe.h"

using std::vector;





/* This class implements the Computer AI for a game of Tic-Tac-Toe
Assumes:
- the board game state is represented as vector<char> state
- the MAX_DEPTH is defined, and must be <= 9
  (there are only 9 moves in a game of Tic-Tac-Toe)
- 
*/
class TTT_AI {
    private:


    public:
        /* Constructor */
        TTT_AI();

        moveT FindBestMove(vector<char> state, int depth, int & rating);
        int EvaluatePosition(vector<char> state, int depth);
        void GenerateMoveList(vector<char> state, vector<moveT> &moveArray); 

        /* deconstructor */
        ~TTT_AI(){};

};



#endif