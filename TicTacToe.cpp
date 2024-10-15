#include<vector>
using std::vector;

class TicTacToe
{
public:
    TicTacToe();
    void playGame();
private:
    vector<char> board;
    void printBoard();
    char checkWinner();
    void makeMove(int row, int col);
    int minimax(bool isMaximizing);
    findBestMove();
};
