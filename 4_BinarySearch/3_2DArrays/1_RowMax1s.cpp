#include<bits/stdc++.h>
int linearMaxOnes(vector<vector<int>>& mat, int n, int m){
    // TC: O(n * m)
    int maxOnes = 0;
    int onesIdx = -1;
    for(int i = 0; i < n; i++){
        int onesCount = 0;
        for(int j = 0; j < m; j++){
            // if(mat[i][j] == 1) onesCount++;
            onesCount += mat[i][j];
        }
        if(maxOnes < onesCount){
            maxOnes = onesCount;
            onesIdx = i;
        }
    }
    return onesIdx;
}
int binaryMaxOnes(vector<vector<int>>& mat, int n, int m){
    // TC: O(n * logm)
    int maxOnes = 0;
    int OnesIdx = -1;
    for(int i = 0; i < n; i++){
        int low = 0, high = m-1;
        // if(mat[i][high] == 0) continue; // I don't think we need this condition because if high is 0, then low will end up at low = m, then m - low = 0
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mat[i][mid] == 1) high = mid - 1;
            else low = mid + 1;
        }
        if(maxOnes < (m - low)){ // we applied concept of opposite polarity where low would end up at the first occarance of 1, then we will subtract that number with row size, resulting in total number of ones
            maxOnes = m - low;
            OnesIdx = i;
        }
    }
    return OnesIdx;
}
int main(){
    int n = 3, m = 3;
    vector<vector<int>> mat = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };

    // int n = 2, m = 2;
    // vector<vector<int>> mat = {
    //     {0, 0},
    //     {0, 0}
    // };

    cout << linearMaxOnes(mat, n, m) << endl;
    cout << binaryMaxOnes(mat, n, m) << endl;

    return 0;
}