#include<bits/stdc++.h>
vector<vector<int>> brute(vector<vector<int>>& nums){
    // TC: O(nlogn + 2n)
    // SC: O(n)
    vector<vector<int>> overlapped;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        int first = 0, second = 1;
        int start = nums[i][first], end = nums[i][second];
        if(!overlapped.empty() && nums[i][second] <= overlapped.back()[second]) continue;
        for(int j = i+1; j < n; j++){
            if(end >= nums[j][first]){
                end = max(end, nums[j][second]);
            } else break;
        }
        overlapped.push_back({start, end});
    }
    return overlapped;
}
vector<vector<int>> optimal(vector<vector<int>>& nums){
    // TC: O(nlogn + n)
    // SC: O(n)
    sort(nums.begin(), nums.end());
    vector<vector<int>> overlapped;
    int n = nums.size();
    int first = 0, second = 1;
    for(int i = 0; i < n; i++){
        if(overlapped.empty() || overlapped.back()[second] < nums[i][first]){
            overlapped.push_back(nums[i]);
        }
        else{ // overlapped.back()[second] >= nums[i][first]
            overlapped.back()[second] = max(overlapped.back()[second], nums[i][second]);
        }
    }
    return overlapped;
}
int main(){
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    for(auto &i : brute(nums)){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(auto &i : optimal(nums)){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}