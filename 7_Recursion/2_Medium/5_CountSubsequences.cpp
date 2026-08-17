#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>& nums, int k, int i, int sum){
    // TC: O(2^n)
    // SC: O(n)
    if(sum > k) return 0; // optimization only for positive integers
    if(i == nums.size()){ // base case
        if(sum == k){
            return 1;
        } return 0;
    }
    int take = helper(nums, k, i+1, sum+nums[i]);
    int skip = helper(nums, k, i+1, sum);
    return take+skip;
}
int countSubsequences(vector<int>& nums, int k){
    return helper(nums, k, 0, 0);
}
int main(){
    vector<int> nums = {1, 2, 1};
    int k = 2;
    cout << countSubsequences(nums, k); // possible subsequences: {1,1}, {2}
    return 0;
}