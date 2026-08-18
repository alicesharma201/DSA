#include<bits/stdc++.h>
using namespace std;
vector<int> bitSubsetSum(vector<int>& nums){
    // TC: O(2^n * n)
    // SC: O(2^n)
    int n = nums.size();
    vector<int> sum;
    int total = 1 << n;
    for(int mask = 0; mask < total; mask++){
        vector<int> val;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                val.push_back(nums[i]);
            }
        }
        sum.push_back(accumulate(val.begin(), val.end(), 0));
    }
    sort(sum.begin(), sum.end());
    return sum;
}
void helper(int i, vector<int>& nums, vector<int>& sum, int currSum){
    // TC: O(2^n + 2^nlog2^n)
    // SC: O(2^n)
    if(i == nums.size()){
        sum.push_back(currSum);
        return;
    }
    helper(i+1, nums, sum, currSum+nums[i]);
    helper(i+1, nums, sum, currSum);
}
vector<int> recursionSubsetSum(vector<int>& nums){
    vector<int> sum;
    helper(0, nums, sum, 0);
    sort(sum.begin(), sum.end());
    return sum;
}
int main(){
    vector<int> nums = {5, 2, 1};
    // vector<int> res = bitSubsetSum(nums);
    vector<int> res = recursionSubsetSum(nums);
    for(int i : res){
        cout << i << " ";
    }
    return 0;
}