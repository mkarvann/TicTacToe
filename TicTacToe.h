#ifndef __TICTACTOE__
#define __TICTACTOE__



#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;




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


class TicTacToe {
    public:
        /* Constructor */
        TicTacToe();

        /* method includes the game loop */
        void playGame();

        /* deconstructor */
        ~TicTacToe(){};
    private:
        /* holds the board state 
        The board is represented by a 3x3 grid of characters.
        Each cell in the grid will have one of three possible values: ' ', 'x', 'o'
        The game starts will all blank cells.
        The cells are referred to by a simple numbering scheme as follow:
            1 | 2 | 3
           ---+---+---
            4 | 5 | 6 
           ---+---+---
            7 | 8 | 9
        */
        vector<char> board;

        int MAX_DEPTH = 9;
        int NUM_ROWS = 3;
        int NUM_COLS = 3;

        /* Assumes computer is using this token */
        char PLAYER_TOKEN = 'x';
        char COMPUTER_TOKEN = 'o';


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
        void printTheGame(vector<char> gameState);

        char checkWinner();

        void makeMove(int row, int col);

        void moves(vector<char> gameState);

        //int minimax(bool isMaximizing);
        //findBestMove();
};

#endif