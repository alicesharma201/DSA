#include<bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, char c, vector<vector<char>>& board){
    for(int x = 0; x < board.size(); x++){
        if(board[row][x] == c) return false;
        if(board[x][col] == c) return false;
        if(board[3*(row/3) + x/3][3*(col/3) + x%3] == c) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] == '.'){
                for(char c = '1'; c <= '9'; c++){
                    if(isValid(i, j, c, board)){
                        board[i][j] = c;
                        if(solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false; // There is no possible number for this cell that allows the Sudoku to be solved. So we tell the previous recursive call: "I couldn't solve it. Try a different choice."
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
int main() {
    vector<vector<char>> board {
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}