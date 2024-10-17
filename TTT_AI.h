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
    int MAX_DEPTH = 9;

    public:
        /* Constructor */
        TTT_AI(int MAX_DEPTH);

        int FindBestMove(vector<char> state, int depth, int & rating);

        /* Evaluates the position. 
        NOTE:  Needs to be modified.  There is a winning
        game state that should be seperated. Also, this method should interface
        with FindBestMove for the minMax approach to work correctly 
        Takes:
          the 'state' of the game, or game board
          the current depth of the evaluation
          the symbol that represents the player to be evaluated, either an 'x' or an 'o'
        */
        int EvaluatePosition(vector<char> state, int depth, char player);
        
        
        void GenerateMoveList(vector<char> state, vector<int> &moveArray); 

        /* deconstructor */
        ~TTT_AI(){};

};



#endif