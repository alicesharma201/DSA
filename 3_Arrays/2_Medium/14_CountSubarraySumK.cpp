#include<bits/stdc++.h>
int brute(vector<int>& nums, int k){
    // TC: O(n^2)
    // SC: O(1)
    int n = nums.size();
    int subArrayCount = 0;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];
            if(sum == k){
                subArrayCount++;
            }
        }
    }
    return subArrayCount;
}
int optimal(vector<int>& nums, int k){
    // TC: O(n) average, O(n²) worst case due to hash collisions
    // SC: O(n)
    int n = nums.size();
    unordered_map<long long, int> prefixSumCount; // {sum, count}
    long long sum = 0;
    int subArrayCount = 0;

    prefixSumCount[0] = 1; // empty subarray with sum zero has appears once (base case)
    for(int i = 0; i < n; i++){
        sum += nums[i];
        int remain = sum - k;
        if(prefixSumCount.find(remain) != prefixSumCount.end()){
            subArrayCount += prefixSumCount[remain];
        }
        prefixSumCount[sum]++;
    }
    return subArrayCount;
}
// Sliding window assumes monotonic behavior — when you expand the window, sum increases; when you shrink, sum decreases. It fails for counting subarrays with sum = k when zeros are present. Sliding window treats one left boundary per right boundary. When zeros exist, multiple left positions give the same sum, but the algorithm only tracks the smallest left that satisfies sum ≤ k. 
int main(){
    vector<int> nums = {3, 1, 2, 4};
    int k = 6;
    cout << brute(nums, k) << endl;
    cout << optimal(nums, k) << endl;
    return 0;
}