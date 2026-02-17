#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int row, int col, const vector<string>& board, int n) {

    // check left in same row
    for (int c = col - 1; c >= 0; c--)
        if (board[row][c] == 'Q') return false;

    // check upper-left diagonal
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--)
        if (board[r][c] == 'Q') return false;

    // check lower-left diagonal
    for (int r = row + 1, c = col - 1; r < n && c >= 0; r++, c--)
        if (board[r][c] == 'Q') return false;

    return true;
}


void nQueen(int col , int n , vector<vector<string>> &paths , vector<string> &board){
    if(col == n ){
        paths.push_back(board);
        return ;
    }
    for(int row = 0 ; row<n ; row++){
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            nQueen(col+1,n,paths,board);
            board[row][col] = '.';
        }
    }
}

int main(){
     int n{4};
     vector<vector<string>> paths ;
     vector<string> board(n, string(n, '.'));
     nQueen(0, n, paths, board);
     return 0;
}