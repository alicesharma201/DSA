#include<bits/stdc++.h>
// bool linearSearchTarget(vector<vector<int>>& mat, int x){
//     TC: O(rows * cols)
//     simple linear search
// }
// bool linearBinarySearchTarget(vector<vector<int>>& mat, int x){
//     TC: O(rows * log(cols))
//     same as before linear search outside and binary search inside till element is found
// }
bool staircaseSearch(vector<vector<int>>& mat, int x){
    // TC: O(m+n)
    int m = mat.size();
        int row = 0, col = mat[0].size()-1;
        while(row < m && col >= 0){
            if(mat[row][col] == x) return true; 
            else if(mat[row][col] > x) col--;
            else row++;
        }
    return false;
}
int main(){
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 23;
    staircaseSearch(mat, target) ? cout << "True" << endl : cout << "False" << endl;
    return 0;
}