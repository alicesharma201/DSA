#include<bits/stdc++.h>
using namespace std;
void helper(int i, int j, string val, vector<string>& res, vector<vector<int>>& grid){
    if(i == grid.size()-1 && j == grid.size()-1){ 
        res.push_back(val);
        return;
    }
    grid[i][j]++;
    if(i != grid.size()-1 && grid[i+1][j] == 1)
        helper(i+1, j, val+'D', res, grid);
    if(j != 0 && grid[i][j-1] == 1)
        helper(i, j-1, val+'L', res, grid);
    if(j != grid.size()-1 && grid[i][j+1] == 1)
        helper(i, j+1, val+'R', res, grid);
    if(i != 0 && grid[i-1][j] == 1)
        helper(i-1, j, val+'U', res, grid);
    grid[i][j]--;
}
vector<string> ratMaze(vector<vector<int>>& grid){
    // TC: O(4^(n^2))
    // SC: O(n^2) we don't use an additional isVisited matrix, but we still use space for recursive stack and output storage
    vector<string> res;
    string val;
    if(grid.empty() || grid[0][0] == 0 || grid.back().back() == 0)
        return {{"NULL"}};
    helper(0, 0, val, res, grid);
    return res;
}
int main(){
    vector<vector<int>> grid = {{1, 0, 0, 0}, 
                                {1, 1, 0, 1}, 
                                {1, 1, 0, 0}, 
                                {0, 1, 1, 1}};
    for(string i : ratMaze(grid)){
        cout << i << " ";
    }
    return 0;
}