#include<bits/stdc++.h>
int brute(vector<int>& nums, int k){

    return 0;
}
int self(vector<int>& nums, int k){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int len = 0; 
    for(int i = 0; i < n; i++){
        int sum = 0;
        // int count = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            // count++;
            if(sum == k) len = max(len, j-i+1);
        }
    }
    return len;
}
int main(){
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    // vector<int> nums = {1, 1, 1, 1};
    int k = 15;
    cout << self(nums, k) << endl;
    return 0;
}