#ifndef __TTT_AI__
#define __TTT_AI__

#include<vector>

using std::vector;

/* Assumes computer is using this token */
char PLAYER_TOKEN = 'x';
char COMPUTER_TOKEN = 'o';

/*
 * Type: moveT
 * ----------
 * For any particular game, the moveT type must keep track of the
 * information necessary to describe a move.  For tic-tac-toe,
 * a moveT is simply an integer identifying the number of one of
 * the nine squares, as follows:
 *
 *        1 | 2 | 3
 *       ---+---+--
 *        4 | 5 | 6
 *       ---+---+--
 *        7 | 8 | 9
 */
 typedef int moveT;



/* This class implements the Computer AI for a game of Tic-Tac-Toe
Assumes:
- the board game state is represented as vector<char> state
- the MAX_DEPTH is defined, and must be <= 9
  (there are only 9 moves in a game of Tic-Tac-Toe)
- 
*/
class TTT_AI {
    private:
        int MAX_DEPTH;


    public:
        /* Constructor */
        TTT_AI(int MAX_DEPTH);

        moveT FindBestMove(vector<char> state, int depth, int & rating);
        int EvaluatePosition(vector<char> state, int depth);
        void GenerateMoveList(vector<char> state, vector<moveT> &moveArray); 

        /* deconstructor */
        ~TTT_AI(){};

};



#endif