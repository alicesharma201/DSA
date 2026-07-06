#include<bits/stdc++.h>
bool linearSearchTarget(vector<vector<int>>& mat, int x){
    // TC: O(rows * cols)
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            if(mat[i][j] == x) return true;
        }
    }
    return false;
}
bool linearBinarySearchTarget(vector<vector<int>>& mat, int x){
    // TC: O(rows * log(cols))
    for(int i = 0; i < mat.size(); i++){
        int low = 0, high = mat[i].size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mat[i][mid] == x) return true;
            else if(mat[i][mid] > x) high = mid - 1;
            else low = mid + 1;
        }
    }
    return false;
}
bool binarySearchTarget(vector<vector<int>>& mat, int x){
    // TC: O(log(mn))
    int n = mat.size(); // rows
    int m = mat[0].size(); // cols
    int low = 0, high = n * m - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int row = mid / m, col = mid % m; // divide and remainder by columns
        if(mat[row][col] == x) return true;
        else if(mat[row][col] > x) high = mid - 1;
        else low = mid + 1; 
    }
    return false;
}
int main(){
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int target = 8;
    linearSearchTarget(mat, target) ? cout << "True" << endl : cout << "False" << endl;
    linearBinarySearchTarget(mat, target) ? cout << "True" << endl : cout << "False" << endl;
    binarySearchTarget(mat, target) ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}