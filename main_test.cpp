#include<iostream>
#include<vector>
#include "TicTacToe.h"
#include "TTT_AI.h"


using std::cout;
using std::endl;
using std::vector;



int main(){
    TicTacToe game;
    game.playGame();

    /*
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

    */




}