#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>>& board, string word, int i, int j, int w){
    if(w == word.size()) return true;

    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[w]) return false;

    int temp = board[i][j];
    board[i][j] = '#';

    bool found = (dfs(board, word, i+1, j, w+1) ||
                    dfs(board, word, i, j+1, w+1) ||
                    dfs(board, word, i-1, j, w+1) ||
                    dfs(board, word, i, j-1, w+1));

    board[i][j] = temp;
    return found;
}
bool exist(vector<vector<char>>& board, string word){
    // TC: O(m * n * 4^L) L is size of word
    // SC: O(L) recursive depth
    int row = board.size();
    int col = board[0].size();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << exist(board, "ABCCED") << endl; // true
    cout << boolalpha << exist(board, "SEE") << endl;    // true
    cout << boolalpha << exist(board, "ABCB") << endl;   // false
    return 0;
}