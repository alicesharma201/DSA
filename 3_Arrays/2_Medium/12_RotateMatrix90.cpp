#include<bits/stdc++.h>
void brute(vector<vector<int>>& matrix){
    // TC: O(n^2)
    // SC: O(n^2)
    // The first row becomes the last column
    int n = matrix.size();
    vector<vector<int>> temp = matrix;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = temp;
}
void optimal(vector<vector<int>>& matrix){ // take transpose then reverse rows
    // TC: O(n^2+n^2) = O(n^2)
    // SC: O(1)
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i < n; i++){ // O(n)
        reverse(matrix[i].begin(), matrix[i].end()); // O(n)
    }
}
int main(){
    vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};
    // brute(matrix);
    optimal(matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}