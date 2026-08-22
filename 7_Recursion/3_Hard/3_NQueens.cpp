#include<bits/stdc++.h>
using namespace std;
bool isSafe(int r, int c, vector<string>& board){
    int tempR = r;
    int tempC = c;
    while(r >= 0 && c >= 0){ // up-left
        if(board[r][c] == 'Q') return false;
        r--; c--;
    }
    r = tempR;
    c = tempC;
    while(r >= 0 && c >= 0){ // up
        if(board[r][c] == 'Q') return false;
        r--;
    }
    r = tempR;
    c = tempC;
    while(r >= 0 && c < board.size()){ // up-right
        if(board[r][c] == 'Q') return false;
        r--; c++;
    }
    return true;
}
void addQueens(int r, int n, vector<string>& board, vector<vector<string>>& res){
    if(r == n){
        res.push_back(board);
        return;
    }
    for(int c = 0; c < n; c++){
        if(isSafe(r, c, board)){
            board[r][c] = 'Q';
            addQueens(r+1, n, board, res);
            board[r][c] = '.';
        }
    }
}
vector<vector<string>> bruteNQueens(int n){
    // TC: O(N^N * N) cost of storing the solutions + for the search
    // SC: O(s * N^2) s = recursion stack
    vector<vector<string>> res;
    string s(n, '.');
    vector<string> board(n, s);
    addQueens(0, n, board, res);
    return res;
}
void addQueens(int r, int n, vector<string>& board, vector<vector<string>>& res, vector<int>& hashCol, vector<int>& hashLeft, vector<int>& hashRight){
    if(r == n){
        res.push_back(board);
        return;
    }
    for(int c = 0; c < n; c++){
        if(hashCol[c] == 0 && hashLeft[n-1 + r-c] == 0 && hashRight[r+c] == 0){
            hashCol[c] = 1;
            hashLeft[n-1 + r-c] = 1;
            hashRight[r+c] = 1;
            board[r][c] = 'Q';
            addQueens(r+1, n, board, res, hashCol, hashLeft, hashRight);
            board[r][c] = '.';
            hashCol[c] = 0;
            hashLeft[n-1 + r-c] = 0;
            hashRight[r+c] = 0;
        }
    }
}
vector<vector<string>> optimalNQueens(int n){
    // TC: O(N^N) where array check becomes O(1)
    // SC: O(s * N^2) s = recursion stack
    vector<vector<string>> res;
    string s(n, '.');
    vector<string> board(n, s);
    vector<int> hashCol(n, 0);
    vector<int> hashLeft(2*n-1, 0);
    vector<int> hashRight(2*n-1, 0);
    addQueens(0, n, board, res, hashCol, hashLeft, hashRight);
    return res;
}
int main(){
    int n = 4;
    // vector<vector<string>> res = bruteNQueens(n);
    vector<vector<string>> res = optimalNQueens(n);

    for (auto &board : res) {
        for (auto &row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }
    return 0;
}