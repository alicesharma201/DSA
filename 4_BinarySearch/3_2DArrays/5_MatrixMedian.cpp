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
int countSmallerEquals(vector<vector<int>>& mat, int x){
    int cnt = 0;
    for(int i = 0; i < mat.size(); i++){
        cnt += upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
    }
    return cnt;
}
int optimalMedian(vector<vector<int>>& mat){
    // TC: O(log(maxValue-minValue) * rows * log(col)) 
    // SC: O(1)
    
    int r = mat.size(), c = mat[0].size();
    int low = mat[0][0], high = mat[0][c-1];

    // the median must be bigger than (r*c)/2 elements
    // [no. of elements <= median] > (r*c)/2 
    int required = (r*c)/2;

    for(int i = 0; i < r; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][c-1]);
    }
    while(low <= high){
        int mid = low + (high - low)/2;
        int smallerEquals = countSmallerEquals(mat, mid);
        if(smallerEquals <= required) low = mid + 1;
        else high = mid - 1;
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