#include<bits/stdc++.h>
int bruteMedian(vector<vector<int>>& mat){
    // TC: O(m*n + m*nlog(m*n))
    // SC: O(m*n)
    int m = mat.size(), n = mat[0].size();
    vector<int> temp;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[(m*n)/2];
}
int countLessEqual(vector<int>& row, int mid){
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}
int optimalMedian(vector<vector<int>>& matrix){
    // TC: O(log(maxValue−minValue)×rows×log(cols))
    // SC: O(1)
    int rows = matrix.size();
    int cols = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[0][cols - 1];
    for (int i = 1; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }
    while (low < high) {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            count += countLessEqual(matrix[i], mid);
        }
        if (count < (rows * cols + 1) / 2)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
int main(){
    vector<vector<int>> mat = {
        {3, 7, 9},
        {1, 6, 8},
        {2, 4, 5}
    };
    cout << bruteMedian(mat) << endl;
    cout << optimalMedian(mat) << endl;
    return 0;
}