#include<bits/stdc++.h>
using namespace std;
void helper(int i, int k, vector<int>& nums, vector<int>& val, vector<vector<int>>& res){
    if(k == 0){
        res.push_back(val);
        return;
    }
    for(int x = i; x < nums.size(); x++){
        if(x > i && nums[x] == nums[x-1]) continue;
        if(nums[x] > k) break;
        val.push_back(nums[x]);
        helper(x+1, k-nums[x], nums, val, res);
        val.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& nums, int k){
    // TC: O(2^n * k), For each of the 2^n subsequences, storing takes O(k) time where k is the average length of each combination
    // SC: O(k * x), To store all x valid combinations, each of average length k
    vector<vector<int>> res;
    vector<int> val;
    helper(0, k, nums, val, res);
    return res;
}
int main(){
    vector<int> nums = {1, 1, 1, 2, 2};
    int k = 4;
    for(auto i : combinationSum2(nums, k)){
        for(int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}