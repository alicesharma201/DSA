#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int>& nums, int k, int i, int sum){
    if(sum > k) return false; // only for positive integers
    if(i == nums.size()){
        if(sum == k){
            return true;
        }
        return false;
    }
    if(helper(nums, k, i+1, sum+nums[i]) == true) return true;
    if(helper(nums, k, i+1, sum) == true) return true;
    return false;
}
bool checkSubsequence(vector<int>& nums, int k){
    // TC: O(2^n)
    // SC: O(n)
    return helper(nums, k, 0, 0);
}
int main(){
    vector<int> nums = {1, 2, 1};
    int k = 2;
    cout << (checkSubsequence(nums, k) ? "True\n" : "False\n"); 
    return 0;
}