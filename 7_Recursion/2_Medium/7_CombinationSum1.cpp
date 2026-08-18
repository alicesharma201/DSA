#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>& nums, int k, vector<int>& val, vector<vector<int>>& res, int i){
    if(i == nums.size()){
        if(k == 0){
            res.push_back(val);
        }
        return;
    }
    if(nums[i] <= k){
        val.push_back(nums[i]);
        helper(nums, k-nums[i], val, res, i);
        val.pop_back();
    }
    helper(nums, k, val, res, i+1);
}
vector<vector<int>> combinationSum(vector<int>& nums, int k){
    // TC: O(2^t * k)
    // SC: O(k * x) where k : average length of combination, x : combinations
    vector<int> val;
    vector<vector<int>> res;
    helper(nums, k, val, res, 0);
    return res;
}
int main(){
    vector<int> nums = {2, 3, 7};
    int k = 7;
    for(auto i : combinationSum(nums, k)){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}