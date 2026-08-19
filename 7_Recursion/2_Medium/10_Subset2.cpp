#include<bits/stdc++.h>
using namespace std;
void bruteHelper(int i, vector<int>& nums, vector<int>& val, set<vector<int>>& st){
    if(i == nums.size()){
        st.insert(val);
        return;
    }
    val.push_back(nums[i]);
    bruteHelper(i+1, nums, val, st);
    val.pop_back();
    bruteHelper(i+1, nums, val, st);
}
vector<vector<int>> bruteSubset(vector<int>& nums){
    // TC: O(2^n * nlogx) set of size x
    // SC: O(2^n * n)
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    vector<int> val;
    bruteHelper(0, nums, val, st);
    vector<vector<int>> res(st.begin(), st.end());
    return res;
}
void optimalHelper(int i, vector<int>& nums, vector<int>& val, vector<vector<int>>& res){
    res.push_back(val);
    for(int x = i; x < nums.size(); x++){
        if(x > i && nums[x] == nums[x-1]) continue;
        val.push_back(nums[x]);
        optimalHelper(x+1, nums, val, res);
        val.pop_back();
    }
}
vector<vector<int>> optimalSubset(vector<int>& nums){
    // TC: O(2^n * n)
    // SC: O(2^n * n)
    sort(nums.begin(), nums.end());
    vector<int> val;
    vector<vector<int>> res;
    optimalHelper(0, nums, val, res);
    return res;
}
int main(){
    vector<int> nums = {1, 2, 1};
    // vector<vector<int>> result = bruteSubset(nums);
    vector<vector<int>> result = optimalSubset(nums);
    for(auto i : result){
        cout << "[";
        for(int j : i){
            cout << j << ' ';
        }
        cout << "]\n";
    }
    return 0;
}