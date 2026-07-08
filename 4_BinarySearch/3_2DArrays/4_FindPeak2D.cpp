#include<bits/stdc++.h>
int maxElement(vector<int>& row){
    int maxIdx = -1, maxVal = -1;
    for(int i = 0; i < row.size(); i++){
        if(maxVal < row[i]){
            maxVal = row[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}
vector<int> findPeak(vector<vector<int>>& mat){
    // TC: O(clogr)
    int r = mat.size(), c = mat[0].size();
    int low = 0, high = r-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int mx = maxElement(mat[mid]);
        int up = mid > 0 ? mat[mid-1][mx] : -1;
        int down = mid < r-1 ? mat[mid+1][mx] : -1;
        if(up < mat[mid][mx] && mat[mid][mx] > down) 
            return {mid,mx};
        else if(up > mat[mid][mx])
            high = mid - 1;
        else low = mid + 1;
    }
    return {-1,-1};
}
int main(){
    vector<vector<int>> mat = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };
    vector<int> res = findPeak(mat);
    cout << "{" << res[0] << "," << res[1] << "}";
    return 0;
}