#include<bits/stdc++.h>
// this one is fun to visualise
// right -> bottom -> left -> top
// TC: O(mn)
// SC: O(mn)
vector<int> spiralMatrix(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = n-1, top = 0, bottom = m-1;
    vector<int> ans;
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top <= bottom){ // if only one row is present, this condition will not get executed
            for(int i = right; i >= left; i--){
            ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if(left <= right){ // if only one column is present, this condition will not get executed
        for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
}
int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };
    for(int i : spiralMatrix(matrix)) cout << i << " ";
    return 0;
}